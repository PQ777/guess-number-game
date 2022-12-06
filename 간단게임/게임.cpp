#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;

void MenuIntro()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t";
	cout << "l-------------------l" << endl;
	cout << "\t\t";
	cout << "l  ���� ���߱� ���� l" << endl;
	cout << "\t\t";
	cout << "l  �Է� �� ���ӽ��� l" << endl;
	cout << "\t\t";
	cout << "l                   l" << endl;
	cout << "\t\t";
	cout << "l      ���        ��" << endl;
	cout << "\t\t";
	cout << "l      1 2 3        l" << endl;
	cout << "\t\t";
	cout << "l      4 5 6        l" << endl;
	cout << "\t\t";
	cout << "l      7 8 *        l" << endl;
	cout << "\t\t";
	cout << "l-------------------l" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "\t\t\t\t Made By Choi In Ho" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	char intro = _getch();
	if (intro == 'g' || intro == 'G')
	{
		system("cls");

	}
}



int main()
{
	system("title ���� ���߱� ����(q Ŭ���� ���� ����)");
	system("mode con cols=60 lines=20");
	srand((unsigned int)time(NULL));
	int Number[9] = {};
	int temp, idx1, idx2;

	for (int i = 0; i < 8; i++) // ������ ���� ������ 1 ~ 8 ���� ���� ����
	{
		Number[i] = i + 1;
	}

	Number[8] = INT_MAX;  // ������ ���� ����
	int Star = 8;  // ������ ������ �� ���

	for (int i = 0; i < 100; i++) // ���ڸ� 100�� ����
	{
		idx1 = rand() % 8;
		idx2 = rand() % 8;

		temp = Number[idx1];
		Number[idx1] = Number[idx2];
		Number[idx2] = temp;

	}
	MenuIntro();
	while (1)
	{

		system("cls");
		for (int i = 0; i < 3; i++) // ������ ���ڿ� �� ���� , �� �ܴ� �������� ���� ����
		{
			cout << endl;
			cout << endl;
			for (int j = 0; j < 3; j++)
			{

				cout << "\t";

				if (Number[i * 3 + j] == INT_MAX)
				{
					cout << "*\t";
				}
				else
					cout << Number[i * 3 + j] << "\t";
			}
			cout << endl;
		}
		bool bWin = true;

		for (int i = 0; i < 8; i++)
		{
			if (Number[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}
		if (bWin == true)
		{
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

			cout << "\t";
			cout << "    l------------------------l" << endl;
			cout << "\t";
			cout << "    l ���ڸ� ���� ������ϴ� l" << endl;

			break;
		}

		cout << endl;
		cout << "\t";
		cout << "l---------------------------------l" << endl;
		cout << "\t";
		cout << "l  w : ���� �̵� / s : �Ʒ� �̵�  l" << endl;
		cout << "\t";
		cout << "l  d : ������ �̵� / a : ���� �̵�l " << endl;
		cout << "\t";
		cout << "l---------------------------------l" << endl;
		char input = _getch();

		if (input == 'q' || input == 'Q') // ���� ����
		{
			break;
		}

		switch (input)
		{
		case 'w':
		case 'W':
			if (Star > 2)
			{
				Number[Star] = Number[Star - 3];
				Number[Star - 3] = INT_MAX;
				Star -= 3;
			}
			break;

		case 's':
		case 'S':
			if (Star < 6)
			{
				Number[Star] = Number[Star + 3];
				Number[Star + 3] = INT_MAX;
				Star += 3;
			}
			break;

		case 'a':
		case 'A':
			if (Star % 3 != 0)
			{
				Number[Star] = Number[Star - 1];
				Number[Star - 1] = INT_MAX;
				--Star;
			}
			break;

		case 'd':
		case 'D':
			if (Star % 3 != 2)
			{
				Number[Star] = Number[Star + 1];
				Number[Star + 1] = INT_MAX;
				++Star;
			}
			break;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	cout << "\t";
	cout << "    l------------------------l" << endl;
	cout << "\t";
	cout << "    l    ������ �����մϴ�   l" << endl;
	cout << "\t";
	cout << "    l------------------------l" << endl;
	cout << "\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("pause");
	return 0;
}