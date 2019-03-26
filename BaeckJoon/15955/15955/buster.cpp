#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class CheckPoint {
public:
	int x;
	int y;
};

int N = 0, Q = 0;
bool pathExist = false;

bool CheckPreToNext(CheckPoint pre, CheckPoint next, int hp);
bool FindResult(int startIndex, int endIndex, int hp, vector<CheckPoint> &checkpoint,  vector<char> isVisited);

int main()
{

	vector<CheckPoint> checkpoint;
	cin >> N >> Q;

	for(int i=0;i<N;i++)
	{
		CheckPoint tempCheck;

		cin >> tempCheck.x >> tempCheck.y;

		checkpoint.push_back(tempCheck);
	}


	for (int i = 0; i < Q; i++)
	{
		int preIndex = -1, postIndex = -1, hp = -1;

		cin >> preIndex >> postIndex >> hp;
		preIndex--;
		postIndex--;

		bool resultCheck = false;

		vector<char> isVisited(N);
		pathExist = false;
		FindResult(preIndex, postIndex, hp, checkpoint,isVisited);

		if (pathExist)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	checkpoint.clear();


	return 0;
}

bool CheckPreToNext(CheckPoint pre, CheckPoint next, int hp)
{
	double distance2 = (pre.x - next.x)*(pre.x - next.x) + (pre.y - next.y)*(pre.y - next.y);


	//�� ������ �Ÿ��� hp ���� ������ �ѹ��� �� �� ����
	if (distance2 <= hp * hp)
		return true;

	//���� ���� ���� �ѹ��� �ν��ͷ� �� �� ����
	if (pre.x == next.x || pre.y == next.y)
		return true;

	//hp��ŭ �������� �� �ν��ͷ� �� �� ����
	
	if (abs(pre.x - next.x) <= hp || abs(pre.y - next.y) <= hp)
		return true;


	//�ƴ� ���� ����Ʈ�� �� �� ���� ����� 
	return false;

}

//���۳�忡�� �� ������ ���� ���� �ִ��� ã��
bool FindResult(int startIndex, int endIndex, int hp, vector<CheckPoint> &checkpoint, vector<char> isVisited)
{
	bool result = false;

	//������ ������ ������ ���� �ִ� ��
	if (startIndex == endIndex)
		return true;

	//�湮�� üũ����Ʈ
	isVisited[startIndex] = 1;

	for (int i = 0; i < N; i++)
	{
		//�湮�� ��尡 �ƴϸ� �ڽ� ���� �Ѿ
		if (isVisited[i] == 0) 
		{
			bool isok = false;
			isok = CheckPreToNext(checkpoint[startIndex], checkpoint[i], hp);

			if (isok)
			{
				result = FindResult(i, endIndex, hp, checkpoint,isVisited);
				if (result)
					pathExist = true;
			}

		}
	}

	isVisited.clear();

	return result;
}