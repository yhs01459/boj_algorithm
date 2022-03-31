/* 그래프 탐색 - 2606 바이러스 
 - DFS 이용하여 풀이
 */

#include<iostream>

using namespace std;

int computerNum; // 컴퓨터의 개수 
int pairNum; // 컴퓨터 쌍의 수 

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