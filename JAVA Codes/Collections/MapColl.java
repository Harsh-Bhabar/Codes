package Collections;

import java.util.*;

import javax.swing.RowFilter.Entry;

public class MapColl {

	public static void main(String[] args) {

	HashMap<String, String> map = new HashMap<>();

	map.put("one", "two");
	map.put("three", "two");
	map.put("two", "two");
	map.put("one", "three");

	System.out.println(map.containsKey("one"));

	map.putIfAbsent("one", "LOLO");
	
	System.out.println(map);

	for(Map.Entry<String, String> e: map.entrySet()){
		System.out.println(e.getKey() + " " + e.getValue());
	}

	for(String key : map.keySet()){
		System.out.println(key);
	}

	map.remove("one");

	System.out.println(map.containsValue("two"));
	System.out.println(map.isEmpty());
	map.clear();


	}
}
