package Collections;

import java.util.Arrays;

public class ArraysColl {

	public static void main(String[] args) {

		int[] a = {1, 2, 3, 5, 6};

		int ind = Arrays.binarySearch(a, 60);
		System.out.println(ind);


		int[] nums = {1, 4, 5, 7, 2, 3};
		Arrays.sort(nums);

		for(Integer i: nums){
			System.out.print(i + " ");
		}


	}

}
