// PICNIC.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#pragma warning (disable:4996) 

void friendMatching(bool (*isFriend)[10],bool* isMatched, int n);
int globalCount = 0;

int main()
{
	int C = 0;
	int N = 0, M = 0;
	int result[50];
	bool isFriend[10][10] = { false };
	bool isMatched[10] = { false };

	scanf("%d", &C);

	for (int i = 0; i < C; i++)
	{
		//집합의 개수 초기화
		globalCount = 0;

		//상태 테이블 초기화
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				isFriend[j][k] = false;
			}

		}

		scanf("%d %d", &N, &M);

		//상태 테이블 입력
		for (int j = 0; j < M; j++)
		{
			int friendA, friendB = 0;
			scanf("%d %d", &friendA, &friendB);
			isFriend[friendA][friendB] = true;
			isFriend[friendB][friendA] = true;

		}

		friendMatching(isFriend, isMatched, N);

		/*
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				printf("%d ", isFriend[j][k]);
			}
			printf("\n");
		}
		*/

		result[i] = globalCount;
	}

	for (int i = 0; i < C; i++)
	{
		printf("%d\n", result[i]);
	}

    return 0;
}

void friendMatching(bool (*isFriend)[10],bool* isMatched, int n)
{
	int firstStudent = 0;
	bool isTerminal = true;
	/*
	printf("{");
	for (int i = 0; i < n; i++)
	{
		if (isMatched[i] == false)
		{
			printf("%d ", i);
		}
	}
	printf("}\n");
	*/
	for (int i = 0; i < n; i++)
	{
		if (isMatched[i] == false)
		{
			firstStudent = i;
			isTerminal = false;
			break;
		}
		
	}

	if (isTerminal)
	{
		globalCount++;
		return;
	}

	for (int i = firstStudent; i < n; i++)
	{
		//짝이 안지어진애들 중 짝을 매칭 후 다음 스텝
		if (isFriend[firstStudent][i] == true && isMatched[firstStudent] == false && isMatched[i] == false)
		{
			isMatched[firstStudent] = true;
			isMatched[i] = true;
			//printf("(%d,%d)\n", firstStudent, i);
			friendMatching(isFriend, isMatched, n);
			isMatched[firstStudent] = false;
			isMatched[i] = false;
		}
	}

	
}