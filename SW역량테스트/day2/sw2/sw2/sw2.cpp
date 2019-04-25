// sw2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<string>

using namespace std;

int main()
{
    cout << "Hello World!\n"; 


	//벡터
	cout << "벡터" << endl;
	vector<int>v;

	v.push_back(13);
	v.push_back(21);
	v.push_back(29);

	//포인터라고 생각하면 좋음 변수 형이 모를 때 쓸 때 좋다
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	//앞에도 넣을 수 있는 벡터
	deque<int> dq;


	//리스트
	cout << "리스트" << endl;
	list<int> lt;

	lt.push_back(123);
	lt.push_front(321);
	lt.push_back(456);
	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++)
	{
		cout << *iter << endl;
	}

	//내림차순
	cout << "리스트 sort 내림차순" << endl;
	lt.sort();
	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++)
	{
		cout << *iter << endl;
	}

	//오름차순
	cout << "리스트 sort 오름차순" << endl;
	lt.sort(greater<int>());

	for (list<int>::iterator iter = lt.begin(); iter != lt.end(); iter++)
	{
		cout << *iter << endl;
	}


	//set은 바이너리 트리 구조이고, 중복을 허용하지 않는다
	cout << "set" << endl;
	set<int> s;
	
	s.insert(4);
	s.insert(1);
	s.insert(2);

	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << endl;
	}
	

	//map key, value값을 가지는 자료구조
	//pair와 함께 많이 쓴다
	cout << "map" << endl;

	map<string, int> m;

	m.insert(pair<string, int>("key1", 1));
	m.insert(pair<string, int>("key2", 2));
	m.insert(pair<string, int>("key3", 3));


	for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
	{
		//pair에 first, second가 있다
		cout << iter->first << ", " << iter->second << endl;
	}


	pair<int, string> p1 = make_pair(1, "value1");
	pair<int, string> p2 = make_pair(2, "value2");

		

	return 0;
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
;