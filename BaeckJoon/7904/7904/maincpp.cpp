#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int CheckDigit(int index,int pre);
void FindDigitHafman(string encodingTotal, int original, int digit);
bool CheckMakeSence();
bool CheckIsTree();
void PrintResult();

int Z = 0, N = 0;
int maxDigit = 0;
string encodedResult[20];

class Node {
public:
	int index;
	string data;
	vector<Node> leaf;
	
};

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

		PrintResult();

		cout << "end\n";

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
	int next = pre + (int)pow(N-1,index);
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
	bool isok = false;

	if (original == Z - 1)
	{
		encodedResult[original] = encodingTotal;
		/*
		for (int i = 0; i < Z; i++)
		{
			cout << encodedResult[i]<<", ";
		}

		cout << "\n";
		*/
 		CheckMakeSence();

		//cout << "Make Senece : " << isok << "\n";

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

		if (isok)
			return;


		digit++;

	}

}

bool CheckMakeSence()
{
	for(int i=0;i<Z;i++)
	{
		//글자가 최대 글자수를 넘거나 없는지 확인
		if (encodedResult[i].length() > maxDigit || encodedResult[i].length() == 0)
		{
			return false;
		}

		/*
		//트리를 형성할수 있는지 확인
		for (int j = 0; j < Z; j++)
		{
			if (i == j || encodedResult[i].length() > encodedResult[j].length())
				continue;

			string targetSub = encodedResult[j].substr(0, encodedResult[j].length());


			//i가 j번째 문자열에 포함되는 형태이면 트리 생성이 불가능 하다
			if (targetSub == encodedResult[j])
				return false;z

		}
		*/


	}

	CheckIsTree();

	return true;
}

bool CheckIsTree()
{
	Node root;
	cout << "Checking Tree\n";
	for (int i = 0; i < Z; i++)
	{
		Node* targetNode = &root;

		cout << encodedResult[i] << endl;
		for (int j = 0; j < encodedResult[i].length(); j++)
		{
			int digitNumber = (int)encodedResult[i][j]-48;
			cout << digitNumber << endl;

			if (targetNode->leaf.size() == 0)
			{
				targetNode->leaf.resize(N);
			}

			targetNode = &targetNode->leaf[digitNumber];
			
			

		}
		

	}


	return false;
}

void PrintResult()
{
	for (int i = 0; i < Z; i++)
	{
		cout << i << "->" << encodedResult[i] << "\n";

	}
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