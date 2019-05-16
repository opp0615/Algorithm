// problem3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//Queen Tracking

#include <iostream>

using namespace std;

//0~9
const int MAX = 9;
int map[MAX][MAX];
int N = 0;


bool CheckIsPosible(int x ,int y)
{
	//가로체크
	for (int i = 0; i < N; i++)
	{
		if (map[y][i] == 1)
			return false;
	}

	//세로 체크
	for (int i = 0; i < N; i++)
	{
		if (map[i][x] == 1)
			return false;
	}

	//대각 체크
	for (int i = 0; i < N; i++)
	{
		//오른쪽 아래
		if (map[y + i][x + i] && CheckBoundary(x+i,y+i))
			return false;

		//오른쪽 위
		if (map[y - i][x + i] && CheckBoundary(x + i, y - i))
			return false;

		//왼쪽 위
		if (map[y - i][x - i] && CheckBoundary(x - i, y - i))
			return false;

		//왼쪽 아래
		if (map[y + i][x - i] && CheckBoundary(x - i, y + i))
			return false;

	}
	return true;
}

bool CheckBoundary(int x, int y)
{
	if (x < 0 || x > 9 || y < 0 || y > 9)
		return false;
	else
		return true;
}



int main()
{

	cin >> N;

	//배열 초기화
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = 0;
		}
	}





}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
