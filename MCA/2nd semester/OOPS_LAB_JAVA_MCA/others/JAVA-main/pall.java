import java.util.Scanner;

public class pall{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string to check for palindrome: ");
        String str = scanner.nextLine();

        if (isPalindrome(str))
            System.out.println(str + " is a palindrome.");
        else
            System.out.println(str + " is not a palindrome.");
        
        scanner.close();
    }

    public static boolean isPalindrome(String str) {
        int i = 0, j = str.length() - 1;
        while (i < j) {
            if (str.charAt(i) != str.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
}
