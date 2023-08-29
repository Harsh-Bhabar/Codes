package Looger_ChainOfResponsibility;

public abstract class LogProcessor {
	public static int INFO = 1;
	public static int ERROR = 2;
	public static int LOG = 3;

	LogProcessor logProcessor;

	LogProcessor(LogProcessor lp){
		this.logProcessor = lp;
	}

	public void log(int logLevel, String msg){
		if(logProcessor != null){
			logProcessor.log(logLevel, msg);
		}else{
			System.out.println("DEFAULT : " + msg);
		}
	}

}
