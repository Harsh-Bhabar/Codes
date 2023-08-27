package Collections;
class MultiThreadingDemo extends Thread{
	public void run(){
		try{
			System.out.println("Current thread ID - " + Thread.currentThread().getId());
		}
		catch(Exception e){
			System.out.println("Exception occurred.");
		}
	}
}

public class MultiThreadByThreadClass {
	public static void main(String[] args){
		for(int i=0; i<10; i++){
			MultiThreadingDemo obj = new MultiThreadingDemo();
			obj.start();
		}
	}
}
