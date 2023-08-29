package Looger_ChainOfResponsibility;

public class InfoLogProcessor extends LogProcessor{
	
	InfoLogProcessor(LogProcessor logProcessor){
		super(logProcessor);
	}

	@Override
	public void log(int logLevel, String msg){
		if(logLevel == 1){
			System.out.println("INFO : " + msg);
		}else{
			super.log(logLevel, msg);
		}
	}
}
