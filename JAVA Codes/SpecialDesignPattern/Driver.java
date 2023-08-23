package SpecialDesignPattern;

import SpecialDesignPattern.Strategy.NormalDriveStrategy;
import SpecialDesignPattern.Strategy.SpecialDriveStrategy;

public class Driver {
	public static void main(String args[]){
		Vehicle specialVehicle = new Vehicle(new SpecialDriveStrategy());
		Vehicle normalVehicle = new Vehicle(new NormalDriveStrategy());

		System.out.println(specialVehicle.drive());
		System.out.println(normalVehicle.drive());

	}
}
