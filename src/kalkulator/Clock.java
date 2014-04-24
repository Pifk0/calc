/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package kalkulator;

import java.util.Timer;

/**
 *
 * @author 2NowakK
 */
public class Clock {
    private Timer timer;
    long startTime;
    long endTime;
    long totalTime;
    public Clock(){
        timer = new Timer();
    }
    public void startClock(){
        startTime = System.currentTimeMillis();
    }
    public void stopClock(){
        endTime   = System.currentTimeMillis();
    }   
    public long getOperationTime(){
        totalTime = endTime - startTime;
        if(totalTime > 2000000)
            throw new OutOfTimeException();
        return totalTime;
    }
}
