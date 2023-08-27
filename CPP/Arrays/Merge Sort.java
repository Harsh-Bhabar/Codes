import java.util.ArrayList;
import java.util.List;

public class MergeSortArrayList {

    public static void merge(List<Integer> arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        List<Integer> leftArray = new ArrayList<>();
        List<Integer> rightArray = new ArrayList<>();

        for (int i = 0; i < n1; i++) {
            leftArray.add(arr.get(left + i));
        }
        for (int j = 0; j < n2; j++) {
            rightArray.add(arr.get(mid + 1 + j));
        }

        int i = 0, j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (leftArray.get(i) <= rightArray.get(j)) {
                arr.set(k, leftArray.get(i));
                i++;
            } else {
                arr.set(k, rightArray.get(j));
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr.set(k, leftArray.get(i));
            i++;
            k++;
        }

        while (j < n2) {
            arr.set(k, rightArray.get(j));
            j++;
            k++;
        }
    }

    public static void mergeSort(List<Integer> arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    public static void main(String[] args) {
        List<Integer> arr = new ArrayList<>();
        arr.add(12);
        arr.add(11);
        arr.add(13);
        arr.add(5);
        arr.add(6);
        arr.add(7);

        System.out.println("Original list:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        mergeSort(arr, 0, arr.size() - 1);

        System.out.println("Sorted list:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
