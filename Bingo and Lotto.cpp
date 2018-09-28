#include <iostream>
#include <time.h>

#define INT_MAX 10000
using namespace std;
int main()
{

	/*로또 srand((unsigned int)time(0));

	int Lotto[45] = {};

	for (int i = 0; i < 45; i++)
	{
		Lotto[i] = i + 1;
	}

	int temp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		temp = Lotto[idx1];
		Lotto[idx1] = Lotto[idx2];
		Lotto[idx2] = temp;
	}
	for (int i = 0; i < 6; i++)
	{
		cout << Lotto[i] << endl;;
	}
	cout << "보너스번호 : " << Lotto[6] << endl;
	system("Pause");*/

	int Number[25];
	int temp, idx1, idx2;
	srand((unsigned int)time(0));
	for (int i = 0; i < 25; i++) {
		Number[i] = i + 1;
	}
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		temp = Number[idx1];
		Number[idx1] = Number[idx2];
		Number[idx2] = temp;
	}



	int Bingo = 0;
	while (true)
	{
		cout << "Line : " << Bingo << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (Number[i * 5 + j] == INT_MAX)
				{
					cout << "*\t";
				}
				else
				{
					cout << Number[i * 5 + j] << "\t";
				}
			}

			cout << endl;
		}

		if (Bingo == 5)
		{
			break;
		}

		//입력
		int Input = 0;
		cout << "수를 입력하세요. (0 : 종료) : ";
		cin >> Input;
		if (Input == 0)
		{
			break;
		}
		else if (Input >= 1 && Input <= 25)
		{

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (Input == Number[i * 5 + j])
					{
						Number[i * 5 + j] = INT_MAX;
					}
				}
			}

			// 빙고 UP
			Bingo = 0;
			int check1 = 0, check2 = 0, check3 = 0, check4 = 0;
			for (int i = 0; i < 5; i++)
			{
				check1 = 0, check2 = 0, check3 = 0, check4 = 0;
				for (int j = 0; j < 5; j++)
				{
					if (Number[i * 5 + j] == INT_MAX)
					{
						check1++;
					}
					if (Number[j * 5 + i] == INT_MAX)
					{
						check2++;
					}
				}
				if (check1 == 5)
				{
					Bingo++;
				}
				if (check2 == 5)
				{
					Bingo++;
				}
				
			}
			check3 = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (Number[i] == INT_MAX)
				{
					check3++;
				}
			}
			if (check3 == 5)
			{
				Bingo++;
			}
			check4 = 0;
			for (int i = 4; i <= 20; i += 4)
			{
				if (Number[i] == INT_MAX)
				{
					check4++;
				}
			}
			if (check4 == 5)
			{
				Bingo++;
			}
			system("cls");
			continue;
		}


	}

	system("Pause");
}