import java.util.Arrays;

class stringSort {
    public static void main(String[] args) {
        // Example array of strings
        String[] strings = {"banana", "apple", "orange", "grape"};

        // Sort the array of strings
        Arrays.sort(strings);

        // Print the sorted array of strings
        System.out.println("Sorted strings:");
        for (String str : strings) {
            System.out.println(str);
        }
    }
}
