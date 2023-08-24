package SnakeLadderLLD.Service;

public class Dice {
	int maxVal ;
	
	Dice(int maxVal){
		this.maxVal = maxVal;
	}

	public int roll(){
		return (int) Math.floor(Math.random()*maxVal + 1 );
	}

}
