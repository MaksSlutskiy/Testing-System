#include "Header.h"
string CheckSymbols(string str)			//функции проверки ввода
{
	string Invalid;
	for (int i = 0; i<str.length(); i++)
	{
		if (i == 0)
		{
			if (str[i]<65 || str[i]>90)
				Invalid.push_back(str[i]);
		}
		else
		{
			if (str[i] < 97 || str[i]>122)
				Invalid.push_back(str[i]);
		}
	}
	if (!Invalid.empty())
		return Invalid;
	else
		return "0";
}
string CheckNumbers(string str)
{
	string Invalid;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i]<48 || str[i]>57)
			Invalid.push_back(str[i]);
	}
	if (!Invalid.empty())
		return Invalid;
	else
		return "0";
}
void CheckSize()
{
		SetColorBgTex(0, 4);
		cursor_to(40, 16);
		cout << "character limit exceeded(no more than 20)" << endl;
		Sleep(2000);
		SetColorBgTex(0, 0);
		cursor_to(40, 16);
		cout << "character limit exceeded(no more than 20)" << endl;
}
string Encryption(string str)			//шифровка пароля и логина
{
	for (int i = str.size()-1; i >0; i--)
	{
		str[i]=str[i] + 20;
	}
	return str;
}
string DeEncryption(string str)       //дешифровка
{
	for (int i = str.size() - 1; i >0; i--)
	{
		str[i] = str[i] - 20;
	}
	return str;

}
void Starting::Registration()			//регистрация
{
	int cursor = 60;
	int ptr = 3;
	string name;
	string patronymic;
	string famil;
	string address;
	string phone;
	string login;
	string password;

	while (1)
	{
		SetColorBgTex(0, 14);
		cursor_to(cursor, ptr);
		cout << "Enter your name : ";
		getline(cin, name);

		if (CheckSymbols(name) != "0")			//ввод данных и проверка на правильность ввода
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr + 2);
			cout << "Invalid character: " << CheckSymbols(name) << endl;
			Sleep(2000);
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr);
			cout << "Enter your name : ";
			cout << name;
			cursor_to(cursor, ptr + 2);
			cout << "Invalid character: " << CheckSymbols(name) << endl;
		}
		else if (name.size() > 20)
		{
			CheckSize();
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr);
			cout << "Enter your name : ";
			cout << name;
		}
		else
			break;
	}
	while (1)
	{
		SetColorBgTex(0, 14);
		cursor_to(cursor, ptr + 2);
		cout << "Enter your patronymic : ";
		getline(cin, patronymic);
		if (CheckSymbols(patronymic) != "0")
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr + 4);
			cout << "Invalid character: " << CheckSymbols(patronymic) << endl;
			Sleep(2000);
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr+2);
			cout << "Enter your patronymic : ";
			cout << patronymic;
			cursor_to(cursor, ptr + 4);
			cout << "Invalid character: " << CheckSymbols(patronymic) << endl;
		}
		else if (patronymic.size() > 20)
		{
			CheckSize();
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 2);
			cout << "Enter your patronymic : ";
			cout << patronymic;
		}
		else
			break;
	}
	while (1)
	{
		SetColorBgTex(0, 14);
		cursor_to(cursor, ptr + 4);
		cout << "Enter your famil : ";
		getline(cin, famil);
		if (CheckSymbols(famil) != "0")
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr + 6);
			cout << "Invalid character: " << CheckSymbols(famil) << endl;
			Sleep(2000);
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr+4);
			cout <<"Enter your famil : ";
			cout << famil;
			cursor_to(cursor, ptr + 6);
			cout << "Invalid character: " << CheckSymbols(famil) << endl;
		}
		else if (famil.size() > 20)
		{
			CheckSize();
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 4);
			cout << "Enter your famil : ";
			cout << famil;
		}
			
		else
			break;
	}
	while (1)
	{
		SetColorBgTex(0, 14);
		cursor_to(cursor, ptr + 6);
		cout << "Enter your address(City) : ";
		getline(cin, address);
		if (CheckSymbols(address) != "0")
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr + 8);
			cout << "Invalid character: " << CheckSymbols(address) << endl;
			Sleep(2000);
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 6);
			cout << "Enter your address(City) : ";
			cout << address;
			cursor_to(cursor, ptr + 8);
			cout << "Invalid character: " << CheckSymbols(address) << endl;
		}
		else if (address.size() > 20)
		{
			CheckSize();
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 6);
			cout << "Enter your address(City) : ";
			cout << address;
		}
		else
			break;
	}
	while (1)
	{
		SetColorBgTex(0, 14);
		cursor_to(cursor, ptr + 8);
		cout << "Enter your phone : ";
		getline(cin, phone);
		if (CheckNumbers(phone) != "0")
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr + 10);
			cout << "Invalid character(must be only numbers): " << CheckNumbers(phone) << endl;
			Sleep(2000);
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 8);
			cout << "Enter your phone : ";
			cout << phone;
			cursor_to(cursor, ptr + 10);
			cout << "Invalid character(must be only numbers): " << CheckNumbers(phone) << endl;
		}
		else if (phone.size()<9)
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr + 12);
			cout << "Phone must have at least 9 characters" << endl;
			Sleep(2000);
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 8);
			cout << "Enter your phone : ";
			cout << phone;
			cursor_to(cursor, ptr + 12);
			cout << "Phone must have at least 9 characters" << endl;
		}
		else if (phone.size() > 20)
		{
			CheckSize();
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 8);
			cout << "Enter your phone : ";
			cout << phone;
		}
		else
			break;
	}
	while (1)
	{
		SetColorBgTex(0, 14);
		cursor_to(cursor, ptr + 10);
		cout << "Enter your login : ";
		getline(cin, login);
		if (login.size()<4)
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr + 12);
			cout << "login must have at least 8 characters"<< endl;
			Sleep(2000);
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr+ 10);
			cout << "Enter your login : ";
			cout << login;
			cursor_to(cursor, ptr + 12);
			cout << "login must have at least 8 characters" << endl;
		}
		else if (login.size() > 20)
		{
			CheckSize();
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 10);
			cout << "Enter your login : ";
			cout << login;
		}
		else
		{
			break;
		}
	}
	while (1)
	{
		SetColorBgTex(0, 14);
		cursor_to(cursor, ptr + 12);
		cout << "Enter your password : ";
		getline(cin, password);
		if (password.size()<4)
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr + 14);
			cout << "Password must have at least 8 characters" << endl;
			Sleep(2000);
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 12);
			cout << "Enter your password : ";
			cout << password;
			cursor_to(cursor, ptr + 14);
			cout << "Password must have at least 8 characters" << endl;
		}
		else if (password.size() > 20)
		{
			CheckSize();
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 12);
			cout << "Enter your password : ";
			cout << password;
		}
		else
		{
			break;
		}
	}
	
	Student newStudent;  
	newStudent.AddStudent(name, patronymic, famil, address, phone, Encryption(login), Encryption(password));
	student.push_back(newStudent); //пользователь добавляеться в список 

	int ptr2 = 3;
	SetColorBgTex(0, 0);
	while (ptr2 != ptr+14)
	{
		cursor_to(cursor, ptr2);
		cout << "---------------------------------------------------------------";
		ptr2 += 2;
	}
	
	SetColorBgTex(0, 13);
	cursor_to(cursor, ptr);
	cout << "Your account is successfully registered!";
	Sleep(3000);
	SetColorBgTex(0, 0);
	cursor_to(cursor, ptr);
	cout << "Your account is successfully registered!" << endl;
}