package com.example.njmo.njmositter_app;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.nio.charset.StandardCharsets;

/**
 * Created by njmo on 12.01.2018.
 */

class NotificationException extends IOException
{

}

public class NannyMessage {
    private boolean wasCameraRequestSend;
    private boolean wasNotifyRequestSend;
    private boolean wasMusicRequestSend;
    private boolean wasMotorRequestSend;
    public NannyMessage()
    {
        wasCameraRequestSend = false;
        wasNotifyRequestSend = false;
        wasMusicRequestSend = false;
        wasMotorRequestSend = false;
    }
    public void processMessage(byte[] jsonStringArray) throws IOException
    {
        String stringMessage = new String(jsonStringArray, StandardCharsets.UTF_8);
        JSONObject jsonMessage = null;

        try {
            jsonMessage = new JSONObject(stringMessage);

            if ( (jsonMessage.getInt("notifyType") == 2) && (jsonMessage.getInt("status") == 1 ))
            {
                wasNotifyRequestSend = false;
                throw new NotificationException();
            }
        }
        catch (JSONException e) {
            e.printStackTrace();
            return;
        }
    }
    public JSONObject createMotorRequest()
    {
        //"nannyType" : 6, "motorSpeed": 200, "type" : 0}
        JSONObject jb = new JSONObject();
        if(!wasMotorRequestSend)
        {
            try {
                jb.put("nannyType",6);
                jb.put("motorSpeed",200);
                jb.put("type",0);
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        else
        {
            try {
                jb.put("nannyType",6);
                jb.put("type",0);
                jb.put("motorSpeed",0);
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        wasMotorRequestSend = !wasMotorRequestSend;
        return jb;
    }
    public JSONObject createMusicRequest()
    {
        JSONObject jb = new JSONObject();
        if(!wasMusicRequestSend)
        {
            try {
                jb.put("nannyType",5);
                jb.put("type",0);
                jb.put("songId",0);
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        else
        {
            try {
                jb.put("nannyType",5);
                jb.put("type",1);
                jb.put("songId",0);
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        wasMusicRequestSend = !wasMusicRequestSend;
        return jb;
    }
    /*
"nannyType" : 6, "motorSpeed": 200, "type" : 0}
{ nannyType: 5, type : 0, songId : 0 }
{ nannyType: 5, type : 1, songId : 0 }
*/
    public JSONObject createNotificationRequestMessage()
    {
        JSONObject jb = new JSONObject();
        if(!wasNotifyRequestSend)
        {
            try {
                jb.put("nannyType",2);
                jb.put("notifyType",0);
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        else
        {
            try {
                jb.put("nannyType",2);
                jb.put("notifyType",1);
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        wasNotifyRequestSend = !wasNotifyRequestSend;
        return jb;
    }

    public JSONObject createCameraRequestMessage()
    {
        JSONObject jb = new JSONObject();
        if(!wasCameraRequestSend)
        {
            try {
                jb.put("nannyType",3);
                jb.put("fps",1);
                jb.put("cameraType",0);
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        else
        {
            try {
                jb.put("nannyType",3);
                jb.put("fps",1);
                jb.put("cameraType",1);
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        wasCameraRequestSend = !wasCameraRequestSend;
        return jb;
    }
}
