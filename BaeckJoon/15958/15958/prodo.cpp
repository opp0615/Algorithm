
//왼쪽 최대 크기 오른쪽 최대크기를 구하는 알고리즘
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


//왼쪽 오른쪽의 최소 높이와 크기를 미리 저장하고 바로 값을 가져와 쓰는 알고리즘
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
int leftMinIndex[500000];
int leftMinSize[500000];
int rightMinIndex[500000];
int rightMinSize[500000];

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

	int rectCount = 0;

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
			totalRect[rectCount]=thisRect;

			thisRect.width = 0; thisRect.height = 0;
			rectCount++;
		}

		preX = postX;
		preY = postY;
	}

	int maxSize = -99999;

	int minIndex = -1;
	int minHeight = 9999;
	int stackedWidth = 0;
	//왼쪽 최소 인덱스, 최소높이로 정해지는 최대 크기 설정
	for (int i= 0; i < rectCount; i++)
	{
		if (totalRect[i].height < minHeight) {
			minIndex = i;
			minHeight = totalRect[i].height;
		}

		stackedWidth += totalRect[i].width;
		leftMinIndex[i] = minIndex;
		leftMinSize[i] = stackedWidth * minHeight;

	}

	minIndex = -1;
	minHeight = 9999;
	stackedWidth = 0;
	//오른쪽 최소 인덱스,최소높이로 정해지는 최대 크기 설정
	for (int i = rectCount-1; i >= 0; i--)
	{
		if (totalRect[i].height < minHeight) {
			minIndex = i;
			minHeight = totalRect[i].height;
		}

		stackedWidth += totalRect[i].width;
		rightMinIndex[i] = minIndex;
		rightMinSize[i] = stackedWidth * minHeight;

	}


	//최대 L 크기 판별
	for (int i = 0; i < rectCount; i++)
	{
		int leftSize = CheckLeft(i);
		int rightSize = CheckRight(i);
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


int CheckLeft(int index) {


	int maxSize = 0;
	int totalWidth = 0;
	int minHeight = totalRect[index].height;

	for (int i = index; i >= 0; i--)
	{

		if (leftMinIndex[i] == i) {
			return leftMinSize[i];
		}

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
		if (rightMinIndex[i] == i) {
			return rightMinSize[i];
		}

		totalWidth += totalRect[i].width;

		if (totalRect[i].height < minHeight)
			minHeight = totalRect[i].height;

		int thisSize = totalWidth * minHeight;

		if (maxSize < thisSize)
			maxSize = thisSize;
	}

	return maxSize;
}
