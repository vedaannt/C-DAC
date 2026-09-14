public class Implementation {

    // =====================================================
    // 1. STUDENT
    // =====================================================

    public static void student() {

        Student s1 = new Student(
                "John",
                2,
                "9876543210",
                "Pune"
        );

        Student s2 = new Student(
                "Sam",
                1,
                "9876543211",
                "Mumbai"
        );

        System.out.println("\nStudent 1");
        s1.display();

        System.out.println("\nStudent 2");
        s2.display();
    }


    // =====================================================
    // 2. TRIANGLE
    // =====================================================

    public static void triangle() {

        Triangle t = new Triangle(3, 4, 5);

        System.out.println("\nArea = " + t.area());
        System.out.println("Perimeter = " + t.perimeter());
    }


    // =====================================================
    // 3. RECTANGLE
    // =====================================================

    public static void rectangle() {

        Rectangle r1 = new Rectangle(4, 5);
        Rectangle r2 = new Rectangle(5, 8);

        System.out.println(
                "\nArea of Rectangle 1 = " + r1.area());

        System.out.println(
                "Area of Rectangle 2 = " + r2.area());
    }


    // =====================================================
    // 4. COMPLEX NUMBER
    // =====================================================

    public static void complex() {

        System.out.print(
                "\nEnter real part of first number: ");

        float r1 = ConsoleInput.getFloat();

        System.out.print(
                "Enter imaginary part of first number: ");

        float i1 = ConsoleInput.getFloat();

        System.out.print(
                "Enter real part of second number: ");

        float r2 = ConsoleInput.getFloat();

        System.out.print(
                "Enter imaginary part of second number: ");

        float i2 = ConsoleInput.getFloat();


        Complex c1 = new Complex(r1, i1);
        Complex c2 = new Complex(r2, i2);


        System.out.print("\nSum = ");
        c1.sum(c2).display();

        System.out.print("Difference = ");
        c1.difference(c2).display();

        System.out.print("Product = ");
        c1.product(c2).display();
    }


    // =====================================================
    // 5. EMPLOYEE INFORMATION
    // =====================================================

    public static void employeeInfo() {

        Employee e1 = new Employee(
                "Robert",
                1994,
                50000,
                "64C-WallsStreat"
        );

        Employee e2 = new Employee(
                "Sam",
                2000,
                60000,
                "68D-WallsStreat"
        );

        Employee e3 = new Employee(
                "John",
                1999,
                55000,
                "26B-WallsStreat"
        );


        System.out.println(
                "\nName\tYear of Joining\tSalary\tAddress");

        e1.display();
        e2.display();
        e3.display();
    }


    // =====================================================
    // 6. EMPLOYEE SALARY
    // =====================================================

    public static void employeeSalary() {

        System.out.print("\nEnter salary: ");

        float salary = ConsoleInput.getFloat();

        System.out.print(
                "Enter hours of work per day: ");

        int hours = ConsoleInput.getInt();


        EmployeeSalary e = new EmployeeSalary();

        e.getInfo(salary, hours);

        e.addSal();

        e.addWork();


        System.out.println(
                "Final Salary = " + e.getSalary());
    }


    // =====================================================
    // STUDENT CLASS
    // =====================================================

    static class Student {

        private String name;
        private int rollNo;
        private String phoneNo;
        private String address;


        Student(String name, int rollNo,
                String phoneNo, String address) {

            this.name = name;
            this.rollNo = rollNo;
            this.phoneNo = phoneNo;
            this.address = address;
        }


        void display() {

            System.out.println("Name     : " + name);
            System.out.println("Roll No  : " + rollNo);
            System.out.println("Phone No : " + phoneNo);
            System.out.println("Address  : " + address);
        }
    }


    // =====================================================
    // TRIANGLE CLASS
    // =====================================================

    static class Triangle {

        private float side1;
        private float side2;
        private float side3;


        Triangle(float side1, float side2, float side3) {

            this.side1 = side1;
            this.side2 = side2;
            this.side3 = side3;
        }


        float perimeter() {

            return side1 + side2 + side3;
        }


        double area() {

            float s = perimeter() / 2;

            return Math.sqrt(
                    s * (s - side1) *
                    (s - side2) *
                    (s - side3)
            );
        }
    }


    // =====================================================
    // RECTANGLE CLASS
    // =====================================================

    static class Rectangle {

        private float length;
        private float breadth;


        Rectangle(float length, float breadth) {

            this.length = length;
            this.breadth = breadth;
        }


        float area() {

            return length * breadth;
        }
    }


    // =====================================================
    // COMPLEX CLASS
    // =====================================================

    static class Complex {

        private float real;
        private float imaginary;


        Complex(float real, float imaginary) {

            this.real = real;
            this.imaginary = imaginary;
        }


        Complex sum(Complex c) {

            return new Complex(
                    real + c.real,
                    imaginary + c.imaginary
            );
        }


        Complex difference(Complex c) {

            return new Complex(
                    real - c.real,
                    imaginary - c.imaginary
            );
        }


        Complex product(Complex c) {

            float r =
                    (real * c.real)
                    - (imaginary * c.imaginary);

            float i =
                    (real * c.imaginary)
                    + (imaginary * c.real);

            return new Complex(r, i);
        }


        void display() {

            System.out.println(
                    real + " + " + imaginary + "i");
        }
    }


    // =====================================================
    // EMPLOYEE INFORMATION CLASS
    // =====================================================

    static class Employee {

        private String name;
        private int yearOfJoining;
        private float salary;
        private String address;


        Employee(String name,
                 int yearOfJoining,
                 float salary,
                 String address) {

            this.name = name;
            this.yearOfJoining = yearOfJoining;
            this.salary = salary;
            this.address = address;
        }


        void display() {

            System.out.println(
                    name + "\t" +
                    yearOfJoining + "\t" +
                    salary + "\t" +
                    address
            );
        }
    }


    // =====================================================
    // EMPLOYEE SALARY CLASS
    // =====================================================

    static class EmployeeSalary {

        private float salary;
        private int hours;


        void getInfo(float salary, int hours) {

            this.salary = salary;
            this.hours = hours;
        }


        void addSal() {

            if (salary < 500) {

                salary = salary + 10;
            }
        }


        void addWork() {

            if (hours > 6) {

                salary = salary + 5;
            }
        }


        float getSalary() {

            return salary;
        }
    }
}