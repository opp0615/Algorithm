
/*
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

*/


#include <iostream>
#include <vector>
using namespace std;

class Rect {
public:
	int width;
	int height;
};

int N = 0;
Rect totalRect[500000];

int CheckLeft(int index);
int CheckRight(int index);


int main()
{

	cin >> N;

	int preX = 0;
	int preY = 0;
	int postX = 0;
	int postY = 0;

	Rect thisRect;
	thisRect.width = 0; thisRect.height = 0;

	int j = 0;

	int rectMaxSize = -9999;
	int rectMaxIndex = 0;

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
			totalRect[j]=thisRect;
			if (thisRect.width*thisRect.height > rectMaxSize) {
				rectMaxIndex = j;
				rectMaxSize = thisRect.width*thisRect.height;
			}

			thisRect.width = 0; thisRect.height = 0;
			j++;
		}

		preX = postX;
		preY = postY;
	}

	int maxSize = -99999;



	
	for (int i= 0; i < N; i++)
	{
		int thisSize = totalRect[i].width * totalRect[i].height;
		int rightSize = CheckRight(i);

		int thisTotalSize = thisSize + rightSize;

		if (thisTotalSize > maxSize)
			maxSize = thisTotalSize;

	}
	
	for (int i = N - 1; i > 0; i--)
	{
		int thisSize = totalRect[i].width * totalRect[i].height;
		int leftSize = CheckLeft(i);

		int thisTotalSize = thisSize + leftSize;

		if (thisTotalSize > maxSize)
			maxSize = thisTotalSize;
	}

	


	cout << maxSize << endl;


	return 0;
}


int CheckLeft(int index) {

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

int CheckRight(int index) {

	if (index+1 > N)
		return 0;

	int maxSize = 0;
	int totalWidth = 0;
	int minHeight = totalRect[index].height;

	for (int i = index+1; i < N; i++)
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
