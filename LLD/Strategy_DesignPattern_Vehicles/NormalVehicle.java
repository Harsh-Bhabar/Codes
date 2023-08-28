package Strategy_DesignPattern_Vehicles;

import Strategy_DesignPattern_Vehicles.Strategy.NormalDriveStrategy;

public class NormalVehicle extends Vehicle{
	
	NormalVehicle(){
		super(new NormalDriveStrategy());
	}
}
