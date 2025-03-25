#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;

// ������� ���������
// Employee
// int id
// char name[50]
// double salary
// �������� ������� ���������� ���������� � ����
// �������� ���� ����������� �� �����
// ����� ���������� �� id 
// ������� ���������� �� id

//�������  2 (��) ������� ���������
// Order
// int OrderID
// char customer[50]
// double amount
// �������� �������
// ���������� ������ +
// ����� ���� ������� +
// ����� ������ �� id 
// ����� ������ �� customer
// ������� ����� �� id 
// ������������� ����� �� id +
// ������������� ������ �� �����. 

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
        cout << "������ �������� �����";
        return;
    }
    Order order;
    cout << "������� id ������" << endl;
    cin >> order.OrderID;
    cin.ignore();
    cout << "������� ��� ���������" << endl;
    cin.getline(order.customer, 50);
    cout << "������� ����� ������" << endl;
    cin >> order.amount;

    file.write((char*)&order, sizeof(order));
    file.close();
    cout << "����� ��������" << endl;
}

void showOrders(const char* fileName)
{
    ifstream file(fileName, ios::binary);
    if (!file)
    {
        cout << "������ �������� �����";
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
            cout << "������ �������� �����";
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
            cout << "������� ��������������" << endl;
        }
        else
        {
            cout << "����� �� ������" << endl;
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
//        cout << "������ �������� �����";
//        return;
//    }
//    Employee emp;
//    cout << "������� id ����������" << endl;
//    cin >> emp.id;
//    cin.ignore();
//    cout << "������� ��� ����������" << endl;
//    cin.getline(emp.name, 50);
//    cout << "������� �� ����������" << endl;
//    cin >> emp.salary;
//
//    file.write((char*)&emp, sizeof(emp));
//    file.close();
//    cout << "��������� ��������" << endl;
//}
//
//void showEmployee(const char* fileName)
//{
//    ifstream file(fileName, ios::binary);
//    if (!file)
//    {
//        cout << "������ �������� �����";
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
//        cout << "������ �������� �����";
//        return;
//    }
//    Employee emp;
//    int searchID;
//    cout << "������� id ��� ������" << endl;
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
//        cout << "������ �������� �����";
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
//        cout << "������� ������" << endl;
//    }
//    else
//    {
//        cout << "��������� �� ������" << endl;
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
        cout << "1 - �������� ����������" << endl;
        cout << "2 - �������� �����������" << endl;
        cout << "3 - ����� ����������� �� id" << endl;
        cout << "4 - �������� ����������� �� id" << endl;
        cout << "0 - �����" << endl;
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
            cout << "������� id ��� ��������" << endl;
            cin >> deleteID,
            removeEmployeeForID(fileName, deleteID);
            break;
        }
        case 0:
        {
            cout << "������ ��������� ���������" << endl;
            break;
        }
        default: {
            cout << "������������ ����" << endl;
        }
        }
    }
    while (choice != 0);*/

    const char* fileName = "Order.dat";
    int choice;

    do
    {
        cout << "1 - �������� �����" << endl;
        cout << "2 - �������� ��� ������" << endl;
        cout << "3 - ������������� �����" << endl;
        cout << "0 - �����" << endl;
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
            cout << "������� id ��� ��������������" << endl;
            cin >> id;
            cout << "������� ����� �����" << endl;
            cin >> amount;
            reWritenOrder(fileName, id, amount);
            break;
        }
        case 0:
        {
            cout << "������ ��������� ���������" << endl;
            break;
        }
        default:
        {
            cout << "������������ ����" << endl;
        }
        }

        } 
    while (choice != 0);

    cout << endl;

    
}