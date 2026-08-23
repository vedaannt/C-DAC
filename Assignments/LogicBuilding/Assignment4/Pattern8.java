public class Pattern8 {
    public static void main(String[] args) {

        for (int i = 1; i <= 6; i++) {

            for (int j = 1; j <= 6; j++) {

                if (i == 1 || i == 6 || j == 1 || j == 6) {
                    System.out.println("*");
                } else {
                    System.out.println(" ");
                }
            }

            System.out.println();
        }
    }
}