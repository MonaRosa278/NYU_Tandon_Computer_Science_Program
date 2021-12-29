
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Employee {
public:
    string name;
    int id;
    float hourlyPayRate;
    float totalPay;
    Employee(int id1, float hourlyPayRate1, string name1) {
        id = id1;
        hourlyPayRate = hourlyPayRate1;
        totalPay = 0;
        name = name1;
    }
    Employee() {
        totalPay = 0;
    }
};
struct NODE {
    Employee emp;
    NODE* next;
    NODE* prev;
 };
struct LIST {
    NODE* head = NULL;
    NODE* rear = NULL;
};
bool isEmpty(LIST &l){
    return (l.head == NULL);
}
void printListH2R(LIST& l) {
    NODE* cur = l.head;
    if (isEmpty(l)) {
        cout << "the list is empty" << endl;
        return;
    }
    cout << "******Payroll Information******" << endl;
    while (cur != NULL) {
        cout << cur->emp.name<<", $"<<cur->emp.totalPay<<endl;
        cur = cur->next;
    }
    cout << "******End of Payroll******" << endl;
}
NODE* findEmpById(LIST& l, int id) {
    NODE* cur = l.rear;
    if (isEmpty(l)) {
        return NULL;
    }
    while (cur != NULL) {
        if (cur->emp.id == id) {
            return cur;
        }
        cur = cur->prev;
    }
    return NULL;
}
void insertElement(LIST& l, Employee emp) {
    NODE* cur;
    NODE* tmp = new NODE;
    if (tmp == NULL)
        exit(1);
    tmp->emp = emp;
    tmp->next = NULL;
    tmp->prev = NULL;
    if (isEmpty(l)) {
        l.head = tmp;
        l.rear = tmp;
        return;
    }
    //insertion at head
    if (emp.totalPay >= l.head->emp.totalPay) {
        tmp->next = l.head;
        l.head->prev = tmp;
        l.head = tmp;
        return;
    }
    //insertion at rear
    if (emp.totalPay <= l.rear->emp.totalPay) {
        tmp->prev = l.rear;
        l.rear->next = tmp;
        l.rear = tmp;
        return;
    }
    //general case
    cur = l.head;
    while (cur != NULL && cur->emp.totalPay > emp.totalPay) {
        cur = cur->next;
    }
    tmp->prev = cur->prev;
    tmp->next = cur;
    cur->prev->next = tmp;
    cur->prev = tmp;
}
void deleteElement(LIST& l, int id) {
    NODE* cur, * prev;
    //list empty
    if (isEmpty(l)) {
        return;
    }
    //delete head
    if (l.head->emp.id == id) {
        cur = l.head->next;
        delete l.head;
        l.head = cur;
        l.head->prev = NULL;
        return;
    }
    //delete rear
    if (l.rear->emp.id == id) {
        cur = l.rear->prev;
        delete l.rear;
        l.rear = cur;
        l.rear->next = NULL;
        return;
    }
    //delete other than head or rear
    cur = l.head;
    prev = NULL;
    while (cur != NULL && cur->emp.id != id) {
        prev = cur;
        cur = cur->next;
    }
    //if does not exist
    if (cur == NULL) {
        return;
    }
    prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
}
int main()
{
    ifstream employeeData, payrollData;
    char c;
    string name = "", empname;
    int id;
    float hourlyPayRate;
    string source1, source2;
    LIST listOfEmployees;
    employeeData.open("emps.txt");
    if (employeeData.fail()) {
        cout << "Could not find emps.txt. Exiting program" << endl;
        exit(1);
    }
    payrollData.open("hours.txt");
    if (payrollData.fail()) {
        cout << "Could not find hours.txt. Exiting program" << endl;
        exit(1);
    }

    
    while (!employeeData.eof()) {
        while (employeeData.get(c)) {
            if (!isblank(c)) {
                name += c;
            }
            else {
                id = stoi(name);
                name = "";
                break;
            }
        }
        while (employeeData.get(c)) {
            if (!isblank(c)) {
                name += c;
            }
            else {
                hourlyPayRate = stof(name);
                name = "";
                break;
            }
        }
        while (employeeData.get(c)) {
            if (!isdigit(c)) {
                name += c;
            }
            else {
                empname = name;
                name = c;
                break;
            }
        }
        if (employeeData.eof()) {
            empname = name;
        }
        Employee* e = new Employee(id, hourlyPayRate, empname);
        insertElement(listOfEmployees, *e);
    }
    int nbOfHours;
    while (payrollData >> id >> nbOfHours) {
        NODE* e1 = findEmpById(listOfEmployees, id);
        if (e1 == NULL) {
            cout << "Employee with ID: " << id << " not found." << endl;
            continue;
        }
        Employee e = e1->emp;
        e.totalPay += nbOfHours * e.hourlyPayRate;
        deleteElement(listOfEmployees, e.id);
        insertElement(listOfEmployees, e);
    }
    printListH2R(listOfEmployees);
}