// hw1.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <vector>

using namespace std;

class Job {
public:
	int start;
	int end;
	int workTime;
};

void WorkBatchProccess(vector<Job> jobs,int N, int finalDay);


int main()
{
	int T = 0;
	cin >> T;


	//�׽�Ʈ ���̽� ����
	for (int i = 0; i < T; i++) {

		int N = 0;
		cin >> N;
		vector<Job> jobs;
		int finalDay = 0;

		//�۾� �ϼ� �޾ƿ���
		for (int j = 0; j < N; j++) {
			int si, ei, wi;

			cin >> si >> ei >> wi;

			Job jobTemp;
			jobTemp.start = si;
			jobTemp.end = ei;
			jobTemp.workTime = wi;
			jobs.push_back(jobTemp);

			if (ei > finalDay)
				finalDay = ei;

		}


		//��ġ ���μ���
		WorkBatchProccess(jobs,N, finalDay);


	}

	return 0;
}

void WorkBatchProccess(vector<Job> jobs, int N, int finalDay)
{
	vector<int> workQueue;
	

	//1�Ϻ��� ������ ������ ����
	for (int day = 1; day < finalDay+1; day++) 
	{

		//���۳��� ���� ���� ���� ��쿡 �۾� ��ġ
		for (int j = 0; j < N; j++)
		{
			if (jobs[j].start == day) 
			{
				cout << jobs[j].start << ", " << jobs[j].end << ", " << jobs[j].workTime << endl;
				workQueue.push_back(j);
			}
				
		}

	}


}

/*
3
3
1 3 8
2 2 8
3 3 8
4
1 2 10
2 4 20
1 3 5
3 4 5
5
1 5 16
2 4 4
3 4 16
1 2 4
4 6 4

Yes
No
Yes
*/