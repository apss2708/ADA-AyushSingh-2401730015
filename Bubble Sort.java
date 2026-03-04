/**
 * BubbleSort Implementation
 * Time Complexity: Best: O(n) | Average: O(n^2) | Worst: O(n^2)
 * Space Complexity: O(1)
 */
public class BubbleSort { 
    public static void main(String[] args) { 
        int[] arr = {9, 5, 1, 4, 3}; 
        
        System.out.println("Original array:");
        printArray(arr);
        
        bubbleSort(arr); 
        
        System.out.println("Sorted array:");
        printArray(arr);
    } 

    public static void bubbleSort(int[] arr) { 
        int n = arr.length; 
        boolean swapped; 
        
        for (int i = 0; i < n - 1; i++) { 
            swapped = false; 
            for (int j = 0; j < n - i - 1; j++) { 
                if (arr[j] > arr[j + 1]) { 
                    // Swap elements
                    int temp = arr[j]; 
                    arr[j] = arr[j + 1]; 
                    arr[j + 1] = temp; 
                    swapped = true; 
                } 
            } 
            // If no elements were swapped in the inner loop, array is sorted
            if (!swapped) break; 
        } 
    } 

    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}
