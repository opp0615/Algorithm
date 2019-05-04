// hw1.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Job {
public:
	int start;
	int end;
	int workTime;

	bool operator <(Job& job) {
		return this->end < job.end;
	}
};

bool WorkBatchProccess(vector<Job> jobs,int N, int finalDay);


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
		bool result = WorkBatchProccess(jobs,N, finalDay);

		string resultText = result ? "Yes" : "No";

		cout << resultText << endl;

	}

	return 0;
}

bool WorkBatchProccess(vector<Job> jobs, int N, int finalDay)
{
	//�۾� ť
	vector<Job> workQueue;
	

	//1�Ϻ��� ������ ������ ����
	for (int day = 1; day < finalDay+1; day++) 
	{
		//�Ϸ翡 8�ð� ���� �� ����
		int dayWorkTime = 8;
		
		//���۳��� ���� ���� ���� ��쿡 �۾� ��ġ
		for (int j = 0; j < N; j++)
		{
			if (jobs[j].start == day) 
			{
				
				workQueue.push_back(jobs[j]);
			}
		}

		//������ �̸� ������� ����
		sort(workQueue.begin(), workQueue.end());


		//���ĵ� ť�� ���鼭 �Ϸ� 8�ð��� �۾�
		for (vector<Job>::iterator iter = workQueue.begin(); iter != workQueue.end(); )
		{
			//cout << iter->start << ", " << iter->end << ", " << iter->workTime<<endl;

			//���� ���� �� �ִ� �ð� ���� ���ؾ� �ϴ� �ð��� Ŭ ��
			if (iter->workTime > dayWorkTime)
			{
				iter->workTime -= dayWorkTime;
				break;
			}
			//���� ���� �� �ִ� �ð����� ���ؾ� �ϴ� �ð��� �۰��� ��
			else if(iter->workTime < dayWorkTime)
			{
				dayWorkTime -= iter->workTime;

				//�ش� �۾� ����� ���� �۾�����
				iter = workQueue.erase(iter);
			}
			//���� ���� �� �ִ� �ð��� ���ؾ��ϴ� �ð��� ���� ��
			else 
			{
				iter = workQueue.erase(iter);
				break;
			}

		}

	}

	//�۾��� �� ó�������� true
	if (workQueue.size() == 0)
	{
		return true;
	}
	//�������� false
	else {
		return false;
	}

}

/*
�׽�Ʈ ���̽�
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