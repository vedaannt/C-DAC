import java.util.Scanner;

public class PositiveNegative {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] numbers = new int[6];

        System.out.println("Enter 6 integers:");

        for (int i = 0; i < 6; i++) {
            numbers[i] = sc.nextInt();
        }

        int positive = 0;
        int negative = 0;

        for (int number : numbers) {

            if (number > 0) {
                positive++;
            } else if (number < 0) {
                negative++;
            }
        }

        System.out.println("Positive numbers: " + positive);
        System.out.println("Negative numbers: " + negative);

        sc.close();
    }
}