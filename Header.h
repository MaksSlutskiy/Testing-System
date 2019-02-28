#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>
#include <conio.h>
#include<fstream>
#include <vector>
#include<list>
#include <algorithm>
using namespace std;
void SetConsWinSize(int XSize, int YSize);
void SetColorBgTex(int Bg, int Tex);
void cursor_to(SHORT xPos, SHORT yPos);
void Mainmenu();
string CheckSymbols(string str);
string CheckNumbers(string str);   //функии для проверки ввода пользователя
void CheckSize();
string Encryption(string str);
string DeEncryption(string str);

class Questions  //класс вопросов и ответов (решил все сделать в паблик чтобы сразу получать доступ через вектор)
{
public:
	string questions;
	string answer1;
	string answer2;
	string answer3;
	string answer4;
	string answer5;
	string answer6;
	int correctanswer;
	Questions()
	{
		questions = "no";
		answer1 = "no";
		answer2 = "no";
		answer3 = "no";
		answer4 = "no";
		answer5 = "no";
		answer6 = "no";
	}
	void DelQuestions()
	{
		questions = "no";
		answer1 = "no";
		answer2 = "no";
		answer3 = "no";
		answer4 = "no";
		answer5 = "no";
		answer6 = "no";
	}

};
class Student		//класс студент используеться в списке всех студентов и при регистрации
{
public:
	string name;
	string patronymic;
	string famil;
	string address;
	string phone;
	string login;
	string password;
	Student()
	{
		name = "noname";
		patronymic = "nopatronymic";
		famil = "nofamil";
		address = "noaddress";
		phone = "nophone";
		login = "nologin";
		password = "nopassword";
	}
	void AddStudent(string name, string patronymic, string famil,
		string address, string phone, string login, string password)
	{
		this->name = name;
		this->patronymic = patronymic;
		this->famil = famil;
		this->address = address;
		this->phone = phone;
		this->login = login;
		this->password = password;


	}
};

class Starting   //основной класс всего проекта
{
	list<Student> student;
	vector<string> section;			
	vector<string> Nametest;
	vector<Questions> BeginTest;
	vector<int>asses;
	Questions FileTest;
	string namesection;
	Student mas;
	string name;
	string patronymic;
	string famil;
	string address;
	string phone;
	string login;
	string password;
	string nametest;
	int check;
	int check2 = 0;
public:
	Starting()			//конструктор считывает всех пользователей с файла
	{
		ifstream fin("Student");
		int sum = 0;
		while (!fin.eof())
		{
			if(sum==0)
			getline(fin, name);
			if (sum == 1)
			getline(fin, patronymic);
			if (sum == 2)
			getline(fin, famil);
			if (sum == 3)
			getline(fin, address);
			if (sum == 4)
			getline(fin, phone);
			if (sum == 5)
			getline(fin, login);
			if (sum == 6)
			getline(fin, password);
			sum++;
			if (sum == 7)
			{
				mas.AddStudent(name, patronymic, famil, address, phone, login, password);
				student.push_back(mas);
				sum = 0;
			}
			
		}
		fin.close();

		ifstream fin2("Section"); // считывает все секции
		char name[50];
		fin2.getline(name, 50);
		while (!fin2.eof())
		{
			section.push_back(name);
			fin2.getline(name, 50);

		}
		fin2.close();

	}
	void Namesection()  //метод для открытия теста в зависимости от выбора секции пользователем
	{
		ifstream fin3(namesection);
		if (!fin3)
		{
			check = 1;
		}
		else
		{ 
			while (!fin3.eof())
			{
				char name[100];
				fin3.getline(name, 100);
				Nametest.push_back(name);
			}
		}
		fin3.close();
	}
	void Registration();
	void Autorization();
	void Areamenu();
	void Section();
	void Test();
	void StartQuestions();
	void TestMenu();
	void History();

	void AdminMenu();
	void UserManagement();
	void DeleteUser();
	void AllUsers();

	void TestManagement();
	void AddSection();
	void AddTest();
	void AddTest2();
	void AddQuestion();
	void AddQuestion2();
	void SaveQuestion();
	void Statistics();
	void UnfinishedTests();

	void TheEnd()   //перезапись файлов для обновления информации 
	{
		remove("Student");
		ofstream fout;
		fout.open("Student", ios::app, ios::binary);
		for (list<Student> ::iterator it = student.begin(); it != student.end(); ++it)
		{
			fout << it->name << endl;
			fout << it->patronymic << endl;
			fout << it->famil << endl;
			fout << it->address << endl;
			fout << it->phone << endl;
			fout << it->login << endl;
			fout << it->password << endl;
		}
		fout.close();

		remove("Section");
		ofstream fin2;
		fin2.open("Section", ios::app, ios::binary);
		for (int i = 0; i<section.size(); i++)
		{
			if (i == section.size() + 1)
				fin2 << section[i];
			else
			fin2 << section[i] << endl;
		}
		fin2.close();

	}
	
};

