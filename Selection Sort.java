/**
 * SelectionSort Implementation
 * Time Complexity: Best: O(n^2) | Average: O(n^2) | Worst: O(n^2)
 * Space Complexity: O(1)
 */
public class SelectionSort {
    static int stepCount = 0;

    public static void selectionSort(int[] arr) {
        stepCount = 0;
        int n = arr.length;
        
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            // Find the minimum element in the unsorted array
            for (int j = i + 1; j < n; j++) {
                stepCount++;   
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            // Swap the found minimum element with the first element
            if (minIndex != i) {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
                stepCount++;   
            }
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
        
        System.out.println("Original Array:");
        printArray(arr);
        
        selectionSort(arr);
        
        System.out.println("Sorted Array (Selection Sort):");
        printArray(arr);
        System.out.println("Step Count: " + stepCount);
    }
}
