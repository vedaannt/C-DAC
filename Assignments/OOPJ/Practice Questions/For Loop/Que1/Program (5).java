public class Program {

    public static void main(String[] args) {

        ComplexNumber arr[] = new ComplexNumber[5];

        for (int i = 0; i < arr.length; i++) {

            arr[i] = new ComplexNumber();

            System.out.println("Enter number1:");
            int number1 = ConsoleInput.getInt();

            System.out.println("Enter number2:");
            int number2 = ConsoleInput.getInt();

            arr[i].setNumber1(number1);
            arr[i].setNumber2(number2);
        }

        for (int i = 0; i < arr.length; i++) {

            System.out.println("Result : "
                    + arr[i].computeComplexNumber());
        }
    }
}