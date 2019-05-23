#include <iostream>
#include <map>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int K = 0;
	int L = 0;

	cin >> L >> K;

	map<string, int> m;
	vector<pair<int, string>> result;

	for (int i = 0; i < K; i++)
	{
		string studentnubmer;
		cin >> studentnubmer;

		m[studentnubmer] = i;

	}


	for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
	{
		//cout << iter->first << ", " << iter->second << endl;
		result.push_back(make_pair(iter->second, iter->first));

	}

	//정렬
	sort(result.begin(), result.end());

	int count = 0;

	for (vector<pair<int, string>>::iterator iter = result.begin(); iter != result.end(); iter++)
	{
		//L번째 까지 출력
		if (count >= L)
			break;
		cout << iter->second << endl;
		count++;
	}


}