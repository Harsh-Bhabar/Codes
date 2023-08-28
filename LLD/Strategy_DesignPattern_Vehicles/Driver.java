package Strategy_DesignPattern_Vehicles;

import Strategy_DesignPattern_Vehicles.Strategy.NormalDriveStrategy;
import Strategy_DesignPattern_Vehicles.Strategy.SpecialDriveStrategy;

public class Driver {
	public static void main(String args[]){
		Vehicle specialVehicle = new Vehicle(new SpecialDriveStrategy());
		Vehicle normalVehicle = new Vehicle(new NormalDriveStrategy());

		System.out.println(specialVehicle.drive());
		System.out.println(normalVehicle.drive());

	}
}
