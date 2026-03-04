/**
 * Fibonacci Implementation
 * Time Complexity: Iterative: O(n) | Recursive: O(2^n)
 * Space Complexity: Iterative: O(1) | Recursive: O(n) stack space
 */
public class Fibonacci { 
    static int stepCount = 0; 

    public static void fibIterative(int n) { 
        stepCount = 0; 
        int a = 0, b = 1; 
        
        System.out.print("Iterative Fibonacci sequence up to " + n + " terms: ");
        System.out.print(a + " " + b + " "); 
        
        for (int i = 2; i < n; i++) { 
            int c = a + b; 
            System.out.print(c + " "); 
            a = b; 
            b = c; 
            stepCount++; 
        } 
        System.out.println("\nStep Count: " + stepCount); 
    } 

    public static int fibRecursive(int n) { 
        stepCount++; 
        if (n <= 1) {
            return n; 
        }
        return fibRecursive(n - 1) + fibRecursive(n - 2); 
    } 

    public static void main(String[] args) { 
        int n = 6; 
        
        System.out.println("Calculating Fibonacci sequence for n = " + n + "\n");
        fibIterative(n); 
        
        stepCount = 0; 
        // Recursive function returns the N-th term, not the sequence.
        // For sequence generation via recursion, more operations check is needed.
        System.out.println("Recursive Fibonacci (N-th term): " + fibRecursive(n - 1)); // 0-indexed typically
        System.out.println("Step Count: " + stepCount); 
    } 
} 
