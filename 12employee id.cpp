/*Company maintains employee information as employee ID, name, designation and salary. Allow user
to add, delete information of employee. Display information of particular employee. If employee does
not exist an appropriate message is displayed. If it is, then the system displays the employee details.
Use index sequential file to maintain the data.*/

#include <bits/stdc++.h>
#define max 20
using namespace std;
struct employee {
string name;
long int code;
string designation;
int exp;
int age, salary;
};

int num;
void showMenu();
employee emp[max], tempemp [max], sortemp[max], sortemp1[max];
void build() {
cout << "Build The Table\n";
cout << "Maximum Entries can be " << max << "\n";
cout << "Enter the number of "<< "Entries required: ";
cin >> num;
if (num > 20) {
cout << "Maximum number of" << "Entries are 20 \n";
num = 20;
}
cout << "Enter the following data:\n";
for (int i = 0; i < num; i++) {
cout << "Name: ";
cin >> emp[i].name;
cout << "Employee ID: ";
cin >> emp[i].code;
cout << "Designation: ";
cin >> emp[i].designation;
cout << "Experience: ";
cin >> emp[i].exp;
cout << "Age: ";
cin >> emp[i].age;
cout << "Salary: ";
cin >> emp[i].salary;
cout<<"\n\n";
}
showMenu();
}

void insert() {
if (num < max) {
int i = num;
num++;
cout << "Enter the information "
<< "of the Employee\n";
cout << "Name";
cin >> emp[i].name;
cout << "Employee ID ";
cin >> emp[i].code;
cout << "Designation ";
cin >> emp[i].designation;
cout << "Experience";
cin >> emp[i].exp;
cout << "Age ";
cin >> emp[i].age;
cout << "Salary ";
cin >> emp[i].salary;
} else {
cout << "Employee Table Full\n";
}
showMenu();
}

void deleteIndex(int i) {
for (int j = i; j < num - 1; j++) {
emp[j].name = emp[j + 1].name;
emp[j].code = emp[j + 1].code;
emp[j].designation = emp[j + 1].designation;
emp[j].exp = emp[j + 1].exp;
emp[j].age = emp[j + 1].age;
emp[j].salary = emp[j + 1].salary;
}
return;
}
void deleteRecord() {
cout << "Enter the Employee ID to Delete Record";
int code;
cin >> code;
for (int i = 0; i < num; i++) {
if (emp[i].code == code) {
deleteIndex(i);
num--;
break;
}
}
showMenu();
}

void searchRecord() {
cout << "Enter the Employee ID to Search Record";
int code;
cin >> code;
for (int i = 0; i < num; i++) {
if (emp[i].code == code) {
cout << "Name" << emp[i].name << "\n";
cout << "Employee ID "<< emp[i].code << "\n";
cout << "Designation "<<emp[i].designation << "\n";
cout << "Experience"<< emp[i].exp << "\n";
cout << "Age"<< emp[i].age << "\n";
cout << "Salary "<<emp[i].salary << "\n";
break;
}
}
showMenu();
}

void showMenu() {
cout <<"-----------------" << "Employee Management System" <<"------------------\n\n";
cout << "Available Options:\n\n";
cout << "Build Table (1)\n";
cout << "Insert New Entry (2)\n";
cout << "Delete Entry (3)\n";
cout << "Search a Record (4)\n";
cout << "Exit (5)\n";
int option;
cout<<"Enter Selected Option:";
cin >> option;
if (option == 1) {
build();
} else if (option == 2) {
insert();
} else if (option == 3) {
deleteRecord();
} else if (option == 4) {
searchRecord();
} else if (option ==5) {
return;
}
else {
cout << "Expected Options are 1/2/3/4/5";
showMenu();
}
cout<<"Thank You!";
}
int main()
{
showMenu();
return 0;
}
