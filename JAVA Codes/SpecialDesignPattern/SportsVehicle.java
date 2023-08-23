package SpecialDesignPattern;

import SpecialDesignPattern.Strategy.SpecialDriveStrategy;

public class SportsVehicle extends Vehicle {

	SportsVehicle(){
		super(new SpecialDriveStrategy());
	}

}
