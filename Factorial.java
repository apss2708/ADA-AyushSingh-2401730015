/**
 * Factorial Implementation
 * Time Complexity (Iterative & Recursive): O(n)
 * Space Complexity: Iterative: O(1) | Recursive: O(n) stack space
 */
public class Factorial {
    static int stepCount = 0;

    public static void factIterative(int n) {
        stepCount = 0;
        long factorial = 1; // Used long to prevent rapid overflow with factorials
        
        for (int i = 1; i <= n; i++) {
            factorial *= i;
            stepCount++;   
        }
        
        System.out.println("Iterative Factorial of " + n + ": " + factorial);
        System.out.println("Step Count: " + stepCount);
    }

    public static long factRecursive(int n) {
        stepCount++;   
        if (n <= 1) {
            return 1;
        }
        return n * factRecursive(n - 1);
    }

    public static void main(String[] args) {
        int n = 5;
        System.out.println("Calculating factorial for n = " + n + "\n");
        
        factIterative(n);
        
        stepCount = 0;
        long result = factRecursive(n);
        System.out.println("Recursive Factorial of " + n + ": " + result);
        System.out.println("Step Count: " + stepCount);
    }
}
