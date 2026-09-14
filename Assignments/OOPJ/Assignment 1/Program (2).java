
public class Program {

	public static void main(String[] args) {
		
		Date objDate = new Date();
//
//        System.out.println("Enter Day:");
//        int dd = ConsoleInput.getInt();
//
//        System.out.println("Enter Month:");
//        int mm = ConsoleInput.getInt();
//
//        System.out.println("Enter Year:");
//        int yyyy = ConsoleInput.getInt();
//
//        objDate.setDay(dd, mm, yyyy);
//        
//        
//        
//        
//        System.out.println("Enter number of days to add:");
//        int days = ConsoleInput.getInt();
//        objDate.addDays(days);
//        
//        
//        
//        System.out.println("Enter number of months to add:");
//        int months = ConsoleInput.getInt();
//        objDate.addMonths(months);
//        
//        
//        System.out.println("Enter number of years to add:");
//        int years = ConsoleInput.getInt();
//        objDate.addYears(years);
//        
////        System.out.println("Enter number of days to add:");
////        int days = ConsoleInput.getInt();
////
////        objDate.addDays(days);
//
//        objDate.display();
//        
        
        
        int choice;

        do {

            System.out.println();
            System.out.println("=============================");
            System.out.println("         Date Menu");
            System.out.println("=============================");
            System.out.println("1. Set Date");
            System.out.println("2. Add Days");
            System.out.println("3. Add Months");
            System.out.println("4. Add Years");
            System.out.println("5. Display");
            System.out.println("6. Compare Dates (not implement)");
            System.out.println("7. Exit");
            System.out.println("=============================");

            System.out.println("Enter Choice:");
            choice = ConsoleInput.getInt();

            switch (choice) {

            case 1:

                System.out.println("Enter Day:");
                int dd = ConsoleInput.getInt();

                System.out.println("Enter Month:");
                int mm = ConsoleInput.getInt();

                System.out.println("Enter Year:");
                int yyyy = ConsoleInput.getInt();

                objDate.setDay(dd, mm, yyyy);

                break;

            case 2:

                System.out.println("Enter number of days to add:");
                int days = ConsoleInput.getInt();

                objDate.addDays(days);

                break;

            case 3:

                System.out.println("Enter number of months to add:");
                int months = ConsoleInput.getInt();

                objDate.addMonths(months);

                break;

            case 4:

                System.out.println("Enter number of years to add:");
                int years = ConsoleInput.getInt();

                objDate.addYears(years);

                break;

            case 5:

                objDate.display();

                break;

            case 6:

                System.out.println("Compare Dates is not implemented");

                break;

            case 7:

                System.out.println("Exiting...");

                break;

            default:

                System.out.println("Invalid Choice");
            }

        } while (choice != 7);
        
	}
}   
        
        