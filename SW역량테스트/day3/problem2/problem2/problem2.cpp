// problem2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <locale>

using namespace std;

int main()
{
	string firstStr, secondStr;

	cin >> firstStr >> secondStr;

	for (int i = 0; i < firstStr.length(); i++) // transform쓰면 됨
	{
		firstStr[i] = tolower(firstStr[i]);
	}

	for (int i = 0; i < secondStr.length(); i++)
	{
		secondStr[i] = tolower(secondStr[i]);
	}


	cout << firstStr << ", " << secondStr << endl;

	vector<string> firstV, secondV;

	//두글자로 짜르기
	int all = 0;
	for (int i = 0; i < firstStr.length()-1; i++)
	{
		string tempstring = "";
		tempstring += firstStr[i];
		tempstring += firstStr[i + 1];

		cout << tempstring << endl;
		if (firstStr[i] > 'z' || firstStr[i]<'a' || firstStr[i+1] > 'z' || firstStr[i+1] < 'a')
		{
			cout << "특수문자 공백!!!" << endl;
		}
		else
		{
			firstV.push_back(tempstring);
			all++;
		}

	}
	
	for (int i = 0; i < secondStr.length(); i++)
	{
		string tempstring = "";
		tempstring += secondStr[i];
		tempstring += secondStr[i + 1];

		cout << tempstring << endl;
		if (secondStr[i] > 'z' || secondStr[i]<'a' || secondStr[i + 1] > 'z' || secondStr[i + 1] < 'a')
		{
			cout << "특수문자 공백!!!" << endl;
		}
		else 
		{
			secondV.push_back(tempstring);
			all++;
		}

		//강사님은 map으로 map에 값이 있으면 증가하는 방법을 사용하였다
	}



}

/*
FRANCE french
16384
handshake	shake hands	65536
aa1+aa2 AAAA12	
43690
E=M*C^2 e=m*c^2
65536

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
