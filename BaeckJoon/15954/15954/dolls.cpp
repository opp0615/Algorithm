#include <iostream>

using namespace std;

int main()
{
	int N = 0, K = 0;
	int arr[500] = { 0 };
	cin >> N >> K;

	int sum = 0;

	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	double m = sum / N;
	
	double sumXminusM = 0;
	for (int i = 0; i < N; i++)
	{
		sumXminusM += (arr[i] - m)*(arr[i] - m);
	}
	double standardDev = (double)sumXminusM / N;

	cout << sum << " , " << m << " , " << sumXminusM <<" , " << standardDev << endl;

	cout << "end" << endl;

	

	return 0;
}