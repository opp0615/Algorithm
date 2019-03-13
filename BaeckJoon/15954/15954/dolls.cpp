#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N = 0, K = 0;
	int arr[500] = { 0 };
	cin >> N >> K;

	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	double minStdDev = 99999;

	for (int i = 0; i < N - K + 1; i++)
	{
		int m = 0;
		//K°³ ¸¸Å­
		for (int j = i; j < K+i; j++)
		{
			m += arr[j];
		}

		double avg = (double)m / (double)K;
		
		
		double stdDev = 0;

		for (int j = i; j < K+i; j++)
		{
			double arrMinusM = (double)arr[j] - (double)avg;
			stdDev += arrMinusM * arrMinusM;
		}

		stdDev /= K;
		stdDev = sqrt(stdDev);

		if (stdDev < minStdDev)
		{
			minStdDev = stdDev;
		}
	
	}
	cout.precision(11);
	cout << fixed << minStdDev << endl;


	return 0;
}