package Collections;

import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.TreeSet;

public class HashSetColl {
	public static void main(String[] args) {
		
		// Set<Integer> set = new HashSet<>(); 

		// LinekdHashSet -> maintains order
		// Set<Integer> set = new LinkedHashSet<>();

		// TreeSet -> sort
		Set<Integer> set = new TreeSet<>();

		set.add(1);
		set.add(33);
		set.add(5);
		set.add(43);
		set.add(47);
		set.add(34);
		set.add(433);

		System.out.println(set.contains(33));
		set.remove(33);

		System.out.println(set);
 

	}
}
