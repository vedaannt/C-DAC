public class Pattern9 {
    public static void main(String[] args) {

        for (int i = 1; i <= 6; i++) {

            for (int space = 6; space > i; space--) {
                System.out.println(" ");
            }

            for (int star = 1; star <= (2 * i - 1); star++) {
                System.out.println("*");
            }

            System.out.println();
        }

        for (int i = 5; i >= 1; i--) {

            for (int space = 6; space > i; space--) {
                System.out.println(" ");
            }

            for (int star = 1; star <= (2 * i - 1); star++) {
                System.out.println("*");
            }

            System.out.println();
        }
    }
}