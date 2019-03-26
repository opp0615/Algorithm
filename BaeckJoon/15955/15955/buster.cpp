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


	//두 지점의 거리가 hp 보다 작으면 한번에 갈 수 있음
	if (distance2 <= hp * hp)
		return true;

	//다음 지점 까지 한번에 부스터로 갈 수 있음
	if (pre.x == next.x || pre.y == next.y)
		return true;

	//hp만큼 움직였을 때 부스터로 갈 수 있음
	
	if (abs(pre.x - next.x) <= hp || abs(pre.y - next.y) <= hp)
		return true;


	//아닌 경우는 포인트로 갈 수 없는 경우임 
	return false;

}

//시작노드에서 끝 노드까지 가는 길이 있는지 찾음
bool FindResult(int startIndex, int endIndex, int hp, vector<CheckPoint> &checkpoint, vector<char> isVisited)
{
	bool result = false;

	//마지막 노드까지 왔으면 갈수 있는 것
	if (startIndex == endIndex)
		return true;

	//방문한 체크포인트
	isVisited[startIndex] = 1;

	for (int i = 0; i < N; i++)
	{
		//방문한 노드가 아니면 자식 노드로 넘어감
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