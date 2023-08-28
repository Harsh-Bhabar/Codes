package LLD_Logger_ChainOfResponsibility;

public class ErrorLogProcessor extends LogProcessor{
	
	ErrorLogProcessor(LogProcessor lp){
		super(lp);
	}

	public void log(int logLevel, String msg){
		if(logLevel == 3){
			System.out.println("ERROR : " + msg);
		}else{
			super.log(logLevel, msg);
		}
	}

}
