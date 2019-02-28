#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

int CheckDigit(int index,int pre);
bool FindDigitHafman(string encodingTotal, int original, int digit);
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
		

		//���Ͽ� ����ִ� ���� �ٸ� ������ ����
		cin >> Z;
		//������ Ʈ���� arity
		cin >> N;

		//�ִ� ���� ��
		maxDigit = CheckDigit(1 ,1);

		//cout << "max : " << maxDigit << endl;

		string encodingTotal ;

		cin >> encodingTotal;

		FindDigitHafman(encodingTotal, 0, 1);


		//cout << "end\n";

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

bool FindDigitHafman(string encodingTotal, int original, int digit)
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

		isok = CheckMakeSence();
		if(isok)
			PrintResult();

		//cout << "Make Senece : " << isok << "\n";

		return isok;
	}


	for (int i = 0; i < maxDigit; i++)
	{

		string encodingTemp;

		//���� ����ŭ �̾Ƴ���
		for (int j = 0; j < digit; j++)
		{
			encodingTemp += encodingTotal[j];
		}

		encodedResult[original] = encodingTemp;

		//������ ���ڿ�
		string subEncoding = encodingTotal.substr(digit, encodingTotal.length() - digit);


		isok = FindDigitHafman(subEncoding, original + 1, 1);

		if (isok)
			return true;


		digit++;

	}

	return false;

}

bool CheckMakeSence()
{
	for(int i=0;i<Z;i++)
	{
		//���ڰ� �ִ� ���ڼ��� �Ѱų� ������ Ȯ��
		if (encodedResult[i].length() > maxDigit || encodedResult[i].length() == 0)
		{
			return false;
		}

		/*

		for (int j = 0; j < Z; j++)
		{
			if (i == j || encodedResult[i].length() > encodedResult[j].length())
				continue;

			string targetSub = encodedResult[j].substr(0, encodedResult[j].length());


			//i�� j��° ���ڿ��� ���ԵǴ� �����̸� Ʈ�� ������ �Ұ��� �ϴ�
			if (targetSub == encodedResult[j])
				return false;z

		}
		*/


	}
	//Ʈ���� �����Ҽ� �ִ��� Ȯ��
	return CheckIsTree();

}

bool CheckIsTree()
{
	Node root;
	root.leaf.resize(N);
	int totalCount = 0;
	//cout << "Checking Tree\n";
	for (int i = 0; i < Z; i++)
	{
		Node* targetNode = &root;
		bool isLeefAdded = false;

		//cout << encodedResult[i] << endl;
		for (int j = 0; j < encodedResult[i].length(); j++)
		{
			int digitNumber = (int)encodedResult[i][j]-48;
			//cout << digitNumber << endl;

			if (targetNode->leaf.size() == 0)
			{
				//������ �߰��Ϸ��µ� �̹� �����Ͱ� ��忡 ������
				if (targetNode->data != "")
				{
					//cout << "������ �߰��Ϸ��µ� �̹� �����Ͱ� ��忡 ������" << endl;
					return false;
				}
				isLeefAdded = true;
				targetNode->leaf.resize(N);
			}

			targetNode = &targetNode->leaf[digitNumber];
			
		}

		//�����͸� �������µ� ������忡 ���� ����
		if (targetNode->leaf.size() != 0)
		{
			//cout << "�����͸� �������µ� ������忡 ���� ����" << endl;
			return false;
		}

		//�����͸� �ִ� ���μ���
		targetNode->index = i;
		targetNode->data = encodedResult[i];

		
		if (!isLeefAdded) //������ �߰��Ѱ� �ƴ϶� �����͸� �ֱ⸸ ��
			totalCount++;
		else  //������ �߰���
			totalCount += N-1;

	}

	if (totalCount != Z)
	{
		//cout << "����� ������ Z�� ��������" << endl;
		return false;
	}


	return true;
}

void PrintResult()
{
	for (int i = 0; i < Z; i++)
	{
		cout << i << "->" << encodedResult[i] << "\n";

	}
}


//�Է�
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


//���
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