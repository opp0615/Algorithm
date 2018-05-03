#pragma warning(disable : 4996)  

#include <stdio.h>
#include <stdlib.h>

void TripleSort(unsigned int* V, unsigned N);
int ErrorDetect(unsigned int* V, unsigned N);

int main()
{
	int T = 0;
	unsigned int * V = NULL;
	unsigned int N = 0;
	int E[100] = { 0 };
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);

		V = (unsigned int*)malloc(sizeof(unsigned int)*N);

		for (unsigned int j = 0; j < N; j++)
			scanf("%d", &V[j]);
		
		TripleSort(V, N);
		E[i] = ErrorDetect(V, N);
		
		free(V);
	}

	for (int i = 0; i < T; i++)
	{
		if (E[i] == -1)
			printf("Case #%d: OK\n", i + 1);
		else
			printf("Case #%d: %d\n", i + 1, E[i]);
	}

	return 0;
}

void TripleSort(unsigned int* V, unsigned N)
{
	bool isSortEnd = false;

	while (!isSortEnd)
	{
		isSortEnd = true;

		for (unsigned int i = 0; i < N - 2; i++)
		{
			if (V[i] > V[i + 2])
			{
				isSortEnd = false;
				unsigned int temp = V[i];
				V[i] = V[i + 2];
				V[i + 2] = temp;
			}
		}
	}
}

int ErrorDetect(unsigned int* V, unsigned N)
{
	int returnError = -1;

	for (unsigned int i = 0; i < N-1; i++)
	{
		if (V[i] > V[i + 1])
		{
			returnError = i;
			break;
		}
	}

	return returnError;
}