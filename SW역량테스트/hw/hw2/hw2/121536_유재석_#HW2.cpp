#include <iostream>

using namespace std;

int main() {

	int T = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {

		bool result = true;

		int x, y, time;

		cin >> x >> y >> time;

		int minStep = abs(x) + abs(y);

		//cout << minStep << endl;

		//시간이 최소 이동 거리 보다 작을때
		if (time < minStep)
			result = false;
		else { //갈수는 있을 때
			int defStep = time - minStep;

			//도착하고 나서의 차이가 홀수 일때
			if (defStep % 2 == 1)
				result = false;
		}


		if (result)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	return 0;
}

/*
4
-5 -2 7
5 -5 2
0 5 6
1 2 7

YES
NO
NO
YES
*/