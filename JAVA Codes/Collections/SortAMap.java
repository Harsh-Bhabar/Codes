package Collections;
import java.util.*;
import java.util.Map.Entry;

public class SortAMap {
	public static void main(String[] args) {
		
		Map<String, Integer> map = new TreeMap<>();
		map.put("harsh", 0);
		map.put("yaush", 1);
		map.put("yash", 2);
		map.put("aysuh",3 );
		map.put("jash", 4);
		

		// using lambda operation
		List<Entry<String, Integer>> entries = new ArrayList<>(map.entrySet());
		Collections.sort(entries, (o1, o2) -> o2.getKey().compareTo(o1.getKey())); // descending
		System.out.println(entries);

		map.entrySet().stream().sorted(Map.Entry.comparingByKey()).forEach(System.out::println);

		// map.entrySet().stream().sorted(Map.Entry.comparingByValue()).forEach(System.out::println);
		
	}
}
