import java.util.Arrays;

class ArraySearch {
    public static void main(String[] args) {
        // Sample array
        int[] array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int target = 6; // Element to search for

        // Call the search method and store the result
        int index = search(array, target);

        // Check if the element was found or not
        if (index != -1) {
            System.out.println("Element " + target + " found at index: " + index);
        } else {
            System.out.println("Element " + target + " not found in the array.");
        }
    }

    // Method to search for an element in the array
    public static int search(int[] array, int target) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == target) {
                return i; // Return the index where the element is found
            }
        }
        return -1; // Return -1 if the element is not found
    }
}
