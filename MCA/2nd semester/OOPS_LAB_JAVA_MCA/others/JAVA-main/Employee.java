import java.util.Scanner;

public class Employee {
    private int eno;
    private String ename;
    private double eSalary;

    public Employee(int eno, String ename, double eSalary) {
        this.eno = eno;
        this.ename = ename;
        this.eSalary = eSalary;
    }

    public int getEno() {
        return eno;
    }

    public String getEname() {
        return ename;
    }

    public double getESalary() {
        return eSalary;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of employees: ");
        int n = scanner.nextInt();

        Employee[] employees = new Employee[n];

        // Input employee information
        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for Employee " + (i + 1) + ":");
            System.out.print("Employee Number: ");
            int eno = scanner.nextInt();
            scanner.nextLine(); // Consume newline character
            System.out.print("Employee Name: ");
            String ename = scanner.nextLine();
            System.out.print("Employee Salary: ");
            double eSalary = scanner.nextDouble();
            employees[i] = new Employee(eno, ename, eSalary);
        }

        System.out.print("\nEnter the employee number to search: ");
        int searchEno = scanner.nextInt();
        boolean found = false;

        // Search for the employee
        for (Employee emp : employees) {
            if (emp.getEno() == searchEno) {
                found = true;
                System.out.println("\nEmployee found:");
                System.out.println("Employee Number: " + emp.getEno());
                System.out.println("Employee Name: " + emp.getEname());
                System.out.println("Employee Salary: " + emp.getESalary());
                break; // No need to search further
            }
        }

        if (!found) {
            System.out.println("\nEmployee with employee number " + searchEno + " not found.");
        }

        scanner.close();
    }
}
