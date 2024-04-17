import java.util.LinkedList;
import java.util.Scanner;

public class RemoveAllElementsFromLinkedList {
    public static void main(String[] args) {
        // Create a linked list
        LinkedList<String> linkedList = new LinkedList<>();

        // Scanner object to get user input
        Scanner scanner = new Scanner(System.in);

        // Get user input for elements until the user enters "done"
        System.out.println("Enter elements into the linked list (type 'done' to finish):");
        while (true) {
            String input = scanner.nextLine();
            if (input.equalsIgnoreCase("done")) {
                break;
            }
            linkedList.add(input);
        }

        // Display the linked list before removal
        System.out.println("Linked List before removal: " + linkedList);

        // Remove all elements from the linked list
        linkedList.clear();

        // Display the linked list after removal
        System.out.println("Linked List after removal: " + linkedList);

        // Close the scanner
        scanner.close();
    }
}

