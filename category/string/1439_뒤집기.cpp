#include<iostream>
#include<map>


using namespace std;

int main() {
	string str;
	map<char, int> consecutiveCnt; //연속된 수를 저장
	int answer; // 최소 횟수
	cin >> str;

	char temp = str[0]; // 이전값을 비교하기 위한 임시변수
	consecutiveCnt[temp]++; 

	//수가 바뀌면 해당값을 저장
	for (int i = 1; i < str.size(); i++) {
		if (temp != str[i]) {
			consecutiveCnt[str[i]]++;
			temp = str[i];
		}
	}

	//한번도 뒤집어진 적이 없는 경우
	if (consecutiveCnt.size() == 1) {
		cout << 0;
	}
	//최솟값
	else {

		answer = min(consecutiveCnt['0'], consecutiveCnt['1']);
		cout << answer;
	}
	
	return 0;
}

/*
* 한번에 연속된 하나 이상의 숫자를 뒤집을 수 있다.
* 전부 같아질때까지 뒤집을때의 최소횟수 구하기
*/