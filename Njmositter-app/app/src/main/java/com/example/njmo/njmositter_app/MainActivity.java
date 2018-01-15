package com.example.njmo.njmositter_app;

import android.graphics.Bitmap;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.ToggleButton;


import org.json.JSONException;
import org.json.JSONObject;
import org.opencv.android.OpenCVLoader;
import org.opencv.android.Utils;
import org.opencv.core.Core;
import org.opencv.core.CvType;
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
import java.math.BigInteger;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.charset.StandardCharsets;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    private static final int PACKET_SIZE = 4096;

    private static TextView textView;
    private Button cameraButton;
    private Button notifyButton;
    private Spinner musicSpinner;
    private SeekBar musicSeekbar;
    private SeekBar motorSeekbar;
    private ToggleButton musicToggleButton;
    private ToggleButton motorToggleButton;
    private String message;
    private NannyConnector nannyConnector;

    private BroadcastNannyFinder finder;

    static {
        if(!OpenCVLoader.initDebug()){
            Log.d(TAG, "OpenCV not loaded");
        } else {
            Log.d(TAG, "OpenCV loaded");
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = (TextView) findViewById(R.id.sample_text);
        cameraButton = (Button) findViewById(R.id.button11);
        notifyButton = (Button) findViewById(R.id.button10);
        musicSpinner = (Spinner) findViewById(R.id.spinner4);
        musicSeekbar = (SeekBar) findViewById(R.id.seekBar4);
        motorSeekbar = (SeekBar) findViewById(R.id.seekBar5);
        musicToggleButton = (ToggleButton) findViewById(R.id.toggleButton3);
        motorToggleButton = (ToggleButton) findViewById(R.id.toggleButton4);

        nannyConnector = new NannyConnector(this,textView);

        new Thread(nannyConnector).start();

        cameraButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                nannyConnector.sendCameraRequest();
            }
        });

        String[] arraySpinner = new String[]
                {
                        "ala",
                        "ma",
                        "kota"
                };
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_spinner_item, arraySpinner);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        musicSpinner.setAdapter(adapter);

        helloworld();
    }
    public void helloworld() {
        // make a mat and draw something
        Mat m = Mat.zeros(800,600, CvType.CV_8UC1);
        //Core.putText(m, "hi there ;)", new Point(30,80), Core.FONT_HERSHEY_SCRIPT_SIMPLEX, 2.2, new Scalar(200,200,0),2);

        // convert to bitmap:
        Bitmap bm = Bitmap.createBitmap(m.cols(), m.rows(),Bitmap.Config.ARGB_4444);
        Utils.matToBitmap(m, bm);

        // find the imageview and draw it!
        ImageView iv = (ImageView) findViewById(R.id.imageView2);
        iv.setImageBitmap(bm);
    }
    public void writeToImageView(final Mat m)
    {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                Bitmap bm = Bitmap.createBitmap(m.cols(), m.rows(),Bitmap.Config.ARGB_8888);
                Utils.matToBitmap(m, bm);
                ImageView iv = (ImageView) findViewById(R.id.imageView2);
                iv.setImageBitmap(bm);
            }});
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
}
