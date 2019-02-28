#include "Header.h"

// ����������� ������������ ��� ������
void Starting::Autorization()
{
	string password2;
	string login2;
	Student autorization;
	int cursor = 40;
	int ptr = 3;
	int sum = 0;
	while (1)  //���� ������
	{
		SetColorBgTex(0, 14);
		cursor_to(cursor, ptr + 4);
		cout << "Enter your login : ";
		getline(cin, login2);
		if (login2.size()<4) //�������� ��� �������� ������ 4
		{
			SetColorBgTex(0, 4);
			cursor_to(cursor, ptr + 6);
			cout << "Login must have at least 4 characters" << endl;
			Sleep(2000);
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 4);
			cout << "Enter your login : ";
			cout << login2;
			cursor_to(cursor, ptr + 6);
			cout << "Login must have at least 4 characters" << endl;
		}
		else if (login2.size() > 20)  //�������� ��� �������� �� ������ 20
		{
			CheckSize();  // ������� ������� ��� �� ������ 20 ��������
			SetColorBgTex(0, 0);
			cursor_to(cursor, ptr + 4);

			cout << "Enter your login : ";
			cout << login2;
		}
		else
		{
			for (auto it = student.begin(); it != student.end(); it++) //���� ����� ����� ���� �������������
			{
				if (login2 == DeEncryption(it->login))
				{
					autorization.AddStudent(it->name, it->patronymic, it->famil,  //���� ������� ����������� �������
						it->address, it->phone, it->login, it->password);
					sum = 1;
				}
			}
			if (sum == 1)  //���� ����������������
				break;
			else
			{
				SetColorBgTex(0, 4);
				cursor_to(cursor, ptr + 6);  //���� ������ ������ ���
				cout << "Login not found";
				cursor_to(cursor, ptr + 8);
				cout << "Input Enter to agein or Esc";
				int Input;
				_getch();
				Input = _getch();
				SetColorBgTex(0, 0);
				cursor_to(cursor, ptr + 4);
				cout << "Enter your Login : ";
				cout << login2;
				cursor_to(cursor, ptr + 6);
				cout << "Login not found";
				cursor_to(cursor, ptr + 8);
				cout << "Input Enter to agein or Esc";
				if (Input == 27)
				{
					sum = 3;   //����� �� �����������
					break;
				}
			}

		}
	}
	if (sum != 3)
		while (1) //���� ����� � �������
		{
			SetColorBgTex(0, 14);
			cursor_to(cursor, ptr + 6);
			cout << "Enter your password : ";
			getline(cin, password2);
			if (password2.size()<4)
			{
				SetColorBgTex(0, 4);
				cursor_to(cursor, ptr + 8);
				cout << "Password must have at least 8 characters" << endl;
				Sleep(2000);
				SetColorBgTex(0, 0);
				cursor_to(cursor, ptr + 6);
				cout << "Enter your password : ";
				cout << password2;
				cursor_to(cursor, ptr + 8);
				cout << "Password must have at least 8 characters" << endl;
			}
			else if (password2.size() > 20)
			{
				CheckSize();
				SetColorBgTex(0, 0);
				cursor_to(cursor, ptr + 6);

				cout << "Enter your password : ";
				cout << password2;
			}
			else
			{
				for (auto it = student.begin(); it != student.end(); it++)
				{
					if (password2 == DeEncryption(it->password))
					{
						autorization.AddStudent(it->name, it->patronymic, it->famil,
							it->address, it->phone, it->login, it->password);
						sum = 2;
					}
				}
				if (sum == 2)
					break;
				else
				{
					SetColorBgTex(0, 4);
					cursor_to(cursor, ptr + 8);
					cout << "Password not found";
					cursor_to(cursor, ptr + 10);
					cout << "Input Enter to agein or Esc";
					int Input;
					_getch();
					Input = _getch();
					SetColorBgTex(0, 0);
					cursor_to(cursor, ptr + 6);
					cout << "Enter your password : ";
					cout << password2;
					cursor_to(cursor, ptr + 8);
					cout << "Password not found";
					cursor_to(cursor, ptr + 10);
					cout << "Input Enter to agein or Esc";
					if (Input == 27)
					{
						sum = 3;
						break;
					}
				}

			}
		}
	SetColorBgTex(0, 0);
	cursor_to(cursor, ptr + 4);
	cout << "Enter your Login : ";
	cout << login2;
	cursor_to(cursor, ptr + 6);
	cout << "Enter your password : ";
	cout << password2;

	//�������� �� ������(�� ������ � ������ ��������������������)
	if(login2== DeEncryption(student.front().login) && password2== DeEncryption(student.front().password))
		AdminMenu();
	else if(sum != 3)
		Areamenu(); //
}
