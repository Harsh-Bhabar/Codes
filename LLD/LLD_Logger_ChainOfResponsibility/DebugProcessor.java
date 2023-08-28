package LLD_Logger_ChainOfResponsibility;

public class DebugProcessor extends LogProcessor{

	DebugProcessor(LogProcessor lp){
		super(lp);
	}

	public void log(int logLevel, String msg){
		if(logLevel == 2){
			System.out.println("DEBUG : " + msg);
		}else{
			super.log(logLevel, msg);
		}
	}

}
