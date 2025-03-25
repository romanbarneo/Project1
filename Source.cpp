#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;

// создать структуру
// Employee
// int id
// char name[50]
// double salary
// написать функции добавления сотрудника в файл
// показать всех сотрудников из файла
// найти сотрудника по id 
// удалить сотрудника по id

//задание  2 (дз) создать структуру
// Order
// int OrderID
// char customer[50]
// double amount
// написать функции
// добавление заказа +
// вывод всех заказов +
// поиск заказа по id 
// поиск заказа по customer
// удалить заказ по id 
// редактировать заказ по id +
// отсортировать заказы по сумме. 

struct Order {
    int OrderID;
    char customer[50];
    double amount;
};

void AddOrder(const char* fileName)
{
    ofstream file(fileName, ios::binary | ios::app);
    if (!file)
    {
        cout << "Ошибка открытия файла";
        return;
    }
    Order order;
    cout << "введите id заказа" << endl;
    cin >> order.OrderID;
    cin.ignore();
    cout << "введите имя заказчика" << endl;
    cin.getline(order.customer, 50);
    cout << "введите сумму заказа" << endl;
    cin >> order.amount;

    file.write((char*)&order, sizeof(order));
    file.close();
    cout << "заказ добавлен" << endl;
}

void showOrders(const char* fileName)
{
    ifstream file(fileName, ios::binary);
    if (!file)
    {
        cout << "Ошибка открытия файла";
        return;
    }
    Order order;
    while (file.read((char*)&order, sizeof(Order)))
    {
    cout << order.OrderID << endl;
    cout << order.customer << endl;
    cout << order.amount << endl;
    }
    file.close();
}

void reWritenOrder(const char* fileName, int id, int amount)
{
    ifstream file(fileName, ios::binary);
    ofstream tempFile("temp.dat", ios::binary);
        if (!file || !tempFile)
        {
            cout << "Ошибка открытия файла";
            return;
        }
        Order order;
        bool isRe = true;
        while (file.read((char*)&order, sizeof(Order)))
        {
            if (order.OrderID == id)
            {
                order.amount = amount;
            }
            else {
                isRe = false;
            }
            tempFile.write((char*)&order, sizeof(Order));
        }
        file.close();
        tempFile.close();
        remove(fileName);
        rename("temp.dat", fileName);
        if (isRe)
        {
            cout << "успешно отредактирован" << endl;
        }
        else
        {
            cout << "заказ не найден" << endl;
        }
    
}

void sortOrder(const char* fileName)
{

}

//struct Employee {
//    int id;
//    char name[50];
//    double salary;
//};
//
//void AddEmployee(const char* fileName)
//{
//    ofstream file(fileName, ios::binary | ios::app);
//    if (!file)
//    {
//        cout << "Ошибка открытия файла";
//        return;
//    }
//    Employee emp;
//    cout << "введите id сотрудника" << endl;
//    cin >> emp.id;
//    cin.ignore();
//    cout << "введите имя сотрудника" << endl;
//    cin.getline(emp.name, 50);
//    cout << "введите зп сотрудника" << endl;
//    cin >> emp.salary;
//
//    file.write((char*)&emp, sizeof(emp));
//    file.close();
//    cout << "сотрудник добавлен" << endl;
//}
//
//void showEmployee(const char* fileName)
//{
//    ifstream file(fileName, ios::binary);
//    if (!file)
//    {
//        cout << "Ошибка открытия файла";
//        return;
//    }
//    Employee emp;
//    while (file.read((char*)&emp, sizeof(Employee)))
//    {
//    cout << emp.id << endl;
//    cout << emp.name << endl;
//    cout << emp.salary << endl;
//    }
//    file.close();
//}
//
//void searchEmployeeForID(const char* fileName)
//{
//    ifstream file(fileName, ios::binary);
//    if (!file)
//    {
//        cout << "Ошибка открытия файла";
//        return;
//    }
//    Employee emp;
//    int searchID;
//    cout << "введите id для поиска" << endl;
//    cin >> searchID;
//    while (file.read((char*)&emp, sizeof(Employee)))
//        if (emp.id == searchID)
//        {
//            cout << emp.id << endl;
//            cout << emp.name << endl;
//            cout << emp.salary << endl;
//        }
//    file.close();
//}
//
//void removeEmployeeForID(const char* fileName, int removeID)
//{
//    ifstream file(fileName, ios::binary);
//    ofstream tempFile("temp.dat", ios::binary);
//    if (!file || !tempFile)
//    {
//        cout << "Ошибка открытия файла";
//        return;
//    }
//    Employee emp;
//    bool isDelete = false;
//    while (file.read((char*)&emp, sizeof(Employee)))
//    {
//        if (emp.id != removeID)
//        {
//            tempFile.write((char*)&emp, sizeof(Employee));
//        }
//        else {
//            isDelete = true;
//        }
//    }
//    file.close();
//    tempFile.close();
//    remove(fileName);
//    rename("temp.dat", fileName);
//    if (isDelete)
//    {
//        cout << "успешно удален" << endl;
//    }
//    else
//    {
//        cout << "сотрудник не найден" << endl;
//    }
//}

int main()
{
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    /*const char* fileName = "employees.dat";
    int choice;*/
    /*do
    {
        cout << "1 - добавить сотрудника" << endl;
        cout << "2 - показать сотрудников" << endl;
        cout << "3 - поиск сотрудников по id" << endl;
        cout << "4 - удаление сотрудников по id" << endl;
        cout << "0 - выход" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
        {
            AddEmployee(fileName);
            break;
        }
        case 2:
        {
            showEmployee(fileName);
            break;
        }
        case 3:
        {
            searchEmployeeForID(fileName);
            break;
        }
        case 4:
        {
            int deleteID;
            cout << "введите id для удаления" << endl;
            cin >> deleteID,
            removeEmployeeForID(fileName, deleteID);
            break;
        }
        case 0:
        {
            cout << "работа программы завершена" << endl;
            break;
        }
        default: {
            cout << "некорректный ввод" << endl;
        }
        }
    }
    while (choice != 0);*/

    const char* fileName = "Order.dat";
    int choice;

    do
    {
        cout << "1 - добавить заказ" << endl;
        cout << "2 - показать все заказы" << endl;
        cout << "3 - редактировать заказ" << endl;
        cout << "0 - выход" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
        {
            AddOrder(fileName);
            break;
        }
        case 2:
        {
            showOrders(fileName);
            break;
        }
        case 3:
        {
            int id, amount;
            cout << "введите id для редактирования" << endl;
            cin >> id;
            cout << "введите новую сумму" << endl;
            cin >> amount;
            reWritenOrder(fileName, id, amount);
            break;
        }
        case 0:
        {
            cout << "работа программы завершена" << endl;
            break;
        }
        default:
        {
            cout << "некорректный ввод" << endl;
        }
        }

        } 
    while (choice != 0);

    cout << endl;

    
}