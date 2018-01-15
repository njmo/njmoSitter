package com.example.njmo.njmositter_app;

import org.json.JSONException;
import org.json.JSONObject;

import java.nio.charset.StandardCharsets;

/**
 * Created by njmo on 12.01.2018.
 */

public class NannyMessage {
    public NannyMessage()
    {

    }
    public void processMessage(byte[] jsonStringArray)
    {
        String stringMessage = new String(jsonStringArray, StandardCharsets.UTF_8);
        JSONObject jsonMessage = null;

        try {
            jsonMessage = new JSONObject(stringMessage);
        } catch (JSONException e) {
            e.printStackTrace();
            return;
        }
    }

    public JSONObject createCameraRequestMessage()
    {
        JSONObject jb = new JSONObject();
        try {
            jb.put("nannyType",3);
            jb.put("fps",1);
            jb.put("cameraType",0);
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return jb;
    }
}
