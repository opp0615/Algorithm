#include <iostream>
#include <vector>

using namespace std;

int main()
{

	int T = 0;

	cin >> T;

	vector<int> height;

	for (int i = 0; i < T; i++)
	{
		int tempHeight = 0;
		cin >> tempHeight;

		height.push_back(tempHeight);

	}


	for (int i = 0; i < T; i++)
	{
		int colideIndex = -1;
		//i => �߻�� ������ ž
		for (int j = i; j >= 0; j--)
		{
			//j => ��ȸ�ϸ� üũ�ϴ� ������ ž
			if (height[i] < height[j])
			{
				colideIndex = j + 1;
				break;
			}


		}

		if (colideIndex == -1)
			cout << 0 << " ";
		else
			cout << colideIndex <<" ";

	}




}

/*
5
6 9 5 7 4


*/