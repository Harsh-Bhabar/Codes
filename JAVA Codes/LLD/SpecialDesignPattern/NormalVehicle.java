package SpecialDesignPattern;

import SpecialDesignPattern.Strategy.NormalDriveStrategy;

public class NormalVehicle extends Vehicle{
	
	NormalVehicle(){
		super(new NormalDriveStrategy());
	}
}
