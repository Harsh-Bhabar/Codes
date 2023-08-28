package Strategy_DesignPattern_Vehicles;

import Strategy_DesignPattern_Vehicles.Strategy.SpecialDriveStrategy;

public class SportsVehicle extends Vehicle {

	SportsVehicle(){
		super(new SpecialDriveStrategy());
	}

}
