#include<iostream>
#include<string>

using namespace std;



// 두 문자열의 차이를 출력하는 함수 
void printDiffrentAlp(string x, string y) {
	int count = 0; 
	for (int i = 0; i < x.size(); i++) {
		if (x[i] != y[i]) {
			count++;
		}
	}
	cout << count;
}

int main() {
	string x;
	string y;
	string z;

	cin >> x >> y; 

	//문자열 z 초기화
	for (int i = 0; i < y.size(); i++) {
		z.push_back(' ');
	}

	//문자열 x와 y의 크기가 같은 경우 차이를 출력
	if (x.size() == y.size()) {
		printDiffrentAlp(x,y);
	}
	//크기가 달라 문자열 x에 알파벳을 추가해야하는 경우 
	else {
		int index = 0; 
		int max = 0; 
		//x와 y 비교
		for (int i = 0; i < y.size()-x.size()+1; i++) {
			int countSameAlp = 0; //같은 문자를 count
			for (int j = 0; j < x.size(); j++) {
				if (x[j] == y[i+j]) {
					countSameAlp++;
				}
			}
			if (max < countSameAlp) {
				max = countSameAlp;
				index = i;
			}
		}
		z.replace(index,x.size(),x); // 해당 인덱스로부터 x의 크기만큼 문자열x로 대체

		//나머지 값은 y의 문자열에 맞춰준다.
		for (int i = 0; i < y.size(); i++) {
			if (z[i] == ' ') {
				z[i] = y[i];
			}
		}
		//y와 문자열 z의 차이 출력
		printDiffrentAlp(z, y);



	}
	return 0;
}

/*
x의 길이는 b의 길이보다 작거나 같다.
이 때 x의 앞이나 뒤에 알파벳을 추가할 수 있다.
x와 y의 길이가 같으면서 x와y의 차이를 최소로 하는 프로그램을 작성

알파벳은 소문자로만 이루어져 있다.
	1. 문자열의 길이 비교
	- 같으면 인덱스별로 비교
	- 다르면 2번
	2. 차이가 최소가 되는 문자열을 만든다.
	-  b의 길이를 갖는 문자열 c 생성
	- 길이가 더 긴 문자열 b와 문자열 a를 비교하는데 0번인덱스 부터 비교
	- count가 높은 index 를 저장
	- z[index] = x -> replace 사용 
	- if (z[index] == "") z[index] = y[index];
*/

