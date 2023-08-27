package Collections;

import java.util.*;

public class CollecitonsClass {
	public static void main(String[] args) {
		ArrayList<Integer> nums = new ArrayList<>();

		nums.add(1);
		nums.add(15);
		nums.add(3);
		nums.add(11);
		nums.add(334);
		nums.add(23532);

		System.out.println(nums);

		Collections.sort(nums);
		System.out.println(nums);

		Collections.sort(nums, Comparator.reverseOrder());
		System.out.println(nums);

		System.out.println(Collections.min(nums));
		System.out.println(Collections.max(nums));
		System.out.println(Collections.frequency(nums, 11));


		List<Student> students = new ArrayList<>();
		students.add(new Student("Harsh", 1));
		students.add(new Student("Aysuh", 2));
		students.add(new Student("Mrinal", 3));
		students.add(new Student("Pankaj", 4));

		Collections.sort(students);
		System.out.println(students);

		Collections.sort(students, new Comparator<Student>() {
			@Override
			public int compare(Student s1, Student s2){
				return s1.name.compareTo(s2.name);
			}
		});

		System.out.println(students);

		students.add(new Student("LOLOL", 13));
		Collections.sort(students, (o1, o2) -> o1.name.compareTo(o2.name));

		System.out.println(students);

		Collections.reverse(nums);
		System.out.println(nums);

	}
}
