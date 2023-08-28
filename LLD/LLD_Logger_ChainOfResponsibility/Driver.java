package LLD_Logger_ChainOfResponsibility;

public class Driver {
	public static void main(String[] args) {
		
		LogProcessor logProcessor = new DebugProcessor(new InfoLogProcessor(new ErrorLogProcessor(null)));

		logProcessor.log(2, "DEBUG");
		logProcessor.log(1, "DEB");
		logProcessor.log(3, "DEBdag");
		logProcessor.log(4, "DEBdag");

	}
}
