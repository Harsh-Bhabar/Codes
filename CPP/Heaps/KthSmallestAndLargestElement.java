package CPP.Heaps;

import java.util.*;
import java.util.Scanner;

class KthSmallestAndLargestElement{

	static class myComp implements Comparator<Integer>{
		public int compare(Integer a, Integer b){
			return b - a;
		}
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the size");
		int arrSize = 0;
		if(sc.hasNextInt()){
			arrSize = sc.nextInt();
		}

		System.out.println("Enter array elements : ");
		List<Integer> nums = new ArrayList<>();
		for(int i=0; i<arrSize; i++){
			if(sc.hasNextInt()){
				int num = sc.nextInt();
				nums.add(num);
			}
		}

		System.out.println("Enter K : ");
		int k = 0;
		if(sc.hasNextInt()){
			k = sc.nextInt();
		}

		PriorityQueue<Integer> pq = new PriorityQueue<>(); // MIN HEAP 

		for(int i=0; i<arrSize; i++){
			pq.add(nums.get(i));
			if(pq.size() > k){
				pq.remove();
			}
		}
		System.out.println("Kth Largest Element  - " + pq.peek());

		PriorityQueue<Integer> maxHeap = new PriorityQueue<>(k, new myComp());

		for(int i=0; i<arrSize; i++){
			maxHeap.add(nums.get(i));
			if(maxHeap.size() > k){
				maxHeap.remove();
			}
		}

		System.out.println("Kth Smallest Element : " + maxHeap.peek());
		sc.close();
	}
}