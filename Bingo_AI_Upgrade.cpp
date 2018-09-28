#include <iostream>
#include <stdlib.h>
#include <time.h>

#define INT_MAX 10000
using namespace std;

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT,
};
int main()
{
	int Number[25];
	int AINumber[25];
	int temp, idx1, idx2;
	srand((unsigned int)time(0));
	for (int i = 0; i < 25; i++) {
		Number[i] = i + 1;
		AINumber[i] = i + 1;
	}
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		temp = Number[idx1];
		Number[idx1] = Number[idx2];
		Number[idx2] = temp;

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		temp = AINumber[idx1];
		AINumber[idx1] = AINumber[idx2];
		AINumber[idx2] = temp;
	}



	int Bingo = 0, AIBingo = 0;
	int AiMode;
	// AI 난이도를 선택한다.
	while (true)
	{
		cout << "****** 5줄 빙고시 승리 ******" << endl;
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI 모드를 선택하세요. : ";
		
		cin >> AiMode;
		if (AiMode < AM_EASY || AiMode > AM_HARD)
		{
			system("cls");
			cout << "난이도를 잘못 입력하셨습니다." << endl;
			continue;
		}
		else
		{
			system("cls");
			break;
		}
	}

	int NoneSelect[25] = {};
	int NoneSelectCount = 0;
	while (true)
	{
		cout << "============ Player ============" << endl;
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
		cout << "\n\n\n\n" << "============== AI ==============" << endl;

		switch (AiMode)
		{
		case AM_EASY:
			cout << "AIMode : Easy" << endl;
			break;
		case AM_HARD:
			cout << "AIMode : Hard" << endl;
			break;
		}
		cout << "Line : " << AIBingo << endl;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (AINumber[i * 5 + j] == INT_MAX)
				{
					cout << "*\t";
				}
				else
				{
					cout << AINumber[i * 5 + j] << "\t";
				}
			}

			cout << endl;
		}

		/*if (Bingo >= 5 && AIBingo >= 5)
		{
			cout << "비김" << endl;
			break;
		}*/
		if (Bingo >= 5)
		{
			if (Bingo == AIBingo)
			{
				cout << "비김" << endl;
			}
			else if (Bingo >= AIBingo)
			{
				cout << "Player 승리" << endl;
			}
			else if (AIBingo >= Bingo)
			{
				cout << "AI 승리" << endl;
			}
			
			break;
		}
		else if (AIBingo >= 5)
		{
			cout << "AI 승리" << endl;
			break;
		}
		

		//입력
		int Input = 0;
		cout << "\n\n\n\n" << "수를 입력하세요. (0 : 종료) : ";
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
					if (Input == AINumber[i * 5 + j])
					{
						AINumber[i * 5 + j] = INT_MAX;
					}
				}
			}

			// 빙고 UP
			Bingo = 0;
			AIBingo = 0;
			int AIcheck1 = 0, AIcheck2 = 0, AIcheck3 = 0, AIcheck4 = 0;
			int check1 = 0, check2 = 0, check3 = 0, check4 = 0;
			for (int i = 0; i < 5; i++)
			{
				AIcheck1 = 0, AIcheck2 = 0, AIcheck3 = 0, AIcheck4 = 0;
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
					if (AINumber[i * 5 + j] == INT_MAX)
					{
						AIcheck1++;
					}
					if (AINumber[j * 5 + i] == INT_MAX)
					{
						AIcheck2++;
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
				if (AIcheck1 == 5)
				{
					AIBingo++;
				}
				if (AIcheck2 == 5)
				{
					AIBingo++;
				}

			}
			check3 = 0;
			AIcheck3 = 0;
			for (int i = 0; i < 25; i += 6)
			{
				if (Number[i] == INT_MAX)
				{
					check3++;
				}
				if (AINumber[i] == INT_MAX)
				{
					AIcheck3++;
				}
			}
			if (check3 == 5)
			{
				Bingo++;
			}
			if (AIcheck3 == 5)
			{
				AIBingo++;
			}
			check4 = 0;
			AIcheck4 = 0;
			for (int i = 4; i <= 20; i += 4)
			{
				if (Number[i] == INT_MAX)
				{
					check4++;
				}
				if (AINumber[i] == INT_MAX)
				{
					AIcheck4++;
				}
			}
			if (check4 == 5)
			{
				Bingo++; 
			} 
			if (AIcheck4 == 5)
			{
				AIBingo++;
			}
			//AI
			NoneSelectCount = 0;
			switch (AiMode)
			{
				case AM_EASY:
					for (int i = 0; i < 25; i++)
					{
						// *이 아닐경우
						if (AINumber[i] != INT_MAX)
						{
							NoneSelect[NoneSelectCount] = AINumber[i];
							++NoneSelectCount;
						}
					}

					Input = NoneSelect[rand() % NoneSelectCount];
					break;
				case AM_HARD:
					// 빙고줄 완성 가능성이 가장 높은 줄을 찾아서 그 줄에있는
					// 숫자를 *로 만드는 알고리즘
					int Line;
					int CheckCount;
					int SaveCount = 0;

					// 가로 라인중 가장*이 많은 것을 찾는다.
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 5; j++)
						{
							if (AINumber[i * 5 + j] == INT_MAX)
							{
								CheckCount++;
							}
						}
						// 별이 5개 미만
						// 기존에 가장 많은 라인의 별보다 커야 가장 별이
						// 많은 라인이므로 라인을 교체해주고 별수를 교체
						if (CheckCount < 5 && SaveCount < CheckCount)
						{
							Line = i;
							SaveCount = CheckCount;
						}
					}

					for (int i = 0; i < 5; i++)
					{
						CheckCount = 0;
						for (int j = 0; j < 5; j++)
						{
							if (AINumber[j * 5 + i] == INT_MAX)
							{
								CheckCount++;
							}
						}
						if (CheckCount < 5 && SaveCount < CheckCount)
						{
							Line = i + 5;
							SaveCount = CheckCount;
						}
					}

					CheckCount = 0;
					for (int i = 0; i < 25; i += 6)
					{
						if (AINumber[i] == INT_MAX)
						{
							CheckCount++;
						}
					}
					if (CheckCount < 5 && SaveCount < CheckCount)
					{
						Line = LN_LT;
						SaveCount = CheckCount;
					}
					CheckCount = 0;
					for (int i = 4; i <= 20; i += 4)
					{
						if (AINumber[i] == INT_MAX)
						{
							CheckCount++;
						}
					}
					if (CheckCount < 5 && SaveCount < CheckCount)
					{
						Line = LN_RT;
						SaveCount = CheckCount;
					}
					if (Line <= LN_H5)
					{
						for (int i = 0; i < 5; i++)
						{
							if (AINumber[Line * 5 + i] != INT_MAX)
							{
								Input = AINumber[Line * 5 + i];
								break;
							}
						}
					}

					else if (Line <= LN_V5)
					{
						for (int i = 0; i < 5; i++)
						{
							if (AINumber[i * 5 + (Line - 5)] != INT_MAX)
							{
								Input = AINumber[i * 5 + (Line - 5)];
								break;
							}
						}
					}
					else if (Line == LN_LT)
					{
						for (int i = 0; i < 25; i += 6)
						{
							if (AINumber[i] != INT_MAX)
							{
								Input = AINumber[i];
								break;
							}
						}
					}

					else if (Line == LN_RT)
					{
						for (int i = 4; i <= 20; i += 4)
						{
							if(AINumber[i] != INT_MAX)
							{
								Input = AINumber[i];
								break;
							}
						}
					}
					break;
			}
			for (int i = 0; i < 25; i++)
			{
				if (Number[i] == Input)
				{
					Number[i] = INT_MAX;
					break;
				}
			}
			for (int i = 0; i < 25; i++)
			{
				if (AINumber[i] == Input)
				{
					AINumber[i] = INT_MAX;
					break;
				}
			}
			system("cls");
			cout << "Ai가 입력한수 : " << Input << endl;
			continue;
		}
		else if (Input > 25)
		{
			system("cls");
			cout << "너무 큰수를 입력하셨습니다." << endl;
			continue;
		}


	}

	system("Pause");
}
