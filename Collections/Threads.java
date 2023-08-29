package Collections;

public record Threads() {
	
}

Thread can be referred to as a lightweight process. 
Thread uses fewer resources to create and exist in the process; 
thread shares process resources. 
The main thread of Java is the thread that is started when the program starts. 
The slave thread is created as a result of the main thread. 
This is the last thread to complete execution.

A thread can programmatically be created by:

Implementing the java.lang.Runnable interface.
Extending the java.lang.Thread class.

You can create threads by implementing the runnable interface 
and overriding the run() method. 
Then, you can create a thread object and call the start() method.

Thread Class:

The Thread class provides constructors and methods 
for creating and operating on threads. 
The thread extends the Object and implements the Runnable interface.

// start a newly created thread.
// Thread moves from new state to runnable state
// When it gets a chance, executes the target run() method
public void start()  
Runnable interface:

Any class with instances that are intended to be executed by a thread should implement the Runnable interface.
The Runnable interface has only one method, which is called run().


Example 1: By using Thread Class

import java.io.*;
class GFG extends Thread {
    public void run()
    {
        System.out.print("Welcome to GeeksforGeeks.");
    }
    public static void main(String[] args)
    {
        GFG g = new GFG(); // creating thread
        g.start(); // starting thread
    }
}
Output
Welcome to GeeksforGeeks.
Example 2: By implementing Runnable interface

import java.io.*;
class GFG implements Runnable {
    public static void main(String args[])
    {
        // create an object of Runnable target
        GFG gfg = new GFG();
  
        // pass the runnable reference to Thread
        Thread t = new Thread(gfg, "gfg");
  
        // start the thread
        t.start();
  
        // get the name of the thread
        System.out.println(t.getName());
    }
    @Override public void run()
    {
        System.out.println("Inside run method");
    }
}
Output
gfg
Inside run method