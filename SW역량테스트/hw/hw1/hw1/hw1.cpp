// hw1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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


	//테스트 케이스 진행
	for (int i = 0; i < T; i++) {

		int N = 0;
		cin >> N;
		vector<Job> jobs;
		int finalDay = 0;

		//작업 일수 받아오기
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

		//배치 프로세스
		bool result = WorkBatchProccess(jobs,N, finalDay);

		string resultText = result ? "Yes" : "No";

		cout << resultText << endl;

	}

	return 0;
}

bool WorkBatchProccess(vector<Job> jobs, int N, int finalDay)
{
	//작업 큐
	vector<Job> workQueue;
	

	//1일부터 끝나는 날까지 진행
	for (int day = 1; day < finalDay+1; day++) 
	{
		//하루에 8시간 일할 수 있음
		int dayWorkTime = 8;
		
		//시작날이 지금 날과 같은 경우에 작업 배치
		for (int j = 0; j < N; j++)
		{
			if (jobs[j].start == day) 
			{
				
				workQueue.push_back(jobs[j]);
			}
		}

		//끝날이 이른 순서대로 정렬
		sort(workQueue.begin(), workQueue.end());


		//정렬된 큐를 돌면서 하루 8시간씩 작업
		for (vector<Job>::iterator iter = workQueue.begin(); iter != workQueue.end(); )
		{
			//cout << iter->start << ", " << iter->end << ", " << iter->workTime<<endl;

			//남은 일할 수 있는 시간 보다 일해야 하는 시간이 클 때
			if (iter->workTime > dayWorkTime)
			{
				iter->workTime -= dayWorkTime;
				break;
			}
			//남은 일할 수 있는 시간보다 일해야 하는 시간이 작거을 때
			else if(iter->workTime < dayWorkTime)
			{
				dayWorkTime -= iter->workTime;

				//해당 작업 지우고 다음 작업으로
				iter = workQueue.erase(iter);
			}
			//남을 일할 수 있는 시간과 일해야하는 시간이 같을 때
			else 
			{
				iter = workQueue.erase(iter);
				break;
			}

		}

	}

	//작업을 다 처리했으면 true
	if (workQueue.size() == 0)
	{
		return true;
	}
	//못했으면 false
	else {
		return false;
	}

}

/*
테스트 케이스
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