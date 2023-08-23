package SnakeLadderLLD.Entity;

public class Ladder extends SpecialEntity {
	
	Ladder(int start, int end){
		super(start, end);
	}

	@Override
	public String entityMsg(){
		return "Yaaay. you've climbed a ladder";
	}

	@Override
	public String getID() {
		return "L_" + this.getEnd();
	};

}
