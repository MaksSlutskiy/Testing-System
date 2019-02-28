#include "Header.h"

// метод для меню админа
void Starting::AdminMenu()
{
	_getch();
	int color1 = 14;
	int cursor = 3;
	int cursor2 = 3;
	int sum = 0;
	vector<string> menu;
	string name1 = "User Management";
	string name2 = "Test Management";
	string name3 = "Statistics";
	menu.push_back(name1);
	menu.push_back(name2);
	menu.push_back(name3);
	int j = 0;
	while (1)
	{
		SetColorBgTex(0, 14);
		for (int i = 0; i < menu.size(); i++)
		{
			cursor_to(20, cursor);
			cout << menu[i];
			cursor += 2;
		}
		cursor = 3;
		for (; j < menu.size(); j++)
		{
			SetColorBgTex(0, 4);
			cursor_to(20, cursor2);
			cout << menu[j];


			int Input;
			Input = _getch();
			if (Input == 13)
			{
				if (j == 0)
				{
					UserManagement();
				}
				if (j == 1)
				{
					
					TestManagement();
				}
				if (j == 2)
				{
					Statistics();
					
				}

			}
			if (Input == 27)
			{
				SetColorBgTex(0, 0);
				cursor_to(20, cursor);
				printf("User Management");
				cursor_to(20, cursor + 2);
				printf("Test Management");
				cursor_to(20, cursor + 4);
				printf("Statistics");
				sum = 2;
				break;
			}
			Input = _getch();
			if (Input == 80)
			{
				if (j < menu.size() - 1)
				{
					j++;
					cursor2 += 2;

				}
				break;

			}
			if (Input == 72)
			{
				if (j > 0)
				{
					j--;
					cursor2 -= 2;
				}
				break;

			}
			break;
		}
		if (sum == 2)
		{
			break;
			sum = 0;
		}
	}
}
// метод для меню админа - работа с пользователсями
void Starting::UserManagement()
{
	_getch();
	int color1 = 14;
	int cursor = 3;
	int cursor2 = 3;
	int sum = 0;
	vector<string> menu;
	string name1 = "Add User";
	string name2 = "Delete User";
	string name3 = "All User";
	menu.push_back(name1);
	menu.push_back(name2);
	menu.push_back(name3);
	int j = 0;
	while (1)
	{
		SetColorBgTex(0, 14);
		for (int i = 0; i < menu.size(); i++)
		{
			cursor_to(40, cursor);
			cout << menu[i];
			cursor += 2;
		}
		cursor = 3;
		for (; j < menu.size(); j++)
		{
			SetColorBgTex(0, 4);
			cursor_to(40, cursor2);
			cout << menu[j];


			int Input;
			Input = _getch();
			if (Input == 13)
			{
				if (j == 0)
				{
					Registration();
					
				}
				if (j == 1)
				{
					
					DeleteUser();
					

				}
				if (j == 2)
				{

					AllUsers();
				}

			}
			if (Input == 27)
			{
				SetColorBgTex(0, 0);
				cursor_to(40, cursor);
				printf("Add User");
				cursor_to(40, cursor + 2);
				printf("Delete User");
				cursor_to(40, cursor + 4);
				printf("All User");
				sum = 2;
				break;
			}
			Input = _getch();
			if (Input == 80)
			{
				if (j < menu.size() - 1)
				{
					j++;
					cursor2 += 2;

				}
				break;

			}
			if (Input == 72)
			{
				if (j > 0)
				{
					j--;
					cursor2 -= 2;
				}
				break;

			}
			break;
		}
		if (sum == 2)
		{
			break;
			sum = 0;
		}
	}
}
// удаление пользователя по фамилии
void Starting::DeleteUser()
{
	SetColorBgTex(0, 14);
	int cursor = 60;
	int ptr = 3;
	string del;
	while (1)
	{
		SetColorBgTex(0, 14);
		cursor_to(cursor, ptr + 4);
		cout << "Enter the student's Famil to remove: ";
		getline(cin, del);
		if (CheckSymbols(del) != "0")
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr + 6);
			cout << "Invalid character: " << CheckSymbols(del) << endl;
			Sleep(2000);
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 4);
			cout << "Enter the student's Famil to remove: ";
			cout << del;
			cursor_to(cursor, ptr + 6);
			cout << "Invalid character: " << CheckSymbols(del) << endl;
		}
		else if (del.size() > 20)
		{
			CheckSize();
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 4);
			cout << "Enter the student's Famil to remove: ";
			cout << del;
		}
		else
			break;
	}

	int sum = 0;
	for (list<Student> ::iterator it = student.begin(); it != student.end(); ++it)
	{
		
		if (del == it->famil)
		{
			it=student.erase(it);
			
			sum = 1;
			break;
		}
	}
	if (sum == 0)
	{
		SetColorBgTex(0, 4);
		cursor_to(cursor, ptr + 6);
		cout << "Famil not found!";
		Sleep(2000);
	}
	else
	{
		SetColorBgTex(0, 13);
		cursor_to(cursor, ptr + 6);
		cout << "User successfully deleted!";
		Sleep(2000);
	}
	SetColorBgTex(0, 0);
	cursor_to(cursor, ptr + 4);
	cout << "--------------------------------------------------------------------------";
	cursor_to(cursor, ptr + 6);
	cout << "--------------------------------------------------------------------------";
	
}
// вывод всех пользователей
void Starting::AllUsers()
{
	_getch();
	SetColorBgTex(0, 14);
	int cursor = 60;
	int ptr = 5;
	int sum = 0;
	int i = 0;
	for (list<Student> ::iterator it = student.begin(); it != student.end(); ++it)
	{
		cursor_to(cursor, ptr);
		cout <<"Name - "<< it->name;
		ptr += 2;
		cursor_to(cursor, ptr);
		cout << "Patronymic - " << it->patronymic; 
		ptr += 2;
		cursor_to(cursor, ptr);
		cout << "Famil - " << it->famil;
		ptr += 2;
		cursor_to(cursor, ptr);
		cout << "Address - " << it->address;
		ptr += 2;
		cursor_to(cursor, ptr);
		cout << "Phone - " << it->phone;
		ptr += 2;
		cursor_to(cursor, ptr);
		cout << "Login - " << DeEncryption(it->login);
		ptr += 2;
		cursor_to(cursor, ptr);
		cout << "Password - " << DeEncryption (it->password);
		ptr += 2;
		cursor_to(cursor, ptr);
		cout << "__________________________";
		ptr += 2;
	}
	SetColorBgTex(0, 4);
	cursor_to(cursor, ptr);
	cout << "Input Esc to exit";
	int Input;
	Input = _getch();
	SetColorBgTex(0, 0);
	cursor_to(cursor, ptr);
	cout << "Input Esc to exit";
	if (Input != 27)
	{
		SetColorBgTex(0, 4);
		cursor_to(cursor, ptr + 2);
		cout << "Wrong Input";
		Sleep(2000);
		cursor_to(cursor, ptr + 2);
		SetColorBgTex(0, 0);
		cout << "Wrong Input";
	}

	SetColorBgTex(0, 0);
	int ptr2 = 3;

	while (ptr2 != ptr)
	{
		cursor_to(cursor, ptr2);
		cout << "---------------------------------------------------------------";
		ptr2 += 2;
	}

}
// меню админа для работы с тестами
void Starting::TestManagement()
{
	_getch();
	int color1 = 14;
	int cursor = 3;
	int cursor2 = 3;
	int ptr = 40;
	int sum = 0;
	vector<string> menu;
	string name1 = "Add Section";
	string name2 = "Add Test";
	string name3 = "Fill Test";
	menu.push_back(name1);
	menu.push_back(name2);
	menu.push_back(name3);
	int j = 0;
	while (1)
	{
		SetColorBgTex(0, 14);
		for (int i = 0; i < menu.size(); i++)
		{
			cursor_to(ptr, cursor);
			cout << menu[i];
			cursor += 2;
		}
		cursor = 3;
		for (; j < menu.size(); j++)
		{
			SetColorBgTex(0, 4);
			cursor_to(ptr, cursor2);
			cout << menu[j];


			int Input;
			Input = _getch();
			if (Input == 13)
			{

				if (j == 0)
				{
					AddSection();
				}
				if (j == 1)
				{
					AddTest();

				}
				if (j == 2)
				{
					AddQuestion();

				}

			}
			if (Input == 27)
			{
				SetColorBgTex(0, 0);
				cursor_to(ptr, cursor);
				printf("Add Section");
				cursor_to(ptr, cursor + 2);
				printf("Add Test");
				cursor_to(ptr, cursor + 4);
				printf("Fill Test");
				sum = 2;
				break;
			}
			Input = _getch();
			if (Input == 80)
			{
				if (j < menu.size() - 1)
				{
					j++;
					cursor2 += 2;

				}
				break;

			}
			if (Input == 72)
			{
				if (j > 0)
				{
					j--;
					cursor2 -= 2;
				}
				break;

			}
			break;
		}
		if (sum == 2)
		{
			break;
			sum = 0;
		}
	}

}
//добавить секцию 
void Starting::AddSection()
{
	int ptr = 60;
	int cursor = 3;
	int sum = 0;
	string name;
	SetColorBgTex(0, 14);
	cursor_to(ptr, cursor);
	cout << "Input name of new section:";
	getline(cin, name);
	for (int i = 0; i<section.size(); i++)
	{
		if (section[i] == name)  // проверка что секции с таким названием нет
		{
			SetColorBgTex(0, 4);
			cursor_to(ptr, cursor+2);
			cout << "Error : Section with that name already exists";
			Sleep(2000);
			sum = 1;
			break;
		}
	}
	if (sum == 0)
	{
		section.push_back(name);
		SetColorBgTex(0, 13);
		cursor_to(ptr, cursor + 2);
		cout << "Section successfully created!";
		Sleep(2000);
	}
	SetColorBgTex(0, 0);
	cursor_to(ptr, cursor);
	cout << "----------------------------------------------------------";
	cursor_to(ptr, cursor + 2);
	cout << "----------------------------------------------------------";
}

// метод для создания теста в секции
void Starting::AddTest()
{
	_getch();
	int sum2 = 0;
	int Input;
	int color = 0;
	int j = 0;
	int a = 0;
	int ptr = 10;
	int ptr2 = 10;
	int cursor = 2;
	while (a != 1)
	{
		SetColorBgTex(0, 2);

		for (int i = 0; i < section.size(); i++)  // выводяться все секции для выбора нужной
		{
			cursor_to(cursor, ptr);
			ptr += 2;
			cout << "" << section[i] << endl;
		}
		ptr = 10;

		for (; j < section.size(); j++)
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr2);
			cout << "" << section[j] << endl;

			Input = _getch();
			if (Input == 13)
			{
				namesection = section[j];
				if(check!=2)
				AddTest2();
				if(check==2)  //для повторного использования метода при заполнении теста
				{
					Namesection();   
					if (check == 1) 
						check = 2;
					else
						Test();
				}
			}
			if (Input == 27)
			{
				SetColorBgTex(0, 0);
				ptr = 10;
				for (int i = 0; i < section.size(); i++)
				{
					cursor_to(cursor, ptr);
					ptr += 2;
					cout << "" << section[i] << endl;
				}
				sum2 = 2;
				break;
			}
			Input = _getch();
			if (Input == 80)
			{
				if (j < section.size() - 1)
				{
					j++;
					ptr2 += 2;

				}
				break;
			}
			if (Input == 72)
			{
				if (j > 0)
				{
					j--;
					ptr2 -= 2;
				}
				break;
			}
			break;

		}
		if (sum2 == 2)
			break;

	}
}
//создание теста
void Starting::AddTest2()
{
	int ptr = 60;
	int cursor = 3;
	int sum = 0;
	string name;
	SetColorBgTex(0, 14);
	cursor_to(ptr, cursor);
	cout << "Input name of new test:";
	getline(cin, name);
	ifstream fin(namesection);
	if (fin)
	{
		ifstream fin(namesection);
		while (!fin.eof())
		{
			char name2[50];
			fin.getline(name2, 50);
			Nametest.push_back(name2);

		}
		

		for (int i = 0; i < Nametest.size(); i++)
		{
			if (Nametest[i] == name)
			{
				SetColorBgTex(0, 4);  //проверка что такого теста нет
				cursor_to(ptr, cursor + 2);
				cout << "Error : Test with that name already exists";
				Sleep(2000);
				sum = 1;
				break;
			}
		}
	}
	fin.close();
	if (sum == 0)
	{
		SetColorBgTex(0, 13);
		cursor_to(ptr, cursor + 2);
		cout << "Test successfully created!";
		Sleep(2000);
		ofstream fout;
		fout.open(namesection, ios::app, ios::binary);
		fout << name << endl;
		fout.close();
		Nametest.clear();
	}
	SetColorBgTex(0, 0);
	cursor_to(ptr, cursor);
	cout << "----------------------------------------------------------";
	cursor_to(ptr, cursor + 2);
	cout << "----------------------------------------------------------";
}

//заполнение теста вопросами
void Starting::AddQuestion()
{
	check = 2;
	check2 = 2; // меню сработает для заполнения теста
	AddTest(); //вызываеться меню выбора секции

	check = 0;
	check2 = 0;
}

//заполнение теста
void Starting::AddQuestion2()
{
	_getch();
	int cursor = 60;
	int ptr2 = 8;
	int ptr = 8;
	SetColorBgTex(0, 13);
	cursor_to(cursor, ptr);
	cout << "Welcome to test creation!"; //инструкция
	ptr += 2;
	cursor_to(cursor, ptr);
	cout << "These are the basic rules for creating a test:";
	ptr += 2;
	cursor_to(cursor, ptr);
	cout << "The first to write a question.";
	ptr += 2;
	cursor_to(cursor, ptr );
	cout << "The maximum number of answers can be 6.";
	ptr += 2;
	cursor_to(cursor, ptr );
	cout << "If there are enough answer options, then write \"no\" instead of entering the answer.";
	ptr += 2;
	cursor_to(cursor, ptr);
	cout << "Last write the correct answer number";
	ptr += 2;

	cursor_to(cursor, ptr);
	cout << "Click Enter to continue";
	ptr += 2;
	int Input;
	Input = _getch();
	while (ptr2 != ptr)
	{
		SetColorBgTex(0, 0);
		cursor_to(cursor, ptr2);
		cout << "---------------------------------------------------------------------------------------";
		ptr2 += 2;
	}


	int sum = 0;
	while (1)  //ввод вопроса и ответов макисмум 6 если ввести no то запишет те ответы которые успел ввести
	{
		ptr2 = 10;
		ptr = 10;
		while (1)
		{
			if (sum == 1)
				cin.ignore();
			sum = 1;
			SetColorBgTex(0, 14);
			cursor_to(cursor, ptr);
			cout << "Question: ";
			getline(cin, FileTest.questions);
			ptr += 2;
			cursor_to(cursor, ptr);
			cout << "answer 1: ";
			getline(cin, FileTest.answer1);
			ptr += 2;
			cursor_to(cursor, ptr);
			cout << "answer 2: ";
			getline(cin, FileTest.answer2);
			ptr += 2;
			cursor_to(cursor, ptr);
			cout << "answer 3: ";
			getline(cin, FileTest.answer3);
			if (FileTest.answer3 == "no")
				break;
			ptr += 2;
			cursor_to(cursor, ptr);
			cout << "answer 4: ";
			getline(cin, FileTest.answer4);
			if (FileTest.answer4 == "no")
				break;
			ptr += 2;
			cursor_to(cursor, ptr);
			cout << "answer 5: ";
			getline(cin, FileTest.answer5);
			if (FileTest.answer5 == "no")
				break;
			ptr += 2;
			cursor_to(cursor, ptr);
			cout << "answer 6: ";
			getline(cin, FileTest.answer6);
			if (FileTest.answer6 == "no")
				break;
			ptr += 2;
			break;
		}
		
		cursor_to(cursor, ptr);
		cout << "correct answer number(1-6): ";
		cin >> FileTest.correctanswer;  //какой ответ верный
		ptr += 2;

		BeginTest.push_back(FileTest);
		FileTest.DelQuestions();
		int Input2;
		SetColorBgTex(0, 14);
		cursor_to(cursor, ptr);
		cout << "Input Esc if you have created enough questions";
		_getch();
		Input2 = _getch();
		while (ptr2 != ptr+2)
		{
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr2);
			cout << "------------------------------------------------------------------------------------------------------";
			ptr2 += 2;
		}
		if (Input2 == 27)
			break;
		

	}
	SaveQuestion();
	BeginTest.clear();
}
// запись теста в файл
void Starting::SaveQuestion()
{
	ofstream fout;
	fout.open(nametest, ios::app, ios::binary);
	for(int i=0;i<BeginTest.size();i++)
	{
		fout << BeginTest[i].questions << endl;
		fout << BeginTest[i].answer1<< endl;
		fout << BeginTest[i].answer2 << endl;
		fout << BeginTest[i].answer3 << endl;
		fout << BeginTest[i].answer4 << endl;
		fout << BeginTest[i].answer5 << endl;
		fout << BeginTest[i].answer6 << endl;
		fout << BeginTest[i].correctanswer << endl;
	}
	fout.close();

}

//статистика в админке - вывод всех тестов которые сдавали все пользователи
void Starting::Statistics()
{
	_getch();
	SetColorBgTex(0, 14);
	ifstream fin3("History");
	int cursor = 10;
	int i = 0;
	while (!fin3.eof())
	{
		char name[100];
		
		cursor_to(40, cursor);
		fin3.getline(name, 100);
		cout << "" << name;
		cursor += 2;
		i++;
		if (i == 4)
		{
			cursor_to(40, cursor);
			cout << "________________________";
			cursor += 2;
			
		}
		if (i == 5)
			i = 0;
		

	}
	fin3.close();
	cursor_to(40, cursor);
	SetColorBgTex(0, 4);
	cout << "Input Esc to exit";
	int Input;
	Input = _getch();
	SetColorBgTex(0, 0);
	cursor_to(40, cursor);
	cout << "Input Esc to exit";
	if (Input != 27)
	{
		SetColorBgTex(0, 4);
		cursor_to(40, cursor + 2);
		cout << "Wrong Input";
		Sleep(2000);
		cursor_to(40, cursor + 2);
		SetColorBgTex(0, 0);
		cout << "Wrong Input";
	}

	SetColorBgTex(0, 0);
	int cursor2 = 10;

	while (cursor2 != cursor)
	{
		cursor_to(40, cursor2);
		cout << "---------------------------------------------------------------";
		cursor2 += 2;
	}


}