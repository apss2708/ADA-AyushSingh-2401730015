/**
 * QuickSort Implementation
 * Time Complexity: Best: O(n log n) | Average: O(n log n) | Worst: O(n^2)
 * Space Complexity: O(log n) stack space for recursion
 */
public class QuickSort {
    static int stepCount = 0;

    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int partitionIndex = partition(arr, low, high);
            
            // Recursively sort elements before and after partition
            quickSort(arr, low, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, high);
        }
    }

    public static int partition(int[] arr, int low, int high) {
        // Choosing the rightmost element as pivot
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            stepCount++;
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        stepCount++;
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
        
        quickSort(arr, 0, arr.length - 1);
        
        System.out.println("Sorted Array (Quick Sort):");
        printArray(arr);
        System.out.println("Step Count: " + stepCount);
    }
}
