/* �׷��� Ž�� - 2606 ���̷��� 
 - DFS �̿��Ͽ� Ǯ��
 */

#include<iostream>

using namespace std;

int computerNum; // ��ǻ���� ���� 
int pairNum; // ��ǻ�� ���� �� 

int map[101][101] = { 0, };
bool visited[101] = { false };
int virusCnt = -1;

void dfs(int idx) {
	visited[idx] = true;
	virusCnt++;
	for (int i = 1; i <= computerNum; i++) {
		if (map[idx][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
}

int main() {
	cin >> computerNum >> pairNum;
	for (int i = 1; i <= pairNum; i++) {
		int temp;
		int temp2;
		cin >> temp >> temp2;
		map[temp][temp2] = 1;
		map[temp2][temp] = 1;
	}
	dfs(1);
	cout << virusCnt;
}