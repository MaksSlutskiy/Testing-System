#include "Header.h"

void Mainmenu()  //начальное меню 
{
	Starting test;
	int a=1;
	int color1 = 14;
	int color2 = 4;
	while (a != 0)
	{

		
		SetColorBgTex(0, 14);   
		cursor_to(75, 1);
		printf("Welcome to Mytest");
		cursor_to(2, 3);
		SetColorBgTex(0, color2);
		printf("Registration");
		cursor_to(2, 5);
		SetColorBgTex(0, color1);
		printf("Authorization");
		int Input;
		Input = _getch();
		if (Input == 13)
		{
			if (color1 == 4)
			{
				test.Autorization();
				test.TheEnd();
				remove("UnfinishedTests");
			}
			if (color1 == 14)
			{
				test.Registration();
				test.TheEnd();
			}
		}
		if (Input == 27)
		{
			break;
		}
		Input = _getch();
		if (Input == 80)
		{
			int color3 = color1;
			color1 = color2;
			color2 = color3;
		}
		if (Input == 72)
		{
			int color3 = color1;
			color1 = color2;
			color2 = color3;
		}
		
	}
	
}

int main()
{
	
	Mainmenu();
	exit(0);



	system("pause");
	return 0;
}

