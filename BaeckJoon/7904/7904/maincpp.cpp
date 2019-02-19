#include <iostream>
#include <string>

using namespace std;

int CheckDigit(int index,int pre, int Z, int N);

int main()
{
	int T = 0;
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int Z = 0, N = 0;

		//파일에 들어있는 서로 다른 글자의 개수
		cin >> Z;
		//허프만 트리의 arity
		cin >> N;
		int digit = 0;
		digit = CheckDigit(1 ,1 ,Z, N);

		cout << digit << "\n";

		string encoding ;

		cin >> encoding;

	}


	return 0;
}

int CheckDigit(int index, int pre, int Z, int N)
{
	int next = pre + N^index;
	if (Z <= next)
	{
		return index;
	}
	else
	{
		index++;
		index = CheckDigit(index, next, Z, N);
		return index;
	}

	return -1;

}


//입력
/*
3
3
2
10011
4
2
000111010
19
10
01234678950515253545556575859
*/


//출력
/*
0->10
1->0
2->11
0->00
1->011
2->1
3->010
0->0
1->1
2->2
3->3
4->4
5->6
6->7
7->8
8->9
9->50
10->51
11->52
12->53
13->54
14->55
15->56
16->57
17->58
18->59
*/