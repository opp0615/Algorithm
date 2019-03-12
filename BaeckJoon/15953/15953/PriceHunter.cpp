#include <iostream>

using namespace std;

int FirstPrice(int a);
int SecondPrice(int b);

int main()
{
	int T = 0;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int a = 0, b = 0;
		
		cin >> a >> b;
	
		int result = FirstPrice(a) + SecondPrice(b);

		cout << result << endl;
	}

	return 0;
}


int FirstPrice(int a)
{

	int price = 0;

	if (a == 0)
	{
		price = 0;
	}
	else if( a <= 1) // 1명
	{
		price = 5000000;
	}
	else if (a <= 3) { //2명
		price = 3000000;
	}
	else if (a <= 6) //3명
	{
		price = 2000000;

	}
	else if (a <= 10) //4명
	{
		price = 500000;
	}
	else if (a <= 15) //5명
	{
		price = 300000;
	}
	else if (a <= 21) //6명
	{
		price = 100000;
	}

	return price;
}

int SecondPrice(int b) 
{
	int price = 0;
	if (b == 0) {
		price = 0;
	}
	else if(b <= 1) // 1명
	{
		price = 5120000;
	}
	else if (b <= 3) { //2명
		price = 2560000;
	}
	else if (b <= 7) //4명
	{
		price = 1280000;

	}
	else if (b <= 15) //8명
	{
		price = 640000;
	}
	else if (b <= 31) //16명
	{
		price = 320000;
	}

	return price;

}