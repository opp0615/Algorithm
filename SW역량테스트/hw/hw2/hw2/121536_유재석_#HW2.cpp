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

		//�ð��� �ּ� �̵� �Ÿ� ���� ������
		if (time < minStep)
			result = false;
		else { //������ ���� ��
			int defStep = time - minStep;

			//�����ϰ� ������ ���̰� Ȧ�� �϶�
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