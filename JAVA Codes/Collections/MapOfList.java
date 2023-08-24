package Collections;
import java.util.*;

public class MapOfList {


	public static void main(String[] args) {
		// Create a map to store integers as keys and lists as values
		Map<Integer, List<Integer>> map = new HashMap<>();

		// Add entries to the map
		map.put(1, new ArrayList<>(Arrays.asList(10, 11, 12)));
		map.put(2, new ArrayList<>(Arrays.asList(20, 21)));
		map.put(3, new ArrayList<>(Arrays.asList(30, 31, 32, 33)));

		// Access values in the map
		List<Integer> listForKey2 = map.get(2);
		System.out.println("List for key 2: " + listForKey2);

		// Iterate through the map entries
		for (Map.Entry<Integer, List<Integer>> entry : map.entrySet()) {
			Integer key = entry.getKey();
			List<Integer> values = entry.getValue();
			System.out.println("Key: " + key + ", Values: " + values);
		}
		
		map.put(10, new ArrayList<>(Arrays.asList(10, 20)));
		System.out.println(map);

		map.get(10).add(1000);

		System.out.println(map);
}

}
