/**
 * InsertionSort Implementation
 * Time Complexity: Best: O(n) | Average: O(n^2) | Worst: O(n^2)
 * Space Complexity: O(1)
 */
public class InsertionSort {
    static int stepCount = 0;

    public static void insertionSort(int[] arr) {
        stepCount = 0;
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            
            // Move elements of arr[0..i-1] that are greater than key
            // to one position ahead of their current position
            while (j >= 0 && arr[j] > key) {
                stepCount++;              
                arr[j + 1] = arr[j];      
                j--;
            }
            arr[j + 1] = key;             
            stepCount++;
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
        
        insertionSort(arr);
        
        System.out.println("Sorted Array (Insertion Sort):");
        printArray(arr);
        System.out.println("Step Count: " + stepCount);
    }
}
