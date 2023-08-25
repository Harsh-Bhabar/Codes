package Collections;

import java.util.*;

public class ArrayListColl {
	public static void main(String[] args){
		
		List<String> students = new ArrayList<>();

		// internal working
		// if size = n 
		// size = n + n/2 +1 

		// INSERTION
		// O(n)
		students.add("Harsh");
		students.add("LOL");
		students.add(1, "ayush");
		System.out.println(students);

		// GETTING
		System.out.println(students.get(2));

		// DELETION
		// O(n)
		students.remove(2);// can pass index
		students.remove(String.valueOf("Harsh")); // search n delete 
		students.clear(); // clears the whole list

		students.add("mrinal");
		students.add("mrinalS");
		System.out.println(students);

		// SETTING TO A INDEX
		students.set(1, "Pankaj");

		// CONTAINS 
		System.out.println(students.contains("ayush"));

		// TRAVSERSE 
		for(int i=0; i<students.size(); i++){
			System.out.print(students.get(i) + " ");
		}

		for(String s: students){
			System.out.print(s + " ");
		}

		Iterator it = students.iterator();

		while(it.hasNext()){
			System.out.println(it.next());
		}

		ArrayList<Integer> nnums = new ArrayList<>(256);
		for(int i=0; i<256; i++){
			nnums.add(0);
		}
		nnums.set('a', 5);
		nnums.set('a', nnums.get('a')+1);
				System.out.println(nnums);

	}
	
}
