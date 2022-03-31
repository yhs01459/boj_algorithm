/* 그래프 - 1260 DFS 와 BFS  */

#include<iostream>
#include<queue>
#define MAX 1001

using namespace std;

int map[MAX][MAX] = { 0, };
bool visited[MAX] = { false };

int n; // 정점의 개수
int m; // 간선의 개수
int v; // 탐색을 시작할 정점의 번호

void dfs(int idx) {
	visited[idx] = true;
	cout << idx << " ";
	for (int i = 1; i <= n; i++) {
		if (map[idx][i]==1 && visited[i]==false) {
			dfs(i);
		}
	}
	
}

void init() {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}

void bfs(int idx) {
	queue <int> q;
	q.push(idx);
	visited[idx] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		cout << temp << " ";
		for (int i = 1; i <= n; i++) {
			if (map[temp][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}

	}
}

int main() {

	//input
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int temp;
		int temp2;
		cin >> temp >> temp2;
		map[temp][temp2] = 1; 
		map[temp2][temp] = 1;
	}

	//dfs
	dfs(v);
	cout << endl;
	//visited clear
	init();

	//bfs
	bfs(v);

}

