// codejamSavingUniverse.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#pragma warning(disable:4996)
#include <stdio.h>
long long TotalDamegeCount(char* P, int instCount);

int main()
{
	int T = 1;
	long long D = 1;
	char P[30];
	int instCount = 0;
	char inst = NULL;
	long long totalDamage = 0;
	int hackCount[100] = { 0 };

	scanf("%d", &T);

	//test case
	for (int i = 0; i < T; i++)
	{
		instCount = 0;
		totalDamage = 0;
		hackCount[i] = 0;
		scanf("%d ", &D);

		for(int j=0;j<30;j++)
		{
			scanf("%c", &inst);
			if (inst == '\n')
				break;
			P[instCount] = inst;
			instCount++;
		}
		

		totalDamage = TotalDamegeCount(P, instCount);

		while (totalDamage > D)
		{
			bool isAnythingChange = false;

			for (int j = instCount; j >=0; j--)
			{
				if (P[j] == 'S')
				{
					if ((j - 1) >= 0)
					{
						if (P[j - 1] == 'C')
						{
							isAnythingChange = true;
							hackCount[i]++;
							P[j-1] = 'S';
							P[j] = 'C';
						}
					}
				}
			}

			if (!isAnythingChange)
			{
				hackCount[i] = -1;
				break;
			}

			totalDamage = TotalDamegeCount(P, instCount);

		}
		
	}

	for (int i = 0; i < T; i++)
	{
		if (hackCount[i] == -1)
			printf("Case #%d: IMPOSSIBLE\n",i+1);
		else
			printf("Case #%d: %d\n",i+1,hackCount[i]);
	}

    return 0;
}


long long TotalDamegeCount(char* P,int instCount)
{
	long long nowDamage = 1;
	long long totalDamage = 0;
	for (unsigned int j = 0; j < instCount; j++)
	{
		if (P[j] == 'C')
		{
			nowDamage *= 2;
		}
		else
		{
			totalDamage += nowDamage;
		}
	}
	
	return totalDamage;
}

