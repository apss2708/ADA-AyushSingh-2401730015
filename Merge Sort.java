/**
 * MergeSort Implementation
 * Time Complexity: Best: O(n log n) | Average: O(n log n) | Worst: O(n log n)
 * Space Complexity: O(n) temporary arrays
 */
public class MergeSort {
    static int stepCount = 0;

    public static void mergeSort(int[] arr, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            
            // Sort first and second halves
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            
            // Merge the sorted halves
            merge(arr, left, mid, right);
        }
    }

    public static void merge(int[] arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        int[] L = new int[n1];
        int[] R = new int[n2];
        
        for (int i = 0; i < n1; i++) {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[mid + 1 + j];
        }
            
        int i = 0, j = 0, k = left;
        
        while (i < n1 && j < n2) {
            stepCount++;  
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        // Copy remaining elements of L[] if any
        while (i < n1) {
            arr[k++] = L[i++];
        }
        // Copy remaining elements of R[] if any
        while (j < n2) {
            arr[k++] = R[j++];
        }
    }

    public static void printArray(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] arr = {35, 12, 48, 7, 22};
        stepCount = 0;
        
        System.out.println("Original Array:");
        printArray(arr);
        
        mergeSort(arr, 0, arr.length - 1);
        
        System.out.println("Sorted Array (Merge Sort):");
        printArray(arr);
        System.out.println("Step Count: " + stepCount);
    }
}
