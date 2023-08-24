package Collections;
import Collections.Student;
import java.util.*;

public class HashSetOfPojo {
	public static void main(String[] args) {
		
		Set<Student> students = new HashSet<>();

		students.add(new Student("Harsh", 1));
		students.add(new Student("LOL", 3));
		students.add(new Student("Ayush", 3));
		students.add(new Student("Sonu", 2));

		System.out.println(students.toString());

	}
}
