public class Pattern3 {
    public static void main(String[] args) {

        for (int i = 1; i <= 5; i++) {

            for (int j = 1; j <= i; j++) {

                System.out.println(2 * j - 1);

                if (j < i) {
                    System.out.println("*");
                }
            }

            System.out.println();
        }
    }
}