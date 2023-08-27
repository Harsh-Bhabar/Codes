package Collections;

import java.util.LinkedList;
import java.util.Queue;

public class LinkedListQueeColl {

	public static void main(String[] args) {
		Queue<Integer> q = new LinkedList<>();

		// INSETION
		q.offer(12);
		q.offer(13);
		q.offer(14);
		q.offer(15);
	
		// print
		System.out.println(q);

		// FRONT
		System.out.println(q.peek());

		// DELETION
		q.poll();
		System.out.println(q);

	}

	
}
