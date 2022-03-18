#include<iostream>
#include<string>
#include<algorithm>
#include<vector>


using namespace std;

int main() {
	string str1; //입력 문자열
	string boomb; //폭발 문자열
	cin >> str1 >> boomb;

	vector<char> answer;

	

	//#2
	for (int i = 0; i < str1.size(); i++) {
		int count = 0;
		answer.push_back(str1[i]);
		if (answer.back() == boomb[boomb.size() - 1]) {
			if (answer.size()>=boomb.size()) {
				int count = 0;
				for (int j = 0; j < boomb.size(); j++) {
					if(answer[answer.size() - boomb.size() + j] == boomb[j]) count++;
				}
				if (count==boomb.size()) {
					answer.erase(answer.end() - boomb.size(),answer.end());
				}
			}
		}
	}
	if (answer.size() == 0) {
		cout << "FRULA";
	}
	else {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i];
		}
	}

	/* #1 시간초과
	while(str1.find(boomb)!=string::npos) {
		int n = str1.find(boomb);
		string from = str1.substr(0, n);
		string to = str1.substr(n + boomb.size());
		str1 = from + to;
	}
	if (str1.size() == 0) {
		cout << "FRULA";
	}
	else {
		cout << str1;
	}
	*/



	return 0;
}