#pragma warning(disable : 4996)  

#include <stdio.h>
#include <math.h>

int main()
{
	int T = 0;
	double A = 0;
	double matrix[3][3][100] = { 0 };
	double theta = 0;
	double PI = 3.14159265358979323846;
	double max = 1.414213;
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%lf", &A);

		A = A / max;

		theta = asin(A) - PI / (double)4;
		//printf("%.15lf,, %.15lf %.15lf, %.15lf\n",sqrt(2), asin(A), theta,sin(theta));
		matrix[0][0][i] = cos(theta)/(double)2;
		matrix[0][1][i] = sin(theta)/(double)2;
		matrix[0][2][i] = 0;

		matrix[1][0][i] = -sin(theta)/2;
		matrix[1][1][i] = cos(theta)/2;
		matrix[1][2][i] = 0;

		matrix[2][0][i] = 0;
		matrix[2][1][i] = 0;
		matrix[2][2][i] = 0.5;
	}

	for (int i = 0; i < T; i++)
	{
		printf("Case #%d:\n", i + 1);

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				printf("%.15lf ", matrix[j][k][i]);
			}
			printf("\n");
		}
	}

	return 0;
}