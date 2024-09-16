#include <iostream>
#include <string>  // ��� ������������ std::string

using namespace std;

const int MAX_EMPLOYEES = 100; // ����������� ������� �����������

struct Employee {
    string firstName;
    string lastName;
    string phoneNumber;
    double salary;
};

Employee employees[MAX_EMPLOYEES]; // ����� ��� ��������� �����������
int employeeCount = 0; // ˳������� ������� �����������

// ������� ��� ��������� �����������
void addEmployee() {
    if (employeeCount < MAX_EMPLOYEES) {
        cout << "������ ��'�: ";
        cin >> employees[employeeCount].firstName;

        cout << "������ �������: ";
        cin >> employees[employeeCount].lastName;

        cout << "������ ����� ��������: ";
        cin >> employees[employeeCount].phoneNumber;

        cout << "������ ��������: ";
        cin >> employees[employeeCount].salary;

        employeeCount++;
    }
    else {
        cout << "�� ����� ������ ����� �����������!" << endl;
    }
}

// ������� ��� ��������� ���������� ��� ��� �����������
void showAllEmployees() {
    for (int i = 0; i < employeeCount; i++) {
        cout << "��'�: " << employees[i].firstName
            << ", �������: " << employees[i].lastName
            << ", �������: " << employees[i].phoneNumber
            << ", ��������: " << employees[i].salary << endl;
    }
}

// ����� ����������� �� ��������
void findEmployeeByLastName() {
    string lastName;
    cout << "������ ������� ��� ������: ";
    cin >> lastName;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].lastName == lastName) {
            cout << "��'�: " << employees[i].firstName
                << ", �������: " << employees[i].lastName
                << ", �������: " << employees[i].phoneNumber
                << ", ��������: " << employees[i].salary << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "����������� � ����� �������� �� ��������." << endl;
    }
}

// ������� ��� ������ ����������� �� ��������� ��������
void findEmployeesBySalaryRange() {
    double minSalary, maxSalary;
    cout << "������ �������� ��������: ";
    cin >> minSalary;
    cout << "������ ����������� ��������: ";
    cin >> maxSalary;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            cout << "��'�: " << employees[i].firstName
                << ", �������: " << employees[i].lastName
                << ", �������: " << employees[i].phoneNumber
                << ", ��������: " << employees[i].salary << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "����������� � ����� ��������� ������� �� ��������." << endl;
    }
}

// ��������� ����������� �� ��������
void deleteEmployee() {
    int index;
    cout << "������ ����� ����������� ��� ��������� (�� 0 �� " << employeeCount - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < employeeCount) {
        for (int i = index; i < employeeCount - 1; i++) {
            employees[i] = employees[i + 1]; // ������� ����� �� ���� �������
        }
        employeeCount--;
        cout << "����������� ��������." << endl;
    }
    else {
        cout << "����������� ������!" << endl;
    }
}

// ���� ��������
void menu() {
    int choice;

    do {
        cout << "\n����:\n";
        cout << "1. ������ �����������\n";
        cout << "2. �������� ��� �����������\n";
        cout << "3. ����� ����������� �� ��������\n";
        cout << "4. ����� �� ��������� ��������\n";
        cout << "5. �������� �����������\n";
        cout << "6. �����\n";
        cout << "������ ��: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            showAllEmployees();
            break;
        case 3:
            findEmployeeByLastName();
            break;
        case 4:
            findEmployeesBySalaryRange();
            break;
        case 5:
            deleteEmployee();
            break;
        case 6:
            cout << "����� � ��������.\n";
            break;
        default:
            cout << "������� ����! ��������� �� ���.\n";
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
