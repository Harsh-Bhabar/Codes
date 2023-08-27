package LLD.Factory_Shape;

public class Driver {
	public static void main(String[] args){
		ShapeFactory shapeFactory = new ShapeFactory();
		Shape shape = shapeFactory.getShape("CIRCLE");
		shape.draw();
		Shape shape2 = shapeFactory.getShape("REC");
		shape2.draw();
	}
}
