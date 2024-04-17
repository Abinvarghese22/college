import java.util.Scanner;

// Custom exception class for authentication
class AuthenticationException extends Exception {
    public AuthenticationException(String message) {
        super(message);
    }
}

// Class to perform user authentication
class UserAuthentication {
    // Method to authenticate user
    public void authenticate(String username, String password) throws AuthenticationException {
        String validUsername = "admin";
        String validPassword = "password123";
        
        if (!username.equals(validUsername) || !password.equals(validPassword)) {
            throw new AuthenticationException("Invalid username or password");
        }
        System.out.println("Authentication successful!");
    }
}

// Main class
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        UserAuthentication auth = new UserAuthentication();

        try {
            // Prompt user for username
            System.out.print("Enter username: ");
            String username = scanner.nextLine();

            // Prompt user for password
            System.out.print("Enter password: ");
            String password = scanner.nextLine();

            // Authenticate user
            auth.authenticate(username, password);
        } catch (AuthenticationException e) {
            System.out.println("Authentication failed: " + e.getMessage());
        } finally {
            // Close scanner
            scanner.close();
        }
    }
}

