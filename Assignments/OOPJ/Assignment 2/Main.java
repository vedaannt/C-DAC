public class Main {

    static Employee[] employees = new Employee[100];
    static int count = 0;

    public static void main(String[] args) {

        int choice;

        do {

            System.out.println("\n========================");
            System.out.println("1. Add");
            System.out.println("2. Display");
            System.out.println("3. Delete");
            System.out.println("4. Sort");
            System.out.println("5. Save");
            System.out.println("6. Load");
            System.out.println("7. Exit");
            System.out.println("========================");

            System.out.print("Enter choice: ");
            choice = ConsoleInput.getInt();

            switch (choice) {

                case 1:
                    add();
                    break;

                case 2:
                    display();
                    break;

                case 3:
                    delete();
                    break;

                case 4:
                    sort();
                    break;

                case 5:
                    save();
                    break;

                case 6:
                    load();
                    break;

                case 7:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice");
            }

        } while (choice != 7);
    }


    // ================= ADD =================

    static void add() {

        System.out.println("\n1. Manager");
        System.out.println("2. Engineer");
        System.out.println("3. Sales Person");
        System.out.println("4. Exit");

        System.out.print("Enter choice: ");
        int choice = ConsoleInput.getInt();

        if (choice == 4) {
            return;
        }

        System.out.print("Enter ID: ");
        int id = ConsoleInput.getInt();

        System.out.print("Enter Name: ");
        String name = ConsoleInput.getString();

        System.out.print("Enter Salary: ");
        double salary = ConsoleInput.getFloat();

        switch (choice) {

            case 1:

                System.out.print("Enter Bonus: ");
                double bonus = ConsoleInput.getFloat();

                employees[count] =
                        new Manager(id, name, salary, bonus);

                break;


            case 2:

                System.out.print("Enter Skill: ");
                String skill = ConsoleInput.getString();

                employees[count] =
                        new Engineer(id, name, salary, skill);

                break;


            case 3:

                System.out.print("Enter Commission: ");
                double commission = ConsoleInput.getFloat();

                employees[count] =
                        new SalesPerson(id, name, salary, commission);

                break;


            default:

                System.out.println("Invalid choice");
                return;
        }

        count++;

        System.out.println("Employee added successfully.");
    }


    // ================= DISPLAY =================

    static void display() {

        if (count == 0) {

            System.out.println("No employees available.");
            return;
        }

        for (int i = 0; i < count; i++) {

            System.out.println("\n------------------------");

            employees[i].display();
        }
    }


    // ================= SORT =================

    static void sort() {

        System.out.println("\na. By Name Ascending");
        System.out.println("b. By Name Descending");
        System.out.println("c. By Designation");
        System.out.println("d. Exit");

        System.out.print("Enter choice: ");
        String choice = ConsoleInput.getString();

        switch (choice.toLowerCase()) {

            case "a":

                for (int i = 0; i < count - 1; i++) {

                    for (int j = i + 1; j < count; j++) {

                        if (employees[i].getName()
                                .compareToIgnoreCase(
                                employees[j].getName()) > 0) {

                            Employee temp = employees[i];

                            employees[i] = employees[j];

                            employees[j] = temp;
                        }
                    }
                }

                System.out.println(
                        "Employees sorted by name in ascending order.");

                break;


            case "b":

                for (int i = 0; i < count - 1; i++) {

                    for (int j = i + 1; j < count; j++) {

                        if (employees[i].getName()
                                .compareToIgnoreCase(
                                employees[j].getName()) < 0) {

                            Employee temp = employees[i];

                            employees[i] = employees[j];

                            employees[j] = temp;
                        }
                    }
                }

                System.out.println(
                        "Employees sorted by name in descending order.");

                break;


            case "c":

                System.out.println(
                        "Sorting by designation is not implemented.");

                break;


            case "d":

                return;


            default:

                System.out.println("Invalid choice.");
        }
    }


    // ================= DELETE =================

    static void delete() {

        // Implement later

        System.out.println("Delete method");
    }


    // ================= SAVE =================

    static void save() {

        // Implement later

        System.out.println("Save method");
    }


    // ================= LOAD =================

    static void load() {

        // Implement later

        System.out.println("Load method");
    }
}