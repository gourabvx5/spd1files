#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <regex>

using namespace std;

bool Emailcheck(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}

class employee
{
private:
    string name, emp_id, position, address, email_id;
    double salary;
    int leaves;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleteRecord();
    void manageSalary();
    void manageLeaves();
};

void employee::menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| EMPLOYEE MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Manage Salary" << endl;
    cout << "\t\t\t 7. Manage Leaves" << endl;
    cout << "\t\t\t 8. Exit\n"
         << endl;

    cout << "\t\t\t............................" << endl;
    cout << "\t\t\tChoose Options:[1/2/3/4/5/6/7/8]" << endl;
    cout << "\t\t\t............................" << endl;
    cout << " Enter Your Choose: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\n\t\t\t Add Another Employee Record (Y, N) : ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleteRecord();
        break;
    case 6:
        manageSalary();
        break;
    case 7:
        manageLeaves();
        break;
    case 8:
        cout << "\n\t\t\t Program Is Exit";
        exit(0);
    default:
        cout << "\n\n\t\t\t Invalid Choice... Please Try Again...";
    }
    cin.ignore();
    cin.get();
    goto menustart;
}

void employee::insert()
{
    system("cls");
    fstream file;
    cout << "\n----------------------------------------------------" << endl;
    cout << "------------ Add Employee Details ------------" << endl;
    cout << "\t\t\tEnter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\t\t\tEnter Employee ID: ";
    getline(cin, emp_id);
    cout << "\t\t\tEnter Position: ";
    getline(cin, position);
    cout << "\t\t\tEnter Email Id(name@gmail.com): ";
    cin >> email_id;
    if (Emailcheck(email_id))
    {
        cout << "\t\t\t Your Email-Id is Valid" << endl;
    }
    else
    {
        cout << "\t\t\t Your Email-Id is Invalid" << endl;
        return;
    }
    cin.ignore();
    cout << "\t\t\tEnter Address: ";
    getline(cin, address);
    cout << "\t\t\tEnter Salary: ";
    cin >> salary;
    cout << "\t\t\tEnter Leaves: ";
    cin >> leaves;
    file.open("employeeRecord.txt", ios::app | ios::out);
    file << name << " " << emp_id << " " << position << " " << email_id << " " << address << " " << salary << " " << leaves << "\n";
    file.close();
}

void employee::display()
{
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n----------------------------------------------------" << endl;
    cout << "------------ Employee Record Table ------------" << endl;
    file.open("employeeRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
    }
    else
    {
        while (file >> name >> emp_id >> position >> email_id >> address >> salary >> leaves)
        {
            cout << "\n\n\t\t\tEmployee No.: " << ++total << endl;
            cout << "\t\t\tName: " << name << "\n";
            cout << "\t\t\tEmployee ID: " << emp_id << "\n";
            cout << "\t\t\tPosition: " << position << "\n";
            cout << "\t\t\tEmail Id: " << email_id << "\n";
            cout << "\t\t\tAddress: " << address << "\n";
            cout << "\t\t\tSalary: " << salary << "\n";
            cout << "\t\t\tLeaves: " << leaves << "\n";
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data is Present..." << endl;
        }
    }
    file.close();
}

void employee::modify()
{
    system("cls");
    fstream file, temp;
    bool found = false;
    string modify_emp_id;
    cout << "\n----------------------------------------------------" << endl;
    cout << "------------ Modify Employee Details ------------" << endl;
    file.open("employeeRecord.txt", ios::in);
    temp.open("temp.txt", ios::out);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Employee ID to Modify: ";
        cin >> modify_emp_id;
        while (file >> name >> emp_id >> position >> email_id >> address >> salary >> leaves)
        {
            if (modify_emp_id != emp_id)
            {
                temp << name << " " << emp_id << " " << position << " " << email_id << " " << address << " " << salary << " " << leaves << "\n";
            }
            else
            {
                cout << "\n\t\t\tEnter New Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "\t\t\tEnter New Position: ";
                getline(cin, position);
                cout << "\t\t\tEnter New Email Id(name@gmail.com): ";
                cin >> email_id;
                if (Emailcheck(email_id))
                {
                    cout << "\t\t\t Your Email-Id is Valid" << endl;
                }
                else
                {
                    cout << "\t\t\t Your Email-Id is Invalid" << endl;
                    return;
                }
                cin.ignore();
                cout << "\t\t\tEnter New Address: ";
                getline(cin, address);
                cout << "\t\t\tEnter New Salary: ";
                cin >> salary;
                cout << "\t\t\tEnter New Leaves: ";
                cin >> leaves;
                temp << name << " " << emp_id << " " << position << " " << email_id << " " << address << " " << salary << " " << leaves << "\n";
                found = true;
            }
        }
        if (!found)
        {
            cout << "\n\t\t\t Employee ID Not Found...";
        }
    }
    file.close();
    temp.close();
    remove("employeeRecord.txt");
    rename("temp.txt", "employeeRecord.txt");
}

void employee::search()
{
    system("cls");
    fstream file;
    bool found = false;
    string search_emp_id;
    cout << "\n----------------------------------------------------" << endl;
    cout << "------------ Search Employee Record ------------" << endl;
    file.open("employeeRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
    }
    else
    {
        cout << "\nEnter Employee ID to Search: ";
        cin >> search_emp_id;
        while (file >> name >> emp_id >> position >> email_id >> address >> salary >> leaves)
        {
            if (search_emp_id == emp_id)
            {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tEmployee ID: " << emp_id << "\n";
                cout << "\t\t\tPosition: " << position << "\n";
                cout << "\t\t\tEmail Id: " << email_id << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                cout << "\t\t\tSalary: " << salary << "\n";
                cout << "\t\t\tLeaves: " << leaves << "\n";
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "\n\t\t\t Employee ID Not Found...";
        }
    }
    file.close();
}

void employee::deleteRecord()
{
    system("cls");
    fstream file, temp;
    bool found = false;
    string delete_emp_id;
    cout << "\n----------------------------------------------------" << endl;
    cout << "------------ Delete Employee Record ------------" << endl;
    file.open("employeeRecord.txt", ios::in);
    temp.open("temp.txt", ios::out);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Employee ID to Delete: ";
        cin >> delete_emp_id;
        while (file >> name >> emp_id >> position >> email_id >> address >> salary >> leaves)
        {
            if (delete_emp_id != emp_id)
            {
                temp << name << " " << emp_id << " " << position << " " << email_id << " " << address << " " << salary << " " << leaves << "\n";
            }
            else
            {
                found = true;
                cout << "\n\t\t\tSuccessfully Deleted Data";
            }
        }
        if (!found)
        {
            cout << "\n\t\t\t Employee ID Not Found...";
        }
    }
    file.close();
    temp.close();
    remove("employeeRecord.txt");
    rename("temp.txt", "employeeRecord.txt");
}

void employee::manageSalary()
{
    system("cls");
    fstream file, temp;
    bool found = false;
    string manage_emp_id;
    double new_salary;
    cout << "\n----------------------------------------------------" << endl;
    cout << "------------ Manage Employee Salary ------------" << endl;
    file.open("employeeRecord.txt", ios::in);
    temp.open("temp.txt", ios::out);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Employee ID to Manage Salary: ";
        cin >> manage_emp_id;
        while (file >> name >> emp_id >> position >> email_id >> address >> salary >> leaves)
        {
            if (manage_emp_id != emp_id)
            {
                temp << name << " " << emp_id << " " << position << " " << email_id << " " << address << " " << salary << " " << leaves << "\n";
            }
            else
            {
                found = true;
                cout << "\n\t\t\tCurrent Salary: " << salary << "\n";
                cout << "\nEnter New Salary: ";
                cin >> new_salary;
                temp << name << " " << emp_id << " " << position << " " << email_id << " " << address << " " << new_salary << " " << leaves << "\n";
                cout << "\n\t\t\tSalary Updated Successfully";
            }
        }
        if (!found)
        {
            cout << "\n\t\t\t Employee ID Not Found...";
        }
    }
    file.close();
    temp.close();
    remove("employeeRecord.txt");
    rename("temp.txt", "employeeRecord.txt");
}

void employee::manageLeaves()
{
    system("cls");
    fstream file, temp;
    bool found = false;
    string manage_emp_id;
    int new_leaves;
    cout << "\n----------------------------------------------------" << endl;
    cout << "------------ Manage Employee Leaves ------------" << endl;
    file.open("employeeRecord.txt", ios::in);
    temp.open("temp.txt", ios::out);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Employee ID to Manage Leaves: ";
        cin >> manage_emp_id;
        while (file >> name >> emp_id >> position >> email_id >> address >> salary >> leaves)
        {
            if (manage_emp_id != emp_id)
            {
                temp << name << " " << emp_id << " " << position << " " << email_id << " " << address << " " << salary << " " << leaves << "\n";
            }
            else
            {
                found = true;
                cout << "\n\t\t\tCurrent Leaves: " << leaves << "\n";
                cout << "\nEnter New Leaves: ";
                cin >> new_leaves;
                temp << name << " " << emp_id << " " << position << " " << email_id << " " << address << " " << salary << " " << new_leaves << "\n";
                cout << "\n\t\t\tLeaves Updated Successfully";
            }
        }
        if (!found)
        {
            cout << "\n\t\t\t Employee ID Not Found...";
        }
    }
    file.close();
    temp.close();
    remove("employeeRecord.txt");
    rename("temp.txt", "employeeRecord.txt");
}

int main()
{
    employee emp;
    emp.menu();
    return 0;
}
