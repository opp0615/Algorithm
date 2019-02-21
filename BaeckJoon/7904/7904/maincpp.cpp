#include <iostream>
#include <string>

using namespace std;

int CheckDigit(int index,int pre);
void FindDigitHafman(string encodingTotal, int original, int digit);
bool CheckMakeSence();

int Z = 0, N = 0;
int maxDigit = 0;
string encodedResult[20];

int main()
{
	int T = 0;
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		

		//파일에 들어있는 서로 다른 글자의 개수
		cin >> Z;
		//허프만 트리의 arity
		cin >> N;

		//최대 글자 수
		maxDigit = CheckDigit(1 ,1);


		string encodingTotal ;

		cin >> encodingTotal;

		FindDigitHafman(encodingTotal, 0, 1);

		/*
		cout << FindDigitHafman(encodingTotal, 0, 1) << "\n";
		cout << FindDigitHafman(encodingTotal, 1, 1) << "\n";
		cout << FindDigitHafman(encodingTotal, 2, 1) << "\n";
		*/
	}


	return 0;
}

int CheckDigit(int index, int pre)
{
	int next = pre + N^index;
	if (Z <= next)
	{
		return index;
	}
	else
	{
		index++;
		index = CheckDigit(index, next);
		return index;
	}

	return -1;

}

void FindDigitHafman(string encodingTotal, int original, int digit)
{
	if (original == Z - 1)
	{
		encodedResult[original] = encodingTotal;
		
		for (int i = 0; i < Z; i++)
		{
			cout << encodedResult[i]<<", ";
		}

		cout << "\n";

		bool isok = CheckMakeSence();

		cout << "Make Senece : " << isok << "\n";

		return;
	}


	for (int i = 0; i < maxDigit; i++)
	{

		string encodingTemp;

		//글자 수만큼 뽑아내기
		for (int j = 0; j < digit; j++)
		{
			encodingTemp += encodingTotal[j];
		}

		encodedResult[original] = encodingTemp;

		//나머지 문자열
		string subEncoding = encodingTotal.substr(digit, encodingTotal.length() - digit);


		FindDigitHafman(subEncoding, original + 1, 1);

		digit++;

	}

}

bool CheckMakeSence()
{
	for(int i=0;i<Z;i++)
	{
		//글자가 최대 글자수를 넘는지 확인
		if (encodedResult[i].length() > maxDigit)
		{
			return false;
		}
	}

	return true;
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