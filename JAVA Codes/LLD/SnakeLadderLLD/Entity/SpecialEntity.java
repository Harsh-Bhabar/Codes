package SnakeLadderLLD.Entity;

public abstract class SpecialEntity {
	public int start;
	public int end;

	SpecialEntity(int s, int e){
		this.start = s;
		this.end = e;
	}

	public abstract String entityMsg();
	
	public abstract String getID();

	public void setStart(int s){
		this.start = s;
	}

	public void setEnd(int e){
		this.end = e;
	}

	public int getStart(){
		return this.start;
	}

	public int getEnd(){
		return this.end;
	}

}
