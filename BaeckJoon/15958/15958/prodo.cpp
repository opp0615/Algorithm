#include <iostream>
#include <vector>
using namespace std;

class Rect {
public:
	int width;
	int height;
};

int CheckLeft(vector<Rect> & totalRect, int index);
int CheckRight(vector<Rect> & totalRect, int index);


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

	int maxSize = -99999;

	for (int i= 0; i < totalRect.size(); i++) 
	{
		int thisSize = totalRect[i].width * totalRect[i].height;
		int leftSize = CheckLeft(totalRect, i);
		int rightSize = CheckRight(totalRect, i);
		int thisSideSize = 0;

		if (leftSize > rightSize)
			thisSideSize = leftSize;
		else
			thisSideSize = rightSize;


		int thisTotalSize = thisSize + thisSideSize;

		if (thisTotalSize > maxSize)
			maxSize = thisTotalSize;

	}

	cout << maxSize << endl;


	return 0;
}


int CheckLeft(vector<Rect> & totalRect, int index) {
	
	if (index-1 < 0)
		return 0;

	int maxSize = 0;
	int totalWidth = 0;
	int minHeight = totalRect[index].height;

	for (int i = index-1; i >= 0; i--) 
	{
		totalWidth += totalRect[i].width;

		if (totalRect[i].height < minHeight)
			minHeight = totalRect[i].height;

		int thisSize = totalWidth * minHeight;

		if (maxSize < thisSize)
			maxSize = thisSize;

	}

	return maxSize;

}

int CheckRight(vector<Rect> & totalRect, int index) {

	if (index+1 > totalRect.size())
		return 0;

	int maxSize = 0;
	int totalWidth = 0;
	int minHeight = totalRect[index].height;

	for (int i = index+1; i < totalRect.size(); i++)
	{
		totalWidth += totalRect[i].width;

		if (totalRect[i].height < minHeight)
			minHeight = totalRect[i].height;

		int thisSize = totalWidth * minHeight;

		if (maxSize < thisSize)
			maxSize = thisSize;
	}

	return maxSize;
}