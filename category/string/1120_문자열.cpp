#include<iostream>
#include<string>

using namespace std;



// �� ���ڿ��� ���̸� ����ϴ� �Լ� 
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

	//���ڿ� z �ʱ�ȭ
	for (int i = 0; i < y.size(); i++) {
		z.push_back(' ');
	}

	//���ڿ� x�� y�� ũ�Ⱑ ���� ��� ���̸� ���
	if (x.size() == y.size()) {
		printDiffrentAlp(x,y);
	}
	//ũ�Ⱑ �޶� ���ڿ� x�� ���ĺ��� �߰��ؾ��ϴ� ��� 
	else {
		int index = 0; 
		int max = 0; 
		//x�� y ��
		for (int i = 0; i < y.size()-x.size()+1; i++) {
			int countSameAlp = 0; //���� ���ڸ� count
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
		z.replace(index,x.size(),x); // �ش� �ε����κ��� x�� ũ�⸸ŭ ���ڿ�x�� ��ü

		//������ ���� y�� ���ڿ��� �����ش�.
		for (int i = 0; i < y.size(); i++) {
			if (z[i] == ' ') {
				z[i] = y[i];
			}
		}
		//y�� ���ڿ� z�� ���� ���
		printDiffrentAlp(z, y);



	}
	return 0;
}

/*
x�� ���̴� b�� ���̺��� �۰ų� ����.
�� �� x�� ���̳� �ڿ� ���ĺ��� �߰��� �� �ִ�.
x�� y�� ���̰� �����鼭 x��y�� ���̸� �ּҷ� �ϴ� ���α׷��� �ۼ�

���ĺ��� �ҹ��ڷθ� �̷���� �ִ�.
	1. ���ڿ��� ���� ��
	- ������ �ε������� ��
	- �ٸ��� 2��
	2. ���̰� �ּҰ� �Ǵ� ���ڿ��� �����.
	-  b�� ���̸� ���� ���ڿ� c ����
	- ���̰� �� �� ���ڿ� b�� ���ڿ� a�� ���ϴµ� 0���ε��� ���� ��
	- count�� ���� index �� ����
	- z[index] = x -> replace ��� 
	- if (z[index] == "") z[index] = y[index];
*/

