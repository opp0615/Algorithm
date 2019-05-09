// day3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;

int main()
{
	vector <int> v;

	
    std::cout << "Hello World!\n"; 

	//정렬
	//sort(begin,end,compare)
	//partial_sort(begin, begin + n, end)
	//is_sorted => 오름차순 : true, 내림차순 : false


	//unmodyfing sequence 값 안바뀌는 접근
	//find(begin,end,값 조건)
	//find_if(being,end,함수 조건)
	//count(begin,end,값 조건)
	//count_if(begin,end,함수 조건)
	//search(전체begin,전체end,찾을려는begin,찾을려는end)

	//modyfing sequence 값 바꾸는 접근
	//copy(대상begin,대상end,복사하는begin)
	//copy_if(대상begin,대상end,복사하는begin,조건함수)
	//swap(바꿀것1,바꿀것2) 형식만 맞추면 됨
	//remove(begin,end,조건 값)
	//remove_if(begin,end,조건 함수)
	//transfrom(a.begin,a.end, b.begin, ::toupper or :::tolower)


	//min,max
	//min(범위 시작,범위 끝)
	//max(범위 시작, 범위 끝)
	//minmax(범위 시작,범위 끝) => first : min, second : max

	//cmath
	//abs 절대값
	//ceil 올림
	//floor 버림
	//round 반올림

	//cctpye
	//isalnum 알파 넘버냐
	//isalpha 알파벳이냐
	//islower 소문자냐
	//isupper 대문자냐
	//tolower 소문자로 만들기
	//toupper 대문자로만들기


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
