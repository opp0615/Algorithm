// kakao_secretmap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n = 0;

	cin >> n;
	
	vector<int> arr1;
	vector<int> arr2;

	for (int i = 0; i < n; i++)
	{
		int arr1_item = 0;
		cin >> arr1_item;

		arr1.push_back(arr1_item);
	}

	for (int i = 0; i < n; i++)
	{
		int arr2_item = 0;
		cin >> arr2_item;

		arr2.push_back(arr2_item);
	}


	for (int i = 0; i < n; i++)
	{
		int first_value = arr1[i];
		int second_value = arr2[i];

		vector<int> first;
		vector<int> second;

		while (first_value != 0) {
			first.push_back(first_value % 2);
			first_value /= 2;
		}

		while (first.size() < 5) {
			first.push_back(0);
		}
		reverse(first.begin(), first.end());

		while (second_value != 0) {
			second.push_back(second_value % 2);
			second_value /= 2;
		}
		while(second.size() < 5) {
			second.push_back(0);
		}

		reverse(second.begin(), second.end());

		for (int i = 0; i < 5; i++) {
			if ((first[i] || second[i]) == 0) {
				cout << 'n';
			}
			else {
				cout << '#';
			}
		}
		cout << endl;

	}

	for (int i = 0; i < n; i++)
	{

		//bit or 연산
		int bit = 0;
		//10진수를 bit or연산을 하면 비트 연산이 되어서 바뀐다
		bit = (arr1[i] | arr2[i]);

		cout<< bit <<endl;

		vector<char> result;

		for (int j = 0; j < n; j++)
		{
			if (bit % 2 == 0)
				result.push_back(' ');
			else
				result.push_back('#');

			//shift연산을 하면 2로 나눈것과 같은 효과
			bit = bit >> 1;
		}

	}


}

/*
5
9 20 28 18 11
30 1 21 17 28


6
46 33 33 22 31 50
27 56 19 14 14 10
*/

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
