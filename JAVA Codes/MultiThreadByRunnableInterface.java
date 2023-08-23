class MultiThreadDemo implements Runnable{
	public void run(){
		try {
			System.out.println("Curr thread id is - " + Thread.currentThread().getId());			
		} catch (Exception e) {
			System.out.println("Exzception occurred.");
		}
	}
}

public class MultiThreadByRunnableInterface {
	public static void main(String args[]){
		for(int i=0; i<10; i++){
			Thread thread = new Thread(new MultiThreadDemo());
			thread.start();
		}
	}
}
