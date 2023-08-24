package Collections;

import java.util.Stack;

public class StackColl {
	public static void main(String[] args){

		Stack<String> animals = new Stack<>();

		// INSERTION
		animals.push("Lion");
		animals.push("Horse");
		animals.push("Lomdi");

		// print
		System.out.println(animals);

		// TOP
		System.out.println(animals.peek());

		// DELETION
		animals.pop();
		System.out.println(animals);

		// for(animals.isEmpty() == false){
		// 	System.out.println(s.peek());
		// 	animals.pop();
		// }

	}
}
