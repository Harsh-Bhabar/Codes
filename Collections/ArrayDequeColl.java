package Collections;

import java.util.ArrayDeque;
import java.util.Queue;

public class ArrayDequeColl {
	public static void main(String[] args) {

		ArrayDeque<Integer> dq = new ArrayDeque<>();

		// INSERTION
		dq.offer(1);
		System.out.println(dq);
		dq.offerFirst(10);
		System.out.println(dq);
		dq.offerLast(100);
		System.out.println(dq);

		// DELETION
		System.out.println(dq.poll());
		System.out.println(dq);
		System.out.println(dq.pollLast());
		System.out.println(dq);
		
		System.out.println(dq.peek());
		System.out.println(dq.peekFirst());
		System.out.println(dq.peekLast());



	}
}
