package SpecialDesignPattern;

import SpecialDesignPattern.Strategy.DriveStategy;

public class Vehicle {
	private DriveStategy driveStategy;

	Vehicle(DriveStategy driveStategy){
		this.driveStategy = driveStategy;
	}

	public String drive(){
		return driveStategy.drive();
	}

}
