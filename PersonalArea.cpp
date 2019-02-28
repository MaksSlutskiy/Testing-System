#include "Header.h"

// меню пользователя после авторизации
void Starting::Areamenu()
{
	_getch();
	int color1 = 14;
	int cursor = 3;
	int cursor2 = 3;
	int sum = 0;
	vector<string> menu;
	string name1 = "Start New Test";
	string name2 = "Test History";
	string name3 = "Unfinished Tests";
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
			cout <<menu[i];
			cursor += 2;
		}
		cursor = 3;
		for (; j < menu.size(); j++)
		{
			SetColorBgTex(0, 4);
			cursor_to(20, cursor2);
			cout <<menu[j];


			int Input;
			Input = _getch();
			if (Input == 13)
			{
				if (j == 0)
				{
					Section();
				}
				if (j == 1)
				{
					History();
				}
				if (j == 2)
				{
					UnfinishedTests();

				}

			}
			if (Input == 27)
			{
				SetColorBgTex(0, 0);
				cursor_to(20, cursor);
				printf("Start New Test");
				cursor_to(20, cursor+2);
				printf("Test History");
				cursor_to(20, cursor + 4);
				printf("Unfinished Tests");
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
		}
	}
}
// выводит все доступные секции тестов для выбора пользователем
void Starting::Section()
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
		
		for (int i = 0; i < section.size(); i++)
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
				 Namesection();
				 if (check != 1)
				 {
					 Test();
				 }
				 check = 0;
				 
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
				 if (j < section.size()-1)
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
//выбор нужного теста в секции
void Starting::Test()
{
	_getch();
	int Input;
	int color = 0;
	int j = 0;
	int a = 0;
	int ptr = 10;
	int ptr2 = 10;
	int cursor = 20;
	int sum = 0;
	while (a != 1)
	{
		SetColorBgTex(0, 2);

		for (int i = 0; i < Nametest.size(); i++)
		{
				cursor_to(cursor, ptr);
				ptr += 2;
				cout << "" << Nametest[i] << endl;
		}
		ptr = 10;

		for (; j < Nametest.size(); j++)
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr2);
			cout << "" << Nametest[j] << endl;

			Input = _getch();
			if (Input == 13)
			{
				nametest = Nametest[j];
				StartQuestions();
				if(check2==0)
				if (check == 0)
				{
					TestMenu();
				}
				if (check2 == 2)
				{
					if (check == 1)
					{
						AddQuestion2();
					}
					else
					{
						cursor_to(60, 12);
						SetColorBgTex(0, 4);
						cout << "This test is ready!";
						Sleep(1000);
						SetColorBgTex(0, 0);
						cursor_to(60, 12);
						cout << "This test is ready!";
					}

				}
				if (check2 == 2)
					check = 2;
				else
				check = 0;
			}
			if (Input == 27)
			{
				SetColorBgTex(0, 0);
				ptr = 10;
				for (int i = 0; i < Nametest.size(); i++)
				{
					cursor_to(cursor, ptr);
					ptr += 2;
					cout << "" << Nametest[i] << endl;
				}
				Nametest.clear();
				sum = 1;
				break;
			}
			Input = _getch();
			if (sum == 1)
			{
				Input = _getch();
				sum = 0;
			}
				
			if (Input == 80)
			{
				if (j <Nametest.size() - 2)
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
		if (sum == 1)
			break;
		
		
	}
}
//считывает с выбранного файла тест
void Starting::StartQuestions()
{
	ifstream file(nametest);
	if (!file)
	{
		check = 1;
	}
	else
	{
		int sum2 = 0;
		int sum3;
		while (!file.eof())
		{
			char name[200];
			if (sum2 == 0)
			{
				file.getline(name, 200);
				FileTest.questions = name;
			}
			if (sum2 == 1)
			{
				file.getline(name, 200);
				FileTest.answer1 = name;
			}
			if (sum2 == 2)
			{
				file.getline(name, 200);
				FileTest.answer2 = name;
			}
			if (sum2 == 3)
			{
				file.getline(name, 200);
				FileTest.answer3 = name;
			}
			if (sum2 == 4)
			{
				file.getline(name, 200);
				FileTest.answer4 = name;
			}
			if (sum2 == 5)
			{
				file.getline(name, 200);
				FileTest.answer5 = name;
			}
			if (sum2 == 6)
			{
				file.getline(name, 200);
				FileTest.answer6 = name;
			}
			if (sum2 == 7)
			{
				sum2 = -1;
				file.getline(name, 200);
				int correctanswer = atoi(name);
				FileTest.correctanswer = correctanswer;

				BeginTest.push_back(FileTest);
				
			}
			sum2++;


		}
		file.close();
		FileTest.DelQuestions();

	}
	
}

// начало теста
void Starting::TestMenu()
{
	_getch(); 
	SetColorBgTex(0, 13);
	cursor_to(50, 4);
	cout << "If you want to stop the test then click Esc"; //для того чтобы не создавать кучу файлов решил сделать что может быть только один
	cursor_to(50, 6);										// незаконченный тест после выхода из профиля неоконченный тест будет стерт
	cout << "After exiting the profile, the unfinished test will be deleted";
	cursor_to(50, 8);
	cout << "Warning : If you already have an unfinished test then he will disappear";
	int sum = 0;
	int sum2 = 0;
	int sum3 = 0;
	int cursor = 50;
	int ptr = 10;
	for (int i = 0; i < BeginTest.size(); i++)
	{
		int j = 0;
		while (1)
		{
			while (1)
			{
				int Input;
				cursor_to(cursor, ptr);
				SetColorBgTex(0, 14);
				
				cout << "" << BeginTest[i].questions << endl;
				if (j == 0)
				{
					SetColorBgTex(0, 4);
				}
				if (BeginTest[i].answer1 != "no")		
				{
					sum2++;
					cursor_to(cursor, ptr+2);
					cout << "" << BeginTest[i].answer1 << endl;
					SetColorBgTex(0, 14);
				}
				if (j == 1)
				{
					SetColorBgTex(0, 4);
				}
				if (BeginTest[i].answer2 != "no")
				{
					sum2++;
					cursor_to(cursor, ptr + 4);
					cout << "" << BeginTest[i].answer2 << endl;
					SetColorBgTex(0, 14);
				}
				if (j == 2)
				{
					SetColorBgTex(0, 4);
				}
				if (BeginTest[i].answer3 != "no")
				{
					sum2++;
					cursor_to(cursor, ptr + 6);
					cout << "" << BeginTest[i].answer3 << endl;
					SetColorBgTex(0, 14);
				}
				if (j == 3)
				{
					SetColorBgTex(0, 4);
				}
				if (BeginTest[i].answer4 != "no")
				{
					sum2++;
					cursor_to(cursor, ptr + 8);
					cout << "" << BeginTest[i].answer4 << endl;
					SetColorBgTex(0, 14);
				}
				if (j == 4)
				{
					SetColorBgTex(0, 4);
				}
				if (BeginTest[i].answer5 != "no")
				{
					sum2++;
					cursor_to(cursor, ptr + 10);
					cout << "" << BeginTest[i].answer5 << endl;
					SetColorBgTex(0, 14);
				}
				if (j == 5)
				{
					SetColorBgTex(0, 4);
				}
				if (BeginTest[i].answer6 != "no")
				{
					sum2++;
					cursor_to(cursor, ptr + 12);
					cout << "" << BeginTest[i].answer6 << endl;
					SetColorBgTex(0, 14);
				}

				Input = _getch();
				if (Input == 13)		//после ответа в вектор оценок добавляеться 1 если правильно или 0 если нет
				{
					if (BeginTest[i].correctanswer-1 == j)
						asses.push_back(1);
					else
						asses.push_back(0);
					sum = 1;
					break;
				}
				if (Input == 27)  //если тест останавливаеться создаеться файл с информацией по пройденным вопросам
				{
					double mycount = count_if(asses.begin(), asses.end(), [](int n) { return n == 1; });
					remove("UnfinishedTests");
					ofstream fout;
					fout.open("UnfinishedTests", ios::app, ios::binary);
					fout << mas.famil << endl;
					fout << nametest << endl;
					fout << i-1 << endl;
					fout << mycount << endl;;
					fout << asses.size();
					fout.close();
					sum3 = 1;
					break;
				}
				Input = _getch();
				if (Input == 80)
				{
					j++;
					if (j == sum2)
						j = 0;
					break;
				}
				if (Input == 72)
				{
					j--;
					if (j == -1)
						j = sum2-1;
					break;
				}
			}
			if (sum == 1||sum3==1)
				break;
			sum2 = 0;
		}
		
		
		
		int ptr2 = 4;
		ptr = 26;
		while (ptr2 != ptr)
		{
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr2);
			cout << "-----------------------------------------------------------------------------------------------";
			ptr2 += 2;
		}

		_getch();
		sum = 0;
		ptr = 8;
		if (sum3 == 1)
			break;
	}

	SetColorBgTex(0, 14);  //если тест пройден до конца подсчитываеться оценка
	if (sum3 != 1)
	{
		double mycount = count_if(asses.begin(), asses.end(), [](int n) { return n == 1; });
		double percentasses = (mycount / asses.size()) * 100; //процент
		double testasses = percentasses / 8.3;			//оценка
		ostream *arr[2] =
		{
			&cout,
			new ofstream("History",ios::app, ios::binary)

		};
		for (int i = 0; i < 2; i++)
		{
			cursor_to(cursor, ptr);
			*(arr[i]) << "The exam passed: " << mas.famil << endl;
			cursor_to(cursor, ptr + 2);
			*(arr[i]) << "The exam on topic: " << nametest << " [ finished ]" << endl;
			cursor_to(cursor, ptr + 4);
			*(arr[i]) << "Correct answers - " << percentasses << " %" << endl;
			cursor_to(cursor, ptr + 6);
			*(arr[i]) << "Your assessment - " << testasses << " (12)" << endl;
			*(arr[i]) << endl;
		}
		_getch();
		int Input;
		Input = _getch();
		if (Input != 27)
		{
			cursor_to(cursor, ptr + 8);
			cout << "Wrong input";
			Sleep(1000);

		}
		SetColorBgTex(0, 0);
		cursor_to(cursor, ptr);
		cout << "The exam passed: " << mas.famil << endl;
		cursor_to(cursor, ptr + 2);
		cout << "The exam on topic: " << nametest << " [ finished ]" << endl;
		cursor_to(cursor, ptr + 4);
		cout << "Correct answers - " << percentasses << " %" << endl;
		cursor_to(cursor, ptr + 6);
		cout << "Your assessment - " << testasses << " (12)" << endl;
		cursor_to(cursor, ptr + 8);
		cout << "Wrong input";
	}
	BeginTest.clear();
	asses.clear();
	_getch();
}

// история сдачи тестов пользователя
void Starting::History()
{
	_getch();
	SetColorBgTex(0, 14);
	ifstream fin3("History");
	int cursor = 10;
	string str = "The exam passed: ";
	string str2 = mas.famil;
	string str4;
	str4=str + str2;
	string str3;
	int sum = 0;
	int i = 0;
	while (!fin3.eof())
	{
		char name[100];
		if (sum == 0)
		{
			fin3.getline(name, 100);
			str3 = name;
			if (str3 == str4)
				sum = 1;

		}
		if (sum ==1&&i!=4)
		{
			cursor_to(40, cursor);
			cout << "" << name;
			fin3.getline(name, 100);
			cursor += 2;
			i++;
			if (i == 4)
			{
				cursor_to(40, cursor);
				cout << "________________________";
				cursor += 2;
			}
	
		}
		else
		{
			sum = 0;
			i = 0;
		}
		
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
		cursor_to(40, cursor+2);
		cout << "Wrong Input";
		Sleep(2000);
		cursor_to(40, cursor+2);
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

void Starting::UnfinishedTests()
{
	_getch();
	int i;
	int asses2;
	int Allasses;
	string name2;
	ifstream file("UnfinishedTests");
	if (!file)
	{
		SetColorBgTex(0, 4);
		cursor_to(60, 6);
		cout << "you have no unfinished tests!";
		Sleep(2000);
		SetColorBgTex(0, 0);
		cursor_to(60, 6);
		cout << "you have no unfinished tests!";
		_getch();
	}
	else
	{
		char name[20];
		file.getline(name, 100);
		name2 = name;
		file.getline(name, 100);
		nametest = name;
		file.getline(name, 100);
		i = atoi(name) + 1;
		file.getline(name, 100);
		asses2 = atoi(name);
		file.getline(name, 100);
		Allasses = atoi(name);
		file.close();
		StartQuestions();

		int sum = 0;
		int sum2 = 0;
		int sum3 = 0;
		int cursor = 50;
		int ptr = 8;
		for (i; i < BeginTest.size(); i++)
		{
			int j = 0;
			while (1)
			{
				while (1)
				{
					int Input;
					cursor_to(cursor, ptr-2);
					SetColorBgTex(0, 14);

					cout << "" << BeginTest[i].questions << endl;
					if (j == 0)
					{
						SetColorBgTex(0, 4);
					}
					if (BeginTest[i].answer1 != "no")
					{
						sum2++;
						cursor_to(cursor, ptr);
						cout << "" << BeginTest[i].answer1 << endl;
						SetColorBgTex(0, 14);
					}
					if (j == 1)
					{
						SetColorBgTex(0, 4);
					}
					if (BeginTest[i].answer2 != "no")
					{
						sum2++;
						cursor_to(cursor, ptr + 2);
						cout << "" << BeginTest[i].answer2 << endl;
						SetColorBgTex(0, 14);
					}
					if (j == 2)
					{
						SetColorBgTex(0, 4);
					}
					if (BeginTest[i].answer3 != "no")
					{
						sum2++;
						cursor_to(cursor, ptr + 4);
						cout << "" << BeginTest[i].answer3 << endl;
						SetColorBgTex(0, 14);
					}
					if (j == 3)
					{
						SetColorBgTex(0, 4);
					}
					if (BeginTest[i].answer4 != "no")
					{
						sum2++;
						cursor_to(cursor, ptr + 6);
						cout << "" << BeginTest[i].answer4 << endl;
						SetColorBgTex(0, 14);
					}
					if (j == 4)
					{
						SetColorBgTex(0, 4);
					}
					if (BeginTest[i].answer5 != "no")
					{
						sum2++;
						cursor_to(cursor, ptr + 8);
						cout << "" << BeginTest[i].answer5 << endl;
						SetColorBgTex(0, 14);
					}
					if (j == 5)
					{
						SetColorBgTex(0, 4);
					}
					if (BeginTest[i].answer6 != "no")
					{
						sum2++;
						cursor_to(cursor, ptr + 10);
						cout << "" << BeginTest[i].answer6 << endl;
						SetColorBgTex(0, 14);
					}

					Input = _getch();
					if (Input == 13)
					{
						if (BeginTest[i].correctanswer - 1 == j)
							asses.push_back(1);
						else
							asses.push_back(0);
						sum = 1;
						break;
					}

					Input = _getch();
					if (Input == 80)
					{
						j++;
						if (j == sum2)
							j = 0;
						break;
					}
					if (Input == 72)
					{
						j--;
						if (j == -1)
							j = sum2 - 1;
						break;
					}
				}
				if (sum == 1)
					break;
				sum2 = 0;
			}


			int ptr2 = 6;
			ptr = 24;
			while (ptr2 != ptr)
			{
				SetColorBgTex(0, 0);
				cursor_to(cursor, ptr2);
				cout << "-----------------------------------------------------------------------------------------------";
				ptr2 += 2;
			}

			_getch();
			sum = 0;
			ptr = 8;
			if (sum3 == 1)
				break;
		}

		SetColorBgTex(0, 14);

		double mycount = asses2+count_if(asses.begin(), asses.end(), [](int n) { return n == 1; });
		
		double percentasses = ((mycount / (asses.size()+Allasses)) * 100);
		double testasses = (percentasses / 8.3);
		ostream *arr[2] =
		{
			&cout,
			new ofstream("History",ios::app, ios::binary)

		};
		for (int i = 0; i < 2; i++)
		{
			cursor_to(cursor, ptr);
			*(arr[i]) << "The exam passed: " << mas.famil << endl;
			cursor_to(cursor, ptr + 2);
			*(arr[i]) << "The exam on topic: " << nametest << " [ finished ]" << endl;
			cursor_to(cursor, ptr + 4);
			*(arr[i]) << "Correct answers - " << percentasses << " %" << endl;
			cursor_to(cursor, ptr + 6);
			*(arr[i]) << "Your assessment - " << testasses << " (12)" << endl;
			*(arr[i]) << endl;
		}
		
		int Input;
		Input = _getch();
		if (Input != 27)
		{
			cursor_to(cursor, ptr + 8);
			cout << "Wrong input";
			Sleep(1000);

		}
		SetColorBgTex(0, 0);
		cursor_to(cursor, ptr);
		cout << "The exam passed: " << mas.famil << endl;
		cursor_to(cursor, ptr + 2);
		cout << "The exam on topic: " << nametest << " [ finished ]" << endl;
		cursor_to(cursor, ptr + 4);
		cout << "Correct answers - " << percentasses << " %" << endl;
		cursor_to(cursor, ptr + 6);
		cout << "Your assessment - " << testasses << " (12)" << endl;
		cursor_to(cursor, ptr + 8);
		cout << "Wrong input";

		BeginTest.clear();
		asses.clear();
		remove("UnfinishedTests");


	}
}