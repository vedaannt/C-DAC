class Employee {
    private int id;
    private String name;
    private double salary;

    // Constructor
    public Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    // Getters
    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    // Setters
    public void setId(int id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public void display() {
        System.out.println("ID     : " + id);
        System.out.println("Name   : " + name);
        System.out.println("Salary : " + salary);
    }
}


// ================= MANAGER =================

class Manager extends Employee {

    private double bonus;

    public Manager(int id, String name, double salary, double bonus) {
        super(id, name, salary);
        this.bonus = bonus;
    }

    public double getBonus() {
        return bonus;
    }

    public void setBonus(double bonus) {
        this.bonus = bonus;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Bonus  : " + bonus);
        System.out.println("Designation : Manager");
    }
}


// ================= ENGINEER =================

class Engineer extends Employee {

    private String skill;

    public Engineer(int id, String name, double salary, String skill) {
        super(id, name, salary);
        this.skill = skill;
    }

    public String getSkill() {
        return skill;
    }

    public void setSkill(String skill) {
        this.skill = skill;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Skill  : " + skill);
        System.out.println("Designation : Engineer");
    }
}


// ================= SALES PERSON =================

class SalesPerson extends Employee {

    private double commission;

    public SalesPerson(int id, String name, double salary,
                       double commission) {
        super(id, name, salary);
        this.commission = commission;
    }

    public double getCommission() {
        return commission;
    }

    public void setCommission(double commission) {
        this.commission = commission;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Commission : " + commission);
        System.out.println("Designation : Sales Person");
    }
}