// ACM Craft.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//1005번

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//역트리
/*
class Node {
public:
	int buildTime;
	vector<int> ptr;
	Node();
	~Node();
};

int FindMax(Node* object,int index);

int main()
{

	int T = 0;
	Node* object = NULL;
	cin >> T;

	for (int i = 0; i < T; i++) 
	{

		int N = 0, K = 0;

		cin >> N >> K;

		object = new Node[N+1];

		for (int j = 0; j < N; j++) 
		{
			int time = 0;
			cin >> time;
			object[j+1].buildTime = time;
		}

		for (int j = 0; j < K; j++)
		{
			int buildA=0, buildB = 0;

			cin >> buildA >> buildB;

			object[buildB].ptr.push_back(buildA);

		}

		
		for (int j = 0; j < N; j++)
		{
			cout <<"Parent : "<< j + 1 << " => " << object[j + 1].buildTime<<"\n";

			for (int k = 0; k < object[j + 1].ptr.size(); k++) {
				cout << "Child : " << object[j + 1].ptr[k] << " => " << object[object[j + 1].ptr[k]].buildTime << "\n";
			}
		}
		


		//victory
		int W = 0;
		cin >> W;

		cout<<FindMax(object,W)<<"\n";

		delete [] object;

	}

}



Node::Node() 
{
	buildTime = 0;
}

Node::~Node()
{
	ptr.clear();
}


int FindMax(Node* object,int index) 
{
	int max = 0;

	cout << "Find :  " <<index<< "\n";

	if (object[index].ptr.size() == 0)
		return object[index].buildTime;

	max += object[index].buildTime;

	int stepMax = -9999;

	for (int i = 0; i < object[index].ptr.size(); i++)
	{
		int tempMax = FindMax(object, object[index].ptr[i]);

		if (tempMax > stepMax)
		{
			stepMax = tempMax;
		}

	}
		
	max += stepMax;

	return max;
		
}
*/


//트리
 /*
int main()
{
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{

		int N = 0, K = 0;

		cin >> N >> K;

		int* buildTimes = new int[N + 1];
		vector < vector<int>> tier;
		int nowTier = 1;

		for (int j = 0; j < N; j++)
		{
			int time = 0;
			cin >> time;
			buildTimes[j + 1] = time;
			vector<int> tempVec;
			tier.push_back(tempVec);
		}

		//첫번재는 무조건 1이라는 가정

		tier[0].push_back(1);


		for (int j = 0; j < K; j++)
		{
			int buildA = 0, buildB = 0;

			cin >> buildA >> buildB;

			for (int k = 0; k < tier.size(); k++)
			{
				for (int l = 0; l < tier[k].size(); l++)
				{
					if (tier[k][l] == buildA)
					{
						tier[k + 1].push_back(buildB);
					}
				}
			}

		}

		int W = 0;
		cin >> W;


		int max = 0;
		bool isEnd = false;
		//find max
		for (int k = 0; k < tier.size(); k++)
		{
			int stepMax = -9999;
			for (int l = 0; l < tier[k].size(); l++)
			{
				if (tier[k][l] == W)
				{
					stepMax = buildTimes[tier[k][l]];
					isEnd = true;
					break;
				}

				if (buildTimes[tier[k][l]] > stepMax)
					stepMax = buildTimes[tier[k][l]];

			}
			max += stepMax;

			if (isEnd)
				break;
		}

		cout<< max << "\n";

	}
	

	return 0;
}

*/


//야매 
/*
class Node {
public:
	int buildTime;
	int needTimeMax;
	Node();
	void SetNeedTime(int time);
	int GetTotalTime();
};

int main()
{
	int T = 0;
	Node* object = NULL;
	cin >> T;

	for (int i = 0; i < T; i++)
	{

		int N = 0, K = 0;

		cin >> N >> K;

		object = new Node[N + 1];

		for (int j = 0; j < N; j++)
		{
			int time = 0;
			cin >> time;
			object[j + 1].buildTime = time;
		}

		for (int j = 0; j < K; j++)
		{
			int buildA = 0, buildB = 0;

			cin >> buildA >> buildB;

			object[buildB].SetNeedTime(object[buildA].GetTotalTime());


		}




		//victory
		int W = 0;
		cin >> W;

		cout << object[W].GetTotalTime()<<"\n";


		delete[] object;

	}



	return 0;
}

Node::Node()
{
	buildTime = 0;
	needTimeMax = 0;
}

void Node::SetNeedTime(int time)
{
	if (time > needTimeMax)
		needTimeMax = time;
}

int Node::GetTotalTime()
{
	return this->buildTime + this->needTimeMax;
}

*/

//위상정렬


int main()
{
	int T = 0;
	
	cin >> T;

	for (int i = 0; i < T; i++)
	{

		int N = 0, K = 0;

		cin >> N >> K;
		vector<int> object[1001];

		//indegree 자신에게 들어오는 간선의 수
		int buildTimes[1001], indegree[1001] = {0};

		for (int j = 0; j < N; j++)
		{
			int time = 0;
			cin >> time;
			buildTimes[j + 1] = time;
		}

		for (int j = 0; j < K; j++)
		{
			int buildA = 0, buildB = 0;

			cin >> buildA >> buildB;

			object[buildA].push_back(buildB);
			indegree[buildB]++;

		}

		//건물짓는 최소시간
		int minBuildTime[1001] = { 0 };
		queue<int> Q;

		for (int j = 1; j < N+1; j++)
		{
			//선행자가 없는 노드 큐에 추가
			if (indegree[j] == 0)
				Q.push(j);
		}

		//victory
		int W = 0;
		cin >> W;

		//목표건물의 선행자가 없어질때까지
		while (indegree[W] > 0)
		{
			int u = Q.front();
			Q.pop();

			for (int j = 0; j < object[u].size(); j++)
			{
				int next = object[u][j];
				//건물을 짓기 위해서는 부모노드의 최소 건설시간과 자신의 건설시간이 필요하다.
				minBuildTime[next] = max(minBuildTime[next], minBuildTime[u] + buildTimes[u]);
				indegree[next]--;
				if (indegree[next] == 0)
					Q.push(next);
			}

		}

		cout << minBuildTime[W] + buildTimes[W]<<"\n";

	}



	return 0;
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
