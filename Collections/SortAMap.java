package Collections;
import java.util.*;
import java.util.Map.Entry;
import java.util.stream.Collector;
import java.util.stream.Collectors;
import static java.util.Collections.reverseOrder;

public class SortAMap {
	public static void main(String[] args) {
		
		// Map<String, Integer> map = new TreeMap<>();
		// map.put("harsh", 0);
		// map.put("yaush", 1);
		// map.put("yash", 2);
		// map.put("aysuh",3 );
		// map.put("jash", 4);
		

		// // using lambda operation
		// List<Entry<String, Integer>> entries = new ArrayList<>(map.entrySet());
		// Collections.sort(entries, (o1, o2) -> o2.getKey().compareTo(o1.getKey())); // descending
		// System.out.println(entries);

		// map.entrySet().stream().sorted(Map.Entry.comparingByKey()).forEach(System.out::println);

		// map.entrySet().stream().sorted(Map.Entry.comparingByValue()).forEach(System.out::println);
		
		Map<String, Integer> map = new HashMap<>();

		map.put("Harsh", 1);
		map.put("Ayush", 2);
		map.put("Mrinal", 3);
		map.put("Sonu", 4);
		map.put("Jash", 5);

		for(Map.Entry<String, Integer> e : map.entrySet()){
			System.out.println(e.getKey() + " " + e.getValue());
		}

		List<Map.Entry<String, Integer>> ls = map.entrySet()
												.stream()
												.sorted(reverseOrder(Map.Entry.comparingByValue()))
												.collect(Collectors.toList());
		System.out.println(ls);

		// map.entrySet().stream().sorted(Map.Entry.comparingByKey()).forEach(System.out::println);

		// System.out.println(map);
	}
}
