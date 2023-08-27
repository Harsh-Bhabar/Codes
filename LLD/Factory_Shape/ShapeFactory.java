package LLD.Factory_Shape;

public class ShapeFactory{
	Shape shape;

	Shape getShape(String shape){
		switch (shape) {
			case "CIRCLE":
				this.shape = new Circle();			
				break;
			case "REC":
				this.shape = new Rectangle();
				break;
			default:
				break;
		}
		return this.shape;
	}
	
}
