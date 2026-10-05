#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include <cstdlib>

using namespace std;


// ============================================================
// EMPLOYEE PAYROLL MANAGEMENT SYSTEM
// C++98 COMPATIBLE VERSION
// ============================================================


// ============================================================
// EMPLOYEE CLASS
// ============================================================

class Employee
{
private:

    int id;

    string name;
    string department;
    string designation;

    double basicSalary;
    double performanceRating;
    double attendance;
    double overtimeHours;

    double bonus;
    double hra;
    double da;
    double overtimePay;

    double pf;
    double tax;
    double otherDeduction;

    double grossSalary;
    double totalDeduction;
    double netSalary;


public:

    // --------------------------------------------------------
    // CONSTRUCTOR
    // --------------------------------------------------------

    Employee()
    {
        id = 0;

        name = "";
        department = "";
        designation = "";

        basicSalary = 0;
        performanceRating = 0;
        attendance = 0;
        overtimeHours = 0;

        bonus = 0;
        hra = 0;
        da = 0;
        overtimePay = 0;

        pf = 0;
        tax = 0;
        otherDeduction = 0;

        grossSalary = 0;
        totalDeduction = 0;
        netSalary = 0;
    }


    // --------------------------------------------------------
    // INPUT EMPLOYEE
    // --------------------------------------------------------

    void inputEmployee()
    {
        cout << "\n";
        cout << "============================================\n";
        cout << "           ENTER EMPLOYEE DETAILS\n";
        cout << "============================================\n";

        cout << "Enter Employee ID: ";
        cin >> id;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Employee Name: ";
        getline(cin, name);

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Designation: ";
        getline(cin, designation);

        cout << "Enter Basic Salary: ";
        cin >> basicSalary;

        cout << "Enter Performance Rating (1-5): ";
        cin >> performanceRating;

        cout << "Enter Attendance Percentage: ";
        cin >> attendance;

        cout << "Enter Overtime Hours: ";
        cin >> overtimeHours;

        cout << "Enter HRA: ";
        cin >> hra;

        cout << "Enter DA: ";
        cin >> da;

        cout << "Enter Other Deduction: ";
        cin >> otherDeduction;

        calculateSalary();

        cout << "\nEmployee added successfully!\n";
    }


    // --------------------------------------------------------
    // SALARY CALCULATION
    // --------------------------------------------------------

    void calculateSalary()
    {
        // Bonus based on performance rating

        if (performanceRating >= 5)
        {
            bonus = basicSalary * 0.20;
        }
        else if (performanceRating >= 4)
        {
            bonus = basicSalary * 0.15;
        }
        else if (performanceRating >= 3)
        {
            bonus = basicSalary * 0.10;
        }
        else if (performanceRating >= 2)
        {
            bonus = basicSalary * 0.05;
        }
        else
        {
            bonus = 0;
        }


        // Overtime pay
        // Rs.300 per overtime hour

        overtimePay = overtimeHours * 300;


        // Gross salary

        grossSalary =
            basicSalary +
            bonus +
            hra +
            da +
            overtimePay;


        // PF = 5% of basic salary

        pf = basicSalary * 0.05;


        // Tax
        // 5% tax if gross salary is above Rs.50,000

        if (grossSalary > 50000)
        {
            tax = grossSalary * 0.05;
        }
        else
        {
            tax = 0;
        }


        // Total deduction

        totalDeduction =
            pf +
            tax +
            otherDeduction;


        // Net salary

        netSalary =
            grossSalary -
            totalDeduction;
    }


    // --------------------------------------------------------
    // DISPLAY EMPLOYEE
    // --------------------------------------------------------

    void displayEmployee() const
    {
        cout << "\n";
        cout << "---------------------------------------------\n";

        cout << "Employee ID       : " << id << endl;
        cout << "Employee Name     : " << name << endl;
        cout << "Department        : " << department << endl;
        cout << "Designation       : " << designation << endl;

        cout << fixed << setprecision(2);

        cout << "Basic Salary      : Rs. "
             << basicSalary << endl;

        cout << "Performance Rating: "
             << performanceRating << endl;

        cout << "Attendance        : "
             << attendance << "%" << endl;

        cout << "Overtime Hours    : "
             << overtimeHours << endl;

        cout << "Net Salary        : Rs. "
             << netSalary << endl;

        cout << "---------------------------------------------\n";
    }


    // --------------------------------------------------------
    // UPDATE EMPLOYEE
    // --------------------------------------------------------

    void updateEmployee()
    {
        cout << "\n";
        cout << "============================================\n";
        cout << "             UPDATE EMPLOYEE\n";
        cout << "============================================\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter New Employee Name: ";
        getline(cin, name);

        cout << "Enter New Department: ";
        getline(cin, department);

        cout << "Enter New Designation: ";
        getline(cin, designation);

        cout << "Enter New Basic Salary: ";
        cin >> basicSalary;

        cout << "Enter New Performance Rating: ";
        cin >> performanceRating;

        cout << "Enter New Attendance Percentage: ";
        cin >> attendance;

        cout << "Enter New Overtime Hours: ";
        cin >> overtimeHours;

        cout << "Enter New HRA: ";
        cin >> hra;

        cout << "Enter New DA: ";
        cin >> da;

        cout << "Enter New Other Deduction: ";
        cin >> otherDeduction;

        calculateSalary();

        cout << "\nEmployee updated successfully!\n";
    }


    // --------------------------------------------------------
    // GENERATE PAYSLIP
    // --------------------------------------------------------

    void generatePayslip() const
    {
        cout << "\n";
        cout << "=============================================\n";
        cout << "              EMPLOYEE PAYSLIP\n";
        cout << "=============================================\n";

        cout << "Employee ID       : " << id << endl;
        cout << "Employee Name     : " << name << endl;
        cout << "Department        : " << department << endl;
        cout << "Designation       : " << designation << endl;

        cout << "---------------------------------------------\n";
        cout << "                 EARNINGS\n";
        cout << "---------------------------------------------\n";

        cout << fixed << setprecision(2);

        cout << "Basic Salary      : Rs. "
             << basicSalary << endl;

        cout << "Bonus             : Rs. "
             << bonus << endl;

        cout << "HRA               : Rs. "
             << hra << endl;

        cout << "DA                : Rs. "
             << da << endl;

        cout << "Overtime Pay      : Rs. "
             << overtimePay << endl;

        cout << "---------------------------------------------\n";

        cout << "Gross Salary      : Rs. "
             << grossSalary << endl;

        cout << "\n";

        cout << "                 DEDUCTIONS\n";

        cout << "---------------------------------------------\n";

        cout << "PF                : Rs. "
             << pf << endl;

        cout << "Tax               : Rs. "
             << tax << endl;

        cout << "Other Deduction   : Rs. "
             << otherDeduction << endl;

        cout << "---------------------------------------------\n";

        cout << "Total Deduction   : Rs. "
             << totalDeduction << endl;

        cout << "=============================================\n";

        cout << "NET SALARY        : Rs. "
             << netSalary << endl;

        cout << "=============================================\n";
    }


    // --------------------------------------------------------
    // GET EMPLOYEE ID
    // --------------------------------------------------------

    int getId() const
    {
        return id;
    }


    // --------------------------------------------------------
    // GET DEPARTMENT
    // --------------------------------------------------------

    string getDepartment() const
    {
        return department;
    }


    // --------------------------------------------------------
    // GET NET SALARY
    // --------------------------------------------------------

    double getNetSalary() const
    {
        return netSalary;
    }


    // --------------------------------------------------------
    // SAVE EMPLOYEE TO FILE
    // --------------------------------------------------------

    void saveToFile(ofstream &file) const
    {
        file << id << "|"
             << name << "|"
             << department << "|"
             << designation << "|"
             << basicSalary << "|"
             << performanceRating << "|"
             << attendance << "|"
             << overtimeHours << "|"
             << hra << "|"
             << da << "|"
             << otherDeduction
             << endl;
    }


    // --------------------------------------------------------
    // LOAD EMPLOYEE FROM FILE
    // --------------------------------------------------------

    bool loadFromFile(ifstream &file)
    {
        string line;

        if (!getline(file, line))
        {
            return false;
        }

        if (line == "")
        {
            return false;
        }


        vector<string> data;

        size_t pos;


        // Separate data using |

        while ((pos = line.find('|')) != string::npos)
        {
            data.push_back(line.substr(0, pos));

            line.erase(0, pos + 1);
        }

        data.push_back(line);


        // We should have 11 values

        if (data.size() != 11)
        {
            return false;
        }


        // Convert string data into required types

        id = atoi(data[0].c_str());

        name = data[1];

        department = data[2];

        designation = data[3];

        basicSalary =
            atof(data[4].c_str());

        performanceRating =
            atof(data[5].c_str());

        attendance =
            atof(data[6].c_str());

        overtimeHours =
            atof(data[7].c_str());

        hra =
            atof(data[8].c_str());

        da =
            atof(data[9].c_str());

        otherDeduction =
            atof(data[10].c_str());


        // Recalculate salary

        calculateSalary();

        return true;
    }
};


// ============================================================
// GLOBAL VECTOR
// ============================================================

vector<Employee> employees;


// ============================================================
// SAVE ALL EMPLOYEES
// ============================================================

void saveAllEmployees()
{
    ofstream file("employees.txt");

    if (!file)
    {
        cout << "\nError opening employees.txt!\n";
        return;
    }


    int i;

    for (i = 0; i < (int)employees.size(); i++)
    {
        employees[i].saveToFile(file);
    }


    file.close();
}


// ============================================================
// LOAD ALL EMPLOYEES
// ============================================================

void loadAllEmployees()
{
    ifstream file("employees.txt");

    // If file does not exist, simply start empty

    if (!file)
    {
        return;
    }


    employees.clear();


    while (true)
    {
        Employee emp;

        if (!emp.loadFromFile(file))
        {
            break;
        }

        employees.push_back(emp);
    }


    file.close();
}


// ============================================================
// CHECK WHETHER ID ALREADY EXISTS
// ============================================================

bool idExists(int id)
{
    int i;

    for (i = 0; i < (int)employees.size(); i++)
    {
        if (employees[i].getId() == id)
        {
            return true;
        }
    }

    return false;
}


// ============================================================
// ADD EMPLOYEE
// ============================================================

void addEmployee()
{
    Employee emp;

    emp.inputEmployee();


    // Check duplicate ID

    if (idExists(emp.getId()))
    {
        cout << "\nEmployee ID already exists!\n";

        cout << "Employee was not added.\n";

        return;
    }


    employees.push_back(emp);


    saveAllEmployees();

    cout << "\nRecord saved successfully!\n";
}


// ============================================================
// DISPLAY ALL EMPLOYEES
// ============================================================

void displayAllEmployees()
{
    if (employees.empty())
    {
        cout << "\nNo employee records available.\n";

        return;
    }


    cout << "\n";
    cout << "============================================\n";
    cout << "             ALL EMPLOYEES\n";
    cout << "============================================\n";


    int i;

    for (i = 0; i < (int)employees.size(); i++)
    {
        employees[i].displayEmployee();
    }
}


// ============================================================
// SEARCH EMPLOYEE
// ============================================================

void searchEmployee()
{
    int id;

    cout << "\nEnter Employee ID to search: ";

    cin >> id;


    int i;

    for (i = 0; i < (int)employees.size(); i++)
    {
        if (employees[i].getId() == id)
        {
            cout << "\nEmployee Found!\n";


            // POINTER USAGE

            Employee *ptr;

            ptr = &employees[i];


            ptr->displayEmployee();


            return;
        }
    }


    cout << "\nEmployee Not Found!\n";
}


// ============================================================
// UPDATE EMPLOYEE
// ============================================================

void updateEmployee()
{
    int id;

    cout << "\nEnter Employee ID to update: ";

    cin >> id;


    int i;

    for (i = 0; i < (int)employees.size(); i++)
    {
        if (employees[i].getId() == id)
        {
            // Pointer usage

            Employee *ptr;

            ptr = &employees[i];


            ptr->updateEmployee();


            saveAllEmployees();


            return;
        }
    }


    cout << "\nEmployee Not Found!\n";
}


// ============================================================
// DELETE EMPLOYEE
// ============================================================

void deleteEmployee()
{
    int id;

    cout << "\nEnter Employee ID to delete: ";

    cin >> id;


    vector<Employee>::iterator it;


    for (it = employees.begin();
         it != employees.end();
         ++it)
    {
        if (it->getId() == id)
        {
            employees.erase(it);


            saveAllEmployees();


            cout << "\nEmployee deleted successfully!\n";


            return;
        }
    }


    cout << "\nEmployee Not Found!\n";
}


// ============================================================
// DEPARTMENT FILTER
// ============================================================

void departmentFilter()
{
    string department;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "\nEnter Department: ";

    getline(cin, department);


    bool found = false;


    cout << "\n";
    cout << "============================================\n";

    cout << "Employees in Department: "
         << department << endl;

    cout << "============================================\n";


    int i;

    for (i = 0; i < (int)employees.size(); i++)
    {
        if (employees[i].getDepartment() == department)
        {
            employees[i].displayEmployee();

            found = true;
        }
    }


    if (!found)
    {
        cout << "\nNo employees found in this department.\n";
    }
}


// ============================================================
// GENERATE PAYSLIP
// ============================================================

void payslip()
{
    int id;

    cout << "\nEnter Employee ID: ";

    cin >> id;


    int i;

    for (i = 0; i < (int)employees.size(); i++)
    {
        if (employees[i].getId() == id)
        {
            employees[i].generatePayslip();

            return;
        }
    }


    cout << "\nEmployee Not Found!\n";
}


// ============================================================
// SALARY ANALYTICS
// ============================================================

void salaryAnalytics()
{
    if (employees.empty())
    {
        cout << "\nNo employee records available.\n";

        return;
    }


    double highest;

    double lowest;

    double total;


    highest = employees[0].getNetSalary();

    lowest = employees[0].getNetSalary();

    total = 0;


    int i;


    for (i = 0; i < (int)employees.size(); i++)
    {
        double salary;

        salary = employees[i].getNetSalary();


        if (salary > highest)
        {
            highest = salary;
        }


        if (salary < lowest)
        {
            lowest = salary;
        }


        total = total + salary;
    }


    double average;

    average = total / employees.size();


    cout << "\n";
    cout << "============================================\n";
    cout << "             SALARY ANALYTICS\n";
    cout << "============================================\n";


    cout << fixed << setprecision(2);


    cout << "Highest Salary : Rs. "
         << highest << endl;


    cout << "Lowest Salary  : Rs. "
         << lowest << endl;


    cout << "Average Salary : Rs. "
         << average << endl;


    cout << "Total Payroll  : Rs. "
         << total << endl;


    cout << "Total Employees: "
         << employees.size() << endl;


    cout << "============================================\n";
}


// ============================================================
// MAIN MENU
// ============================================================

void menu()
{
    cout << "\n\n";

    cout << "=================================================\n";
    cout << "       EMPLOYEE PAYROLL MANAGEMENT SYSTEM\n";
    cout << "=================================================\n";

    cout << "1. Add Employee\n";

    cout << "2. Display All Employees\n";

    cout << "3. Search Employee\n";

    cout << "4. Update Employee\n";

    cout << "5. Delete Employee\n";

    cout << "6. Department Filter\n";

    cout << "7. Generate Payslip\n";

    cout << "8. Salary Analytics\n";

    cout << "9. Save Records\n";

    cout << "0. Exit\n";

    cout << "=================================================\n";

    cout << "Enter your choice: ";
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    // Load old employee records when program starts

    loadAllEmployees();


    int choice;


    do
    {
        menu();


        cin >> choice;


        switch (choice)
        {
            case 1:

                addEmployee();

                break;


            case 2:

                displayAllEmployees();

                break;


            case 3:

                searchEmployee();

                break;


            case 4:

                updateEmployee();

                break;


            case 5:

                deleteEmployee();

                break;


            case 6:

                departmentFilter();

                break;


            case 7:

                payslip();

                break;


            case 8:

                salaryAnalytics();

                break;


            case 9:

                saveAllEmployees();

                cout << "\nRecords saved successfully!\n";

                break;


            case 0:

                saveAllEmployees();

                cout << "\n";
                cout << "Thank you for using ";
                cout << "Employee Payroll Management System!\n";

                break;


            default:

                cout << "\nInvalid choice!\n";

                cout << "Please enter a valid option.\n";
        }


    }
    while (choice != 0);


    return 0;
}
