package Strategy_DesignPattern_Vehicles.Strategy;

public class NormalDriveStrategy implements DriveStategy{
	
	@Override
	public String drive(){
		return "Normal Drive Strategy";
	}
}
