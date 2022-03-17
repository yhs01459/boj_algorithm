#include<iostream>
#include<map>


using namespace std;

int main() {
	string str;
	map<char, int> consecutiveCnt; //���ӵ� ���� ����
	int answer; // �ּ� Ƚ��
	cin >> str;

	char temp = str[0]; // �������� ���ϱ� ���� �ӽú���
	consecutiveCnt[temp]++; 

	//���� �ٲ�� �ش簪�� ����
	for (int i = 1; i < str.size(); i++) {
		if (temp != str[i]) {
			consecutiveCnt[str[i]]++;
			temp = str[i];
		}
	}

	//�ѹ��� �������� ���� ���� ���
	if (consecutiveCnt.size() == 1) {
		cout << 0;
	}
	//�ּڰ�
	else {

		answer = min(consecutiveCnt['0'], consecutiveCnt['1']);
		cout << answer;
	}
	
	return 0;
}

/*
* �ѹ��� ���ӵ� �ϳ� �̻��� ���ڸ� ������ �� �ִ�.
* ���� ������������ ���������� �ּ�Ƚ�� ���ϱ�
*/