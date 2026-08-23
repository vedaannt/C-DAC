import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String str = sc.nextLine();

        String cleanString = str.replaceAll("[^a-zA-Z0-9]", "")
                                 .toLowerCase();

        String reverse = "";

        for (int i = cleanString.length() - 1; i >= 0; i--) {
            reverse = reverse + cleanString.charAt(i);
        }

        if (cleanString.equals(reverse)) {
            System.out.println("The string '" + str
                    + "' is a palindrome.");
        } else {
            System.out.println("The string '" + str
                    + "' is not a palindrome.");
        }

        sc.close();
    }
}