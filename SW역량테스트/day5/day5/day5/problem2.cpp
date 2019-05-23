#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

class WorkPair
{
public:
	int index;
	int priority;
};

int main()
{
	int T = 0;

	cin >> T;

	deque<WorkPair> workVector;

	for (int i = 0; i < T; i++)
	{
		int priority = 0;
		cin >> priority;

		WorkPair pair;
		pair.index = i;
		pair.priority = priority;

		workVector.push_back(pair);
			   
	}



	int targetIndex = 0;
	cin >> targetIndex;



	int count = 0;
	while (!workVector.empty())
	{
		WorkPair thisNode = workVector.front();
		workVector.pop_front();
		

		bool isPrintable = true;
		

		for (int i = 0; i < workVector.size(); i++)
		{
			if (workVector[i].priority > thisNode.priority)
			{
				workVector.push_back(thisNode);
				isPrintable = false;
			}
		}


		if (isPrintable)
		{
			count++;
			if (thisNode.index == targetIndex)
				cout << count << endl;
		}


	}




}

/*
4
2 1 3 2
2

1

6
1 1 9 1 1 1
0

5


*/