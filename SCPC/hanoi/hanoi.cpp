// hanoi.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int Answer;

int main()
{
	int T, test_case;

	int N = 0;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using cin function.
	You may remove the comment symbols(//) in the below statement and use it.
	Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		N = 0;
		//plate input
		scanf("%d ", &N);
		bool isABC = false;
		int step = 0;
		for (int j = 0; j < N; j++)
		{
			char inputC;
			scanf("%c", &inputC);


			//ABC연이어서 나오면

			switch (step)
			{
			case 0:
				if (inputC == 'A')
				{
					step++;
					break;
				}
			case 1:
				if (inputC == 'B')
				{
					step++;
					break;
				}
				else if (inputC == 'C')
				{
					step--;
					break;
				}
			case 2:
				if (inputC == 'C')
				{
					isABC = true;
					step++;
					break;
				}
				else if (inputC == 'A')
				{
					isABC = false;
					step = 1;
				}
				else if (inputC == 'B')
				{
					isABC = false;
					step = 0;
				}
			case 3:
				break;
			default:
				break;
			}

		}
		//enter remove
		char inputC;
		scanf("%c", &inputC);


		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;

		if (!isABC)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

}

