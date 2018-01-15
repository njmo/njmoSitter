package com.example.njmo.njmositter_app;

import android.content.Context;
import android.net.DhcpInfo;
import android.net.wifi.WifiManager;
import android.util.Log;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InterfaceAddress;
import java.net.NetworkInterface;
import java.net.SocketException;
import java.net.UnknownHostException;
import java.nio.charset.StandardCharsets;
import java.util.Enumeration;

/**
 * Created by njmo on 12.01.2018.
 */

public class BroadcastNannyFinder {

    public BroadcastNannyFinder()
    {

    }
    public JSONObject findNanny()
    {
        String address = "0.0.0.0";
        DatagramSocket serverSocket = null;
        InetAddress addr = null;
        try {
            addr =  InetAddress.getByName(address);
        } catch (UnknownHostException e) {
            e.printStackTrace();
            return null;
        }
        try {
            serverSocket = new DatagramSocket(12345,addr);
            serverSocket.setSoTimeout(1000);
        } catch (SocketException e) {
            e.printStackTrace();
            return null;
        }
        byte[] receiveData = new byte[4100];
        DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
        try {
            serverSocket.receive(receivePacket);
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
        JSONObject jb = null;
        try {
             return new JSONObject(new String(receiveData, StandardCharsets.UTF_8));
        } catch (JSONException e) {
            e.printStackTrace();
            return null;
        }


    }
    public static String getBroadcast(){
        String found_bcast_address=null;
        System.setProperty("java.net.preferIPv4Stack", "true");
        try
        {
            Enumeration<NetworkInterface> niEnum = NetworkInterface.getNetworkInterfaces();
            while (niEnum.hasMoreElements())
            {
                NetworkInterface ni = niEnum.nextElement();
                if(!ni.isLoopback()){
                    for (InterfaceAddress interfaceAddress : ni.getInterfaceAddresses())
                    {

                        found_bcast_address = interfaceAddress.getBroadcast().toString();
                        found_bcast_address = found_bcast_address.substring(1);

                    }
                }
            }
        }
        catch (SocketException e)
        {
            e.printStackTrace();
        }

        return found_bcast_address;
    }
}
