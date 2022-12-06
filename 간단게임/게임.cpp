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
	cout << "l  숫자 맞추기 게임 l" << endl;
	cout << "\t\t";
	cout << "l  입력 시 게임시작 l" << endl;
	cout << "\t\t";
	cout << "l                   l" << endl;
	cout << "\t\t";
	cout << "l      ▼▼        ㅣ" << endl;
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
	system("title 숫자 맞추기 게임(q 클릭시 게임 종료)");
	system("mode con cols=60 lines=20");
	srand((unsigned int)time(NULL));
	int Number[9] = {};
	int temp, idx1, idx2;

	for (int i = 0; i < 8; i++) // 마지막 별을 제외한 1 ~ 8 까지 숫자 저장
	{
		Number[i] = i + 1;
	}

	Number[8] = INT_MAX;  // 마지막 공백 지정
	int Star = 8;  // 마지막 공간에 별 등록

	for (int i = 0; i < 100; i++) // 숫자를 100번 섞기
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
		for (int i = 0; i < 3; i++) // 마지막 숫자에 별 생성 , 그 외는 랜덤으로 숫자 지정
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
			cout << "    l 숫자를 모주 맞췄습니다 l" << endl;

			break;
		}

		cout << endl;
		cout << "\t";
		cout << "l---------------------------------l" << endl;
		cout << "\t";
		cout << "l  w : 위쪽 이동 / s : 아래 이동  l" << endl;
		cout << "\t";
		cout << "l  d : 오른쪽 이동 / a : 왼쪽 이동l " << endl;
		cout << "\t";
		cout << "l---------------------------------l" << endl;
		char input = _getch();

		if (input == 'q' || input == 'Q') // 게임 종료
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
	cout << "    l    게임을 종료합니다   l" << endl;
	cout << "\t";
	cout << "    l------------------------l" << endl;
	cout << "\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	system("pause");
	return 0;
}