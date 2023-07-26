#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
						
using namespace std;
void writeToFile(string name, string pwd) {
	string fileName = ".\\config.ini";
	string appName = "User Details";
	string key = name;
	string value = pwd;
	if (WritePrivateProfileStringA(appName.c_str(), key.c_str(), value.c_str(), fileName.c_str())) {
		cout << "User Added Successfully!.." << endl;
	}
	else {
		cout << "Failed to Add Data...." << endl;
	}
}



class Login {
private:
		static Login* Instance;
		string userName,password;
		Login() {
			userName = " ";
			password = " ";
		}
	public:
		static Login* getInstance() {
			if (Instance == NULL) {
				Instance = new Login();
			}
			return Instance;
		}
		void setUserName(string name,string pwd) {
			userName = name;
			password = pwd;
		}
		int validateUser() {
			string fileName = ".\\config.ini";
			string appName = "User Details";
			char res[100];
			string key = userName;
			if (GetPrivateProfileStringA(appName.c_str(), key.c_str(), " ", res, sizeof(res), fileName.c_str())) {
				if (res == password) {
					cout << "Login Successfully!..." << endl;
					return 1;
				}
				else {
					cout << "Invalid data....." << endl;
					return 0;
				}
			}
			else {
				cout << "Faild to search Uername " << endl;
				return 0;
			}
			return 0;


		}
		void createProfile() 
		{
			    string mob_num, address;
				cout << "Enter your Mobile Number : " << endl;
				cin >> mob_num;
				cout << "Enter your Address : " << endl;
				cin >> address;
				string fileName = ".\\config.ini";
				string appName = userName;
				string key = "Mobile";
				string value = mob_num;
				WritePrivateProfileStringA(appName.c_str(), key.c_str(), value.c_str(), fileName.c_str());
				appName = userName;
				key = "Address";
				value = address;
				WritePrivateProfileStringA(appName.c_str(), key.c_str(), value.c_str(), fileName.c_str());
				cout << "Profile created Successfully!.." << endl;
		}
		void editProfile() 
		{
			string editData, editValue;
			cout << "What Data you want to Edit : " << endl;
			cin >> editData;
			cout << "Enter the new " << editData << " Value : " << endl;
			cin >> editValue;
			string fileName = ".\\config.ini";
			string appName = userName;
			string key = editData;
			string value = editValue;
			WritePrivateProfileStringA(appName.c_str(), key.c_str(), value.c_str(), fileName.c_str());
			cout << "Data Edited Succesfully!..." << endl;
		}
};



class Users 
{
private:
	static Users* instance;
	string Name;
	string pwd;
	Users() 
	{
		Name = " ";
		pwd = " ";
	}
public:
	static Users* getInstance() {
		if (instance == NULL) {
			instance = new Users();
		}
		return instance;
	}
	void setData(string name, string age) {
		Name = name;
		pwd = age;
		writeToFile(Name, pwd);
	}
	void getData(string username) {
		string fileName = ".\\config.ini";
		string appName = username;
		char res[100];
		GetPrivateProfileSectionA(appName.c_str(), res, sizeof(res), fileName.c_str());
		cout << "Data retrived succedssfully!.." << endl;
		for (int i = 0; i < sizeof(res); i++) {
			if (res[i] < 0) {
				break;
			}
			if (res[i] == '\0') {
				cout << endl;
			}
			else {
				cout << res[i];
			}

		}
	}
	void getData() {
		string fileName = ".\\config.ini";
		string appName = "User Details";
		char res[100];
		GetPrivateProfileSectionA(appName.c_str(), res, sizeof(res), fileName.c_str());
		cout << "Data retrived succedssfully!.." << endl;
		for (int i = 0; i < sizeof(res); i++) {
			if (res[i] < 0) {
				break;
			}
			if (res[i] == '\0') {
				cout << endl;
			}
			else {
				cout << res[i];
			}
			
		}
		
	}
};



Users* Users::instance = NULL;
Login* Login::Instance = NULL;



void registerNewUser() {
	string username, password;
	cout << "****************************************" << endl;
	cout << "Enter user Name : " << endl;
	cin >> username;
	cout << "Enter the Password : " << endl;
	cin >> password;
//	Users* newUser = Users::getInstance();
	Users::getInstance()->setData(username, password);
}


void displayUsers() {
	//Users* user = Users::getInstance();
	Users::getInstance()->getData();
 }


void loginUser() {
	string username,password;
	int ch;
	cout << "Enter the User Name : " << endl;
	cin >> username;
	cout << "Enter the Password : " << endl;
	cin >> password;
	//Login* login = Login::getInstance();
	Login::getInstance()->setUserName(username,password);
	int status = Login::getInstance()->validateUser();
	string op;
	if (status == 1) {
		do {
			cout << "****************************************" << endl;
			cout << "What do you want to perform : " << endl;
			cout << "1. create Profile " << endl;
			cout << "2. Edit profile" << endl;
			cout << "3.Display Profile" << endl;
			cout << "****************************************" << endl;
			cout << "Enter your choice : " << endl;
			cin >> ch;
			switch (ch) {
			case 1:
				Login::getInstance()->createProfile();
				break;
			case 2:
				Login::getInstance()->editProfile();
				break;
			case 3:
				//Users* user = Users::getInstance();
				Users::getInstance()->getData(username);
				break;
			}
			cout << "Do you want to go main menu : " << endl;
			cin >> op;
		} while (op == "no");
		
	}
	
}


int main()
{
	int ch;
	string op;
	
	do {
		cout << "****************************************" << endl;
		cout << "1. Register New User" << endl;
		cout << "2.Login existing user" << endl;
		cout << "3. Display all the users" << endl;
		cout << "****************************************" << endl;
		cout << "Enter your choice : " << endl;
		cin >> ch;
		switch (ch) {
		case 1:
			registerNewUser();
			break;
		case 2:
			loginUser();
			break;
		case 3:
			displayUsers();
			break;
		}
		cout << "Do You Want to Cotinue : " << endl;
		cin >> op;
	} while (op == "yes");

	system("pause");
}



/*  
    map<string, string> getData(string username) {
        string fileName = ".\\config.ini";
        string appName = username;
        char res[100];
        GetPrivateProfileSectionA(appName.c_str(), res, sizeof(res), fileName.c_str());

        map<string, string> dataMap;
        string currentKey, currentValue;
        for (int i = 0; i < sizeof(res); i++) {
            if (res[i] < 0) {
                break;
            }
            if (res[i] == '=') {
                currentKey = currentValue;
                currentValue = "";
            }
            else if (res[i] == '\0') {
                dataMap[currentKey] = currentValue;
                currentKey = "";
                currentValue = "";
            }
            else {
                currentValue += res[i];
            }
        }

        cout << "Data retrieved successfully!.." << endl;
        return dataMap;
		}  */