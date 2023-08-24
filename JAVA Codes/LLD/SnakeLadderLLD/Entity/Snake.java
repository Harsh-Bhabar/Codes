package SnakeLadderLLD.Entity;

public class Snake extends SpecialEntity {

	Snake(int start, int end){
		super(start, end);
	}

	@Override
	public String entityMsg(){
		return "OOOPS, you;ve encountred a Snake!";
	}

	@Override
	public String getID(){
		return "S_" + this.getEnd();
	};

}
