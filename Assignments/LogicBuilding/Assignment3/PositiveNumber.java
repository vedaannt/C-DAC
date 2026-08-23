import java.util.Scanner;

public class PositiveNumber {

    static void askForPositiveNumber(Scanner sc) {

        int number;

        do {
            System.out.println("Enter a positive number: ");
            number = sc.nextInt();

        } while (number <= 0);

        System.out.println("You have entered a positive number: " + number);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        askForPositiveNumber(sc);

        sc.close();
    }
}