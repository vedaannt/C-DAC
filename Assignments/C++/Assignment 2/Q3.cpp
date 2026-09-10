#include <iostream>
#include <string>

using namespace std;


class Employee
{
private:

    int empId;

    string name;

    string department;

    char grade;

    double basicSalary;

    bool isActive;


    static int employeeCount;

    static int nextEmpId;


public:

    // Constructor
    Employee()
    {
        empId = nextEmpId++;

        name = "";

        department = "";

        grade = 'D';

        basicSalary = 10001;

        isActive = true;

        employeeCount++;
    }


    // Set Name
    void setName(string n)
    {
        if(n.empty())
        {
            cout << "ERROR: Name cannot be empty."
                 << endl;
        }
        else
        {
            name = n;
        }
    }


    // Set Department
    void setDepartment(string dept)
    {
        if(dept == "Engineering" ||
           dept == "HR" ||
           dept == "Finance" ||
           dept == "Operations")
        {
            department = dept;
        }
        else
        {
            cout << "ERROR: '"
                 << dept
                 << "' is not a registered department."
                 << endl;
        }
    }


    // Set Grade
    void setGrade(char g)
    {
        if(g == 'A' ||
           g == 'B' ||
           g == 'C' ||
           g == 'D')
        {
            grade = g;
        }
        else
        {
            cout << "ERROR: Invalid grade '"
                 << g << "'"
                 << endl;
        }
    }


    // Set Salary
    void setBasicSalary(double salary)
    {
        if(salary > 10000 &&
           salary < 500000)
        {
            basicSalary = salary;
        }
        else
        {
            cout << "ERROR: Salary must be between "
                 << "Rs.10,000 and Rs.5,00,000."
                 << endl;
        }
    }


    // Deactivate
    void deactivate()
    {
        isActive = false;
    }


    // Getters

    int getEmpId() const
    {
        return empId;
    }


    string getName() const
    {
        return name;
    }


    string getDepartment() const
    {
        return department;
    }


    char getGrade() const
    {
        return grade;
    }


    double getBasicSalary() const
    {
        return basicSalary;
    }


    bool getIsActive() const
    {
        return isActive;
    }


    // Allowance
    double computeAllowances() const
    {
        if(grade == 'A')
        {
            return basicSalary * 0.40;
        }
        else if(grade == 'B')
        {
            return basicSalary * 0.30;
        }
        else if(grade == 'C')
        {
            return basicSalary * 0.20;
        }
        else
        {
            return basicSalary * 0.10;
        }
    }


    // Gross salary
    double computeGrossSalary() const
    {
        return basicSalary +
               computeAllowances();
    }


    // Tax
    double computeTax() const
    {
        double gross =
            computeGrossSalary();


        if(gross <= 50000)
        {
            return 0;
        }
        else if(gross <= 100000)
        {
            return (gross - 50000) * 0.10;
        }
        else
        {
            return 5000 +
                   (gross - 100000) * 0.20;
        }
    }


    // Net salary
    double computeNetSalary() const
    {
        return computeGrossSalary()
               - computeTax();
    }


    // Accept details
    void acceptDetails()
    {
        string n;
        string dept;

        char g;

        double salary;


        cout << "Enter name : ";

        cin >> ws;

        getline(cin, n);

        setName(n);


        cout << "Enter department : ";

        getline(cin, dept);

        setDepartment(dept);


        cout << "Enter grade : ";

        cin >> g;

        setGrade(g);


        cout << "Enter basic salary : ";

        cin >> salary;

        setBasicSalary(salary);
    }


    // Payslip
    void printPayslip() const
    {
        cout << endl;

        cout << "================================"
             << endl;

        cout << "       EMPLOYEE PAYSLIP"
             << endl;

        cout << "================================"
             << endl;


        cout << "Emp ID : "
             << empId << endl;

        cout << "Name : "
             << name << endl;

        cout << "Department : "
             << department << endl;

        cout << "Grade : "
             << grade << endl;


        cout << "Status : ";

        if(isActive)
        {
            cout << "Active" << endl;
        }
        else
        {
            cout << "Inactive" << endl;
        }


        cout << "Basic Salary : Rs. "
             << basicSalary << endl;

        cout << "Allowances : Rs. "
             << computeAllowances() << endl;

        cout << "Gross Salary : Rs. "
             << computeGrossSalary() << endl;

        cout << "Tax Deduction : Rs. "
             << computeTax() << endl;

        cout << "Net Salary : Rs. "
             << computeNetSalary() << endl;


        cout << "================================"
             << endl;
    }


    // Static function
    static int getEmployeeCount()
    {
        return employeeCount;
    }
};


// Static variables
int Employee::employeeCount = 0;

int Employee::nextEmpId = 1001;


int main()
{
    // Stack object
    Employee e1;


    // Heap objects
    Employee* e2 =
        new Employee();

    Employee* e3 =
        new Employee();


    // Input
    e1.acceptDetails();

    e2->acceptDetails();

    e3->acceptDetails();


    // Print
    e1.printPayslip();

    e2->printPayslip();

    e3->printPayslip();


    // Deactivate employee
    e3->deactivate();


    if(!e3->getIsActive())
    {
        cout << e3->getName()
             << " is no longer active. "
             << "Payroll skipped."
             << endl;
    }


    cout << "Total Employees : "
         << Employee::getEmployeeCount()
         << endl;


    // Delete heap objects
    delete e2;

    delete e3;


    return 0;
}