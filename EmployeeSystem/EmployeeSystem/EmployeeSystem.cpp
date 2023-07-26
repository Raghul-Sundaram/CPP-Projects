#include "stdafx.h"
#include<iostream>
#include<map>
#include<vector>
#include<list>
#include<string>
using namespace std;



class Employee {
private:
	string emp_id, emp_name, emp_age, emp_no;
	vector<string> data;
	map<string, vector<string>> Emp_data;



public:
	void addEmployee(string id, string name, string age, string no) {
		emp_id = id;
		emp_name = name;
		emp_age = age;
		emp_no = no;
		data.push_back(emp_name);
		data.push_back(emp_age);
		data.push_back(emp_no);
		Emp_data.insert(pair<string, vector<string>>(emp_id, data));
		data.clear();

	}
	void deleteemp(string key) {
		Emp_data.erase(key);
	}
	void editdetail() {
		string edit_id, edit_item;
		int ch;
		cout << "Enter the Employee Id to edit Information" << endl;
		cin >> edit_id;
		cout << "What Do you want to change in this Id " << edit_id << endl;
		cout << "1. Name\n2. Age\n3. Number" << endl;
		cin >> ch;
		map<string, vector<string>>::iterator it = Emp_data.begin();
		switch (ch) {
		case 1:
			cout << "Enter the New Name : " << endl;
			cin >> edit_item;

			while (it != Emp_data.end()) {
				if (it->first == edit_id) {
					it->second[0] = edit_item;
				}
				it++;
			}
			cout << "Edited Successfully" << endl;
			showemployees();
			break;
		case 2:
			cout << "Enter the New Age : " << endl;
			cin >> edit_item;

			while (it != Emp_data.end()) {
				if (it->first == edit_id) {
					it->second[1] = edit_item;
				}
				it++;
			}
			cout << "Edited Successfully" << endl;
			showemployees();
			break;
		case 3:
			cout << "Enter the New Number : " << endl;
			cin >> edit_item;

			while (it != Emp_data.end()) {
				if (it->first == edit_id) {
					it->second[2] = edit_item;
				}
				it++;
			}
			cout << "Edited Successfully" << endl;
			showemployees();
			break;
		default:
			cout << "Invalid OPTION :" << endl;

		}
	}
	void showemployees() {

		map<string, vector<string>>::iterator it = Emp_data.begin();
		cout << "EMP_ID NAME AGE NUMBER" << endl;
		cout << "----------------" << endl;
		while (it != Emp_data.end()) {
			cout << it->first << " ";
			for (string i : it->second) {
				cout << i << " ";
			}
			cout << endl;
			it++;
		}
		cout << endl;
		cout << "----------------" << endl;
	}


};
void showmenu() {
	cout << "Employee Details" << endl;
	cout << "----------------" << endl;
	cout << "1. Add Employee" << endl;
	cout << "2. Edit Information" << endl;
	cout << "3. Delete Employee" << endl;
	cout << "4. Display All the Employee" << endl;
	cout << "----------------" << endl;
}

int main() {


	string id, name, age, no, ch, key;
	int op;
	Employee emp;

	do {
		showmenu();
		cout << "Enter the option" << endl;
		cin >> op;
		switch (op) {
		case 1:
			cout << "Enter Employee id : " << endl;
			cin >> id;
			cout << "Enter Employee name : " << endl;
			cin >> name;
			cout << "Enter Employee Age : " << endl;
			cin >> age;
			cout << "Enter Employee Mobile Number : " << endl;
			cin >> no;
			emp.addEmployee(id, name, age, no);
			break;
		case 2:
			emp.editdetail();
			break;
		case 3:
			cout << "Enter the Employee Id to Delete" << endl;
			cin >> key;
			emp.deleteemp(key);
		case 4:
			emp.showemployees();
			break;
		default:
			cout << "Invalid option" << endl;

		}
		cout << "Do you want to continue : " << endl;
		cin >> ch;
	} while (ch == "yes");



	system("pause");

}
