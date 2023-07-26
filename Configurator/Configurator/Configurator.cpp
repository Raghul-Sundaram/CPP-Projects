// Configurator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <string>
#include <iostream>
#include<map> 
#include<vector>
using namespace std;

static int noOfEmployee = 0;
class Employee {
private :
	string emp_id;
	string name;
public:
	Employee() {
		cout << "New Employee Register Successfully!..." << endl;
	}
	Employee(string id, string s ) {
		emp_id = id;
		name = s;
	}
	void parseINI() {
		string Appname,Key, filename;
		filename = ".\\Employee.ini";
		Appname = "Employee Details";
		string Value = name;
		Key = emp_id;
		WritePrivateProfileStringA(Appname.c_str(), Key.c_str(), Value.c_str(), filename.c_str());
	}
	void display() {
		char ans[100];
		GetPrivateProfileStringA("Employee", "NoOfEmployees", " ", ans, sizeof(ans), ".\\Employee.ini");
		if (!strlen(ans)) cout << "No Employees found!";
		else {
			cout << "Employee ID " << "    " << "Name" << endl;
			for (int i = 1; i < stoi(ans); i++) {
				cout << i << "               ";
				char name[10];
				GetPrivateProfileStringA("Employee Details", to_string(i).c_str(), " ", name, sizeof(name), ".\\Employee.ini");
				cout << name << endl;
			}
		}
		
	}
};
class CreateEmployee {
private:
	string id;
	string name;
	string ch;
	vector<string> det;
public:
	void newEmp() {

			cout << "Enter the Employee Id : " << endl;
			cin >> id;
			cout << "Enter the Employee name : " << endl;
			cin >> name;
			Employee newEmployee(id, name);
			newEmployee.parseINI();
			det.clear();
	}
};
class Settings {
private :
	string emp_id;
public:
	void addPersonalDetails(string id) {
		emp_id = id;
		string age, ph_num, address;
		cout << "Enter your Age : " << endl;
		cin >> age;
		cout << "Enter your Mobile Number : " << endl;
		cin >> ph_num;
		cout << "Enter your Address : " << endl;
		cin >> address;
		string Appname, Key, Value, filename;
		filename = ".\\personaldetails.ini";
		Appname = emp_id;
		Key = "Age";
		Value = age;
		WritePrivateProfileStringA(Appname.c_str(), Key.c_str(), Value.c_str(), filename.c_str());
		Key = "Mobile";
		Value = ph_num;
		WritePrivateProfileStringA(Appname.c_str(), Key.c_str(), Value.c_str(), filename.c_str());
		Key = "Address";
		Value = address;
		WritePrivateProfileStringA(Appname.c_str(), Key.c_str(), Value.c_str(), filename.c_str());
		cout << "Details Added Successfully" << endl;
	}
	void deleteEmployee(string id) {
		emp_id = id;
		string Appname, Key, Value, filename;
		filename = ".\\Employee.ini";
		Appname = "Employee Details";
		Key = emp_id;
		Value = "Deleted";
		WritePrivateProfileStringA(Appname.c_str(), Key.c_str(), Value.c_str(), filename.c_str());
		filename = ".\\personaldetails.ini";
		Appname =emp_id;
		WritePrivateProfileStringA(Appname.c_str(),NULL,NULL, filename.c_str());
		cout << "Profile deleted successfully !..." << endl;
		noOfEmployee--;

	}
	void viewProfile(string id) {
		emp_id = id;
		vector<string> dtd{ "Age","Mobile","Address" };
		for (int i = 0; i < 3; i++) {
			cout << dtd.at(i) << "    ";
			char name[10];
			GetPrivateProfileStringA(emp_id.c_str(), dtd.at(i).c_str(), " ", name, sizeof(name), ".\\personaldetails.ini");
			cout << name << endl;
		}

	}
	void EditDetails(string id) {
		emp_id = id;
		int op;
		string newage, newnumber, newaddress;
		string Appname, Key, Value, filename;
		cout << "*************************************" << endl;
		cout << "1. Age " << endl;
		cout << "2.Mobile Number " << endl;
		cout << "3. Address" << endl;
		cout << "*************************************" << endl;
		cout << "Which Detail You are going to Edit : " << endl;
		cin >> op;
		switch (op) {
		case 1:
			cout << "Enter the new age : " << endl;
			cin >> newage;
			filename = ".\\personaldetails.ini";
			Appname = emp_id;
			Key = "Age";
			Value = newage;
			WritePrivateProfileStringA(Appname.c_str(), Key.c_str(), Value.c_str(), filename.c_str());
			break;
		case 2:
			cout << "Enter the new Number : " << endl;
			cin >> newnumber;
			filename = ".\\personaldetails.ini";
			Appname = emp_id;
			Key = "Mobile";
			Value = newnumber;
			WritePrivateProfileStringA(Appname.c_str(), Key.c_str(), Value.c_str(), filename.c_str());
			break;
		case 3:
			cout << "Enter the new Address : " << endl;
			cin >> newaddress;
			filename = ".\\personaldetails.ini";
			Appname = emp_id;
			Key = "Address";
			Value = newaddress;
			WritePrivateProfileStringA(Appname.c_str(), Key.c_str(), Value.c_str(), filename.c_str());
			break;
	}


	}
};
class Login {
private:
	string name, emp_id;
public:
	Login() {}
	Login(string id) {
		emp_id = id;
	}
	void ValidateEmployee() {
		string Appname, Key,filename;
		char ans[100];
		Appname = "Employee Details";
		filename = ".\\Employee.ini";
		Key = emp_id;
		GetPrivateProfileStringA(Appname.c_str(), Key.c_str(), " " ,ans, sizeof(ans), filename.c_str());
		cout << "Welcome : " << ans << endl;
		cout << "Login Sucessfully!...." << endl;
	}
	void setting() {
		int op;
		string ch;
		Settings setting;
		do {
			cout << "******Profile Settings*****" << endl;
			cout << "1. Add Personal Details" << endl;
			cout << "2. Delete My Profile " << endl;
			cout << "3. Edit Personal Details" << endl;
			cout << "4. view Personal Details" << endl;
			cout << "****************************" << endl;
			cout << "Enter your choice : " << endl;
			cin >> op;
			switch (op) {
			case 1:
				setting.addPersonalDetails(emp_id);
				break;
			case 2:
				setting.deleteEmployee(emp_id);
				break;
			case 3:
				setting.EditDetails(emp_id);
				break;
			case 4:
				setting.viewProfile(emp_id);
				break;
			default:
				return;

			}
			cout << "Do you want to go Settings menu : " << endl;
			cin >> ch;
		} while (ch == "yes");

	}
};

int main()
{
	string id;
	string num;
	string name;
	string ch;
	Employee base;
	int op;
	do{
		cout << "*************************************" << endl;
		cout << "1. Register New Employee " << endl;
		cout << "2. Display all Employees " << endl;
		cout << "3. Login Existing Employee " << endl;
		cout << "*************************************" << endl;
		cout << " Enter your Operation : " << endl;
		cin >> op;
		CreateEmployee newEmp;
		string Appname, Key, filename, value, back;
		char ans[100];
		GetPrivateProfileStringA("Employee", "NoOfEmployees", " ", ans, sizeof(ans), ".\\Employee.ini");
		if (!strlen(ans)) noOfEmployee = 0;
		else
		noOfEmployee = stoi(ans);
		WritePrivateProfileStringA("Employee", "NoOfEmployees",to_string( noOfEmployee).c_str(), ".\\Employee.ini");
		switch (op) {
		case 1:
			do {
				newEmp.newEmp();
				noOfEmployee++;
				cout << "Do you want to add one more Employee : " << endl;
				cin >> back;
			} while (back == "yes");
			WritePrivateProfileStringA("Employee", "NoOfEmployees", to_string(noOfEmployee).c_str(), ".\\Employee.ini");
			break;
		case 2:
			base.display();
			break;
		case 3:
			cout << "Enter your Employee Id : " << endl;
			cin >> id;
			Login login(id);
			login.ValidateEmployee();
			login.setting();
			break;
		
		}
		cout << "Do you want to Go to Menu : " << endl;
		cin >> ch;
	} while (ch == "yes");
	
	system("pause");
}

