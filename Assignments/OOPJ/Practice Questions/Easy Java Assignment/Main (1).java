public class Main {

    public static void main(String[] args) {

        int choice;

        do {
            System.out.println("\n==========================");
            System.out.println("1. Student");
            System.out.println("2. Triangle");
            System.out.println("3. Rectangle");
            System.out.println("4. Complex Number");
            System.out.println("5. Employee Information");
            System.out.println("6. Employee Salary");
            System.out.println("7. Exit");
            System.out.println("==========================");

            System.out.print("Enter choice: ");
            choice = ConsoleInput.getInt();

            switch (choice) {

                case 1:
                    Implementation.student();
                    break;

                case 2:
                    Implementation.triangle();
                    break;

                case 3:
                    Implementation.rectangle();
                    break;

                case 4:
                    Implementation.complex();
                    break;

                case 5:
                    Implementation.employeeInfo();
                    break;

                case 6:
                    Implementation.employeeSalary();
                    break;

                case 7:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 7);
    }
}