#include <iostream>
#include <vector>


using namespace std;


class CheckPoint {
public:
	int x;
	int y;
};

int main()
{
	int N = 0, Q = 0;

	cin >> N >> Q;

	vector<CheckPoint> checkpoint;

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
		cout << checkpoint[preIndex].x << ", " << checkpoint[preIndex].y << endl;
		cout << checkpoint[postIndex].x << ", " << checkpoint[postIndex].y << endl;
		cout << hp << endl;

	}
	return 0;
}