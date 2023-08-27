package Collections;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class PriorityQueueColl {
	public static void main(String[] args) {
		
		// Queue<Integer> pq = new PriorityQueue<>(); // minHeap
		Queue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder()); // maxHeap
		
		//INSETION
		pq.offer(1);
		pq.offer(4);
		pq.offer(3);
		pq.offer(2);

		// TOP
		System.out.println(pq.peek());
		System.out.println(pq);

		// POP
		System.out.println(pq.poll());
		System.out.println(pq);

	}
}
