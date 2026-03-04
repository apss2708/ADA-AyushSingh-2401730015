import java.util.Scanner; 

/**
 * LinearSearch Implementation (renamed from Insertion.java constraints context)
 * Time Complexity: Best: O(1) | Average: O(n) | Worst: O(n)
 * Space Complexity: O(1)
 */
public class LinearSearch { 
    
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        int[] arr = new int[5]; 
        
        System.out.println("Enter 5 array elements: "); 
        for (int i = 0; i < arr.length; i++) { 
            arr[i] = sc.nextInt(); 
        } 
        
        System.out.println("\nArray elements:"); 
        for (int i = 0; i < arr.length; i++) { 
            System.out.print(arr[i] + " "); 
        } 
        System.out.println();
        
        System.out.println("\nLinear Search for target: 20"); 
        linearSearch(arr, 20); 
        
        sc.close();
    } 
    
    public static void linearSearch(int[] arr, int target) { 
        boolean isFound = false; 
        
        for (int i = 0; i < arr.length; i++) { 
            if (arr[i] == target) { 
                System.out.println("Element found at index: " + i + " with value: " + arr[i]); 
                isFound = true; 
                break; 
            } 
        } 
        
        if (!isFound) {
            System.out.println("Element not found in list!"); 
        }
    } 
} 
