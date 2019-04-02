#include <iostream>
#include <vector>
using namespace std;


Rect CheckLeft(vector<Rect> & totalRect, int index);
Rect CheckRight(vector<Rect> & totalRect, int index);

class Rect {
public:
	int width;
	int height;
};

int main()
{
	int N = 0;
	
	cin >> N;
	
	int preX = 0;
	int preY = 0;
	int postX = 0;
	int postY = 0;

	vector<Rect> totalRect;
	Rect thisRect;
	thisRect.width = 0; thisRect.height = 0;

	//사각형 만들기
	for (int i = 0; i < N; i++) {


		int x, y = 0;
		
		cin >> x >> y;

		if (i == 0) {
			preX = x;
			preY = y;
			continue;
		}

		postX = x;
		postY = y;
		
		
		if ((postX - preX) == 0) {
			thisRect.height = postY;
		}
		else if ((postY - preY ) == 0) {
			thisRect.width = postX-preX;
		}

		if (thisRect.width * thisRect.height != 0) {
			totalRect.push_back(thisRect);
			thisRect.width = 0; thisRect.height = 0;
		}

		preX = postX;
		preY = postY;
	}

	for (int i= 0; i < totalRect.size; i++) 
	{
		Rect leftRect = CheckLeft(totalRect, i);
		Rect rightRect = CheckRight(totalRect, i);


	}


	return 0;
}


Rect CheckLeft(vector<Rect> & totalRect, int index) {
	
}

Rect CheckRight(vector<Rect> & totalRect, int index) {

}