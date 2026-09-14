public class Program {

    public static void main(String[] args) {

        System.out.println("Enter the size of array: ");

        int size = ConsoleInput.getInt();

        int arr[] = new int[size];

        for (int temp = 0; temp < arr.length; temp++) {

            System.out.println("Enter the element in array :");
            arr[temp] = ConsoleInput.getInt();
        }

        ArrayOperations objArrayOperations = new ArrayOperations();

        int choice;

        do {

            System.out.println("\n----- MENU -----");
            System.out.println("1. Sort Array");
            System.out.println("2. Sum of Array");
            System.out.println("3. Average");
            System.out.println("4. Copy Array");
            System.out.println("5. Maximum");
            System.out.println("6. Minimum");
            System.out.println("7. Reverse Array");
            System.out.println("8. Duplicate Values");
            System.out.println("9. Common Elements");
            System.out.println("10. Display");
            System.out.println("0. Exit");

            System.out.println("Enter your choice:");
            choice = ConsoleInput.getInt();

            switch (choice) {

            case 1:
                objArrayOperations.arraSort(arr);
                System.out.println("Sorted Array : ");
                objArrayOperations.display(arr);
                break;

            case 2:
                System.out.println("Sum of array : "+ objArrayOperations.arraySum(arr));
                break;

            case 3:
                System.out.println("Average : "+ objArrayOperations.calculateAvgArray(arr));
                break;

            case 4:
                int copy[] = objArrayOperations.copyArray(arr);

                System.out.println("Copy array : ");

                for (int i = 0; i < copy.length; i++) {
                    System.out.print(copy[i] + " ");
                }

                System.out.println();
                break;

            case 5:
                System.out.println("Max Number : " + objArrayOperations.findMax(arr));
                break;

            case 6:
                System.out.println("Min Number : "+ objArrayOperations.findMin(arr));
                break;

            case 7:
                int reverse[] = objArrayOperations.reverseArray(arr);

                System.out.println("Reverse array : ");

                for (int i = 0; i < reverse.length; i++) {
                    System.out.print(reverse[i] + " ");
                }

                System.out.println();
                break;

            case 8:
                System.out.println("Duplicate values : ");
                objArrayOperations.findDuplicate(arr);
                break;

            case 9:
                System.out.println("Enter size of second array:");

                int size2 = ConsoleInput.getInt();

                int arr2[] = new int[size2];

                for (int i = 0; i < arr2.length; i++) {

                    System.out.println("Enter element:");
                    arr2[i] = ConsoleInput.getInt();
                }

                System.out.println("Common elements : ");

                objArrayOperations.findCommon(arr, arr2);
                break;

            case 10:
                System.out.println("Array : ");
                objArrayOperations.display(arr);
                break;

            case 0:
                System.out.println("Exit");
                break;

            default:
                System.out.println("Invalid choice");
            }

        } while (choice != 0);
    }
}