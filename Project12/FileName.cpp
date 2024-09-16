#include <iostream>
#include <string>  // Для використання std::string

using namespace std;

const int MAX_EMPLOYEES = 100; // Максимальна кількість співробітників

struct Employee {
    string firstName;
    string lastName;
    string phoneNumber;
    double salary;
};

Employee employees[MAX_EMPLOYEES]; // Масив для зберігання співробітників
int employeeCount = 0; // Лічильник кількості співробітників

// Функція для додавання співробітника
void addEmployee() {
    if (employeeCount < MAX_EMPLOYEES) {
        cout << "Введіть ім'я: ";
        cin >> employees[employeeCount].firstName;

        cout << "Введіть прізвище: ";
        cin >> employees[employeeCount].lastName;

        cout << "Введіть номер телефону: ";
        cin >> employees[employeeCount].phoneNumber;

        cout << "Введіть зарплату: ";
        cin >> employees[employeeCount].salary;

        employeeCount++;
    }
    else {
        cout << "Не можна додати більше співробітників!" << endl;
    }
}

// Функція для виведення інформації про всіх співробітників
void showAllEmployees() {
    for (int i = 0; i < employeeCount; i++) {
        cout << "Ім'я: " << employees[i].firstName
            << ", Прізвище: " << employees[i].lastName
            << ", Телефон: " << employees[i].phoneNumber
            << ", Зарплата: " << employees[i].salary << endl;
    }
}

// Пошук співробітника за прізвищем
void findEmployeeByLastName() {
    string lastName;
    cout << "Введіть прізвище для пошуку: ";
    cin >> lastName;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].lastName == lastName) {
            cout << "Ім'я: " << employees[i].firstName
                << ", Прізвище: " << employees[i].lastName
                << ", Телефон: " << employees[i].phoneNumber
                << ", Зарплата: " << employees[i].salary << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Співробітника з таким прізвищем не знайдено." << endl;
    }
}

// Функція для пошуку співробітників за діапазоном зарплати
void findEmployeesBySalaryRange() {
    double minSalary, maxSalary;
    cout << "Введіть мінімальну зарплату: ";
    cin >> minSalary;
    cout << "Введіть максимальну зарплату: ";
    cin >> maxSalary;

    bool found = false;
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].salary >= minSalary && employees[i].salary <= maxSalary) {
            cout << "Ім'я: " << employees[i].firstName
                << ", Прізвище: " << employees[i].lastName
                << ", Телефон: " << employees[i].phoneNumber
                << ", Зарплата: " << employees[i].salary << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Співробітників з таким діапазоном зарплат не знайдено." << endl;
    }
}

// Видалення співробітника за індексом
void deleteEmployee() {
    int index;
    cout << "Введіть номер співробітника для видалення (від 0 до " << employeeCount - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < employeeCount) {
        for (int i = index; i < employeeCount - 1; i++) {
            employees[i] = employees[i + 1]; // Зсуваємо масив на одну позицію
        }
        employeeCount--;
        cout << "Співробітника видалено." << endl;
    }
    else {
        cout << "Некоректний індекс!" << endl;
    }
}

// Меню програми
void menu() {
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Додати співробітника\n";
        cout << "2. Показати всіх співробітників\n";
        cout << "3. Пошук співробітника за прізвищем\n";
        cout << "4. Пошук за діапазоном зарплати\n";
        cout << "5. Видалити співробітника\n";
        cout << "6. Вийти\n";
        cout << "Оберіть дію: ";
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
            cout << "Вихід з програми.\n";
            break;
        default:
            cout << "Невірний вибір! Спробуйте ще раз.\n";
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}
