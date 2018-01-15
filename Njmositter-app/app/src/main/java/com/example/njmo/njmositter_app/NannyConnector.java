package com.example.njmo.njmositter_app;

import android.graphics.Bitmap;
import android.util.Log;
import android.util.Pair;
import android.widget.ImageView;
import android.widget.TextView;

import org.json.JSONException;
import org.json.JSONObject;
import org.opencv.android.Utils;
import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.MatOfByte;
import org.opencv.core.Point;
import org.opencv.core.Scalar;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

/**
 * Created by njmo on 15.01.2018.
 */

public class NannyConnector implements Runnable{
    private BroadcastNannyFinder finder;
    private NannyMessage nannyMessage;
    private int attempts;
    MainActivity activity;
    TextView textView;
    boolean isRunning;

    private Socket socket ;
    private DataInputStream in;

    NannyConnector(MainActivity mainActivity,TextView tw)
    {
        socket = null;
        finder = new BroadcastNannyFinder();
        attempts = 0;
        activity = mainActivity;
        textView = tw;
        nannyMessage = new NannyMessage();
    }

    private void writeToTextView(final String text)
    {
        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                textView.setText(text);
            }
        });
    }

    public JSONObject listenForNannyBroadcastMessage()
    {
        JSONObject nannyAddress = null;
        do
        {
            nannyAddress = finder.findNanny();
            if(nannyAddress == null)
            {
                try {
                    writeToTextView("No information from nanny waiting 2 seconds to retry, att(" + attempts + ")");
                    attempts++;
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }while(nannyAddress == null);
        writeToTextView("Found nanny broadcast message");

        return nannyAddress;
    }

    public void sendCameraRequest()
    {
        if ( socket == null )
            return;

        JSONObject cameraRequest = nannyMessage.createCameraRequestMessage();
        try {
            socket.getOutputStream().write(cameraRequest.toString().getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public Pair<Integer,byte[]> readBytesFromNanny()
    {
        byte[] data = new byte[4];
        try {
            socket.getInputStream().read(data,0,4);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }

        ByteBuffer b = ByteBuffer.wrap(data);
        b.order(ByteOrder.LITTLE_ENDIAN);

        int length = b.getInt();
        byte[] frame = new byte[length];

        try {
            in.readFully(frame);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
        return new Pair(length,frame);
    }

    @Override
    public void run() {
        JSONObject nannyAddress = listenForNannyBroadcastMessage();
        writeToTextView("Trying to connect to nanny");

        try {
            socket = new Socket(nannyAddress.getString("ip"),nannyAddress.getInt("port"));
            in = new DataInputStream(socket.getInputStream());
        } catch (IOException e) {
            e.printStackTrace();
        } catch (JSONException e) {
            e.printStackTrace();
        }

        isRunning = true;
        while(isRunning)
        {
            Pair<Integer,byte[]> nannyData = readBytesFromNanny();

            if( nannyData == null )
                continue;

            if(nannyData.first.intValue() < 1000)
            {
                nannyMessage.processMessage(nannyData.second);
                continue;
            }
            else
            {
                Mat m;
                m = Imgcodecs.imdecode(new MatOfByte(nannyData.second), Imgcodecs.CV_LOAD_IMAGE_COLOR);
                if(m.size().width == 0)
                {
                    continue;
                }
                activity.writeToImageView(m);
            }
        }
    }
}
