package Collections;
class Sample{

	public static int someMethod(){
		try{
			return 1;
		}catch(Exception e){
			System.out.println("Exc");
		}
		finally{
			System.out.println("dfinally");
			return 10;
		}
	}

	public static void main(String args[]){
		int ans = someMethod();
		System.out.println(ans);
	}
}
