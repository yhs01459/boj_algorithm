#include<iostream>
#include<string>

using namespace std;

int main() {
	int n; // �Է¹޴� ������ ����
	string k; //�Է����� �־����� ����k
	int num; //���ڿ��� �־����� ������ ù��° �ڸ��� ������ ����
	cin >> n;

	//n��ŭ �ݺ�
	for (int i = 0; i < n; i++) { 
		cin >> k;
		num = (k[k.size() - 1]) - '0'; // ù��° �ڸ��� ���ڷ� ��ȯ �� ����
		if (num % 2 == 0) { // ù��° �ڸ��� ¦����� even ���
			cout << "even";
		}
		else {
			cout << "odd"; //Ȧ����� odd ���
		}
		cout << endl;
	}
	return 0;
	
}

/* 
* ���� ������ 1~10^60 �̱⶧���� int,double �� ������ Ÿ���� �ٷ� �� �ִ� ������ �Ѿ��.
* �׷����� string���� �Է¹޾� �������ڸ��� ���ڷ� �����Ͽ� ¦���� even, Ȧ���� odd�� ����ϵ��� ���α׷��� �Ѵ�.
* 
*/