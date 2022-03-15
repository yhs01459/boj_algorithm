#include<iostream>
#include<string>

using namespace std;

int main() {
	int n; // 입력받는 숫자의 개수
	string k; //입력으로 주어지는 정수k
	int num; //문자열로 주어지는 숫자의 첫번째 자리를 저장할 변수
	cin >> n;

	//n만큼 반복
	for (int i = 0; i < n; i++) { 
		cin >> k;
		num = (k[k.size() - 1]) - '0'; // 첫번째 자리를 숫자로 변환 후 저장
		if (num % 2 == 0) { // 첫번째 자리가 짝수라면 even 출력
			cout << "even";
		}
		else {
			cout << "odd"; //홀수라면 odd 출력
		}
		cout << endl;
	}
	return 0;
	
}

/* 
* 입의 범위가 1~10^60 이기때문에 int,double 등 정수형 타입이 다룰 수 있는 범위를 넘어선다.
* 그로인해 string으로 입력받아 마지막자리만 숫자로 변경하여 짝수면 even, 홀수면 odd를 출력하도록 프로그래밍 한다.
* 
*/