
/* 11724 연결요소의 개수 */

#include<iostream>
#include<queue>
#define MAX 1001

using namespace std;

int n; // 정점의 개수
int m; // 간선의 개수
int map[MAX][MAX] = { 0, };
bool visited[MAX] = { false, };
int cnt = 0;

void init() {
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}
void dfs(int idx) {
	visited[idx] = true;
	for (int i = 1; i <= n; i++) {
		if (map[idx][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
}

void bfs(int idx) {
	
	queue<int> q;
	q.push(idx);
	visited[idx] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (map[temp][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
		
	}

}


int main() {
	
	
	cin >> n >> m;

	//연결정보 저장 
	for (int i = 0; i < m; i++) {
		int temp;
		int temp2;
		cin >> temp >> temp2;
		map[temp][temp2] = 1;
		map[temp2][temp] = 1;
	}

	//깊이탐색
	for (int i = 1; i <= n; i++) {
		if (visited[i]==false) {
			dfs(i);
			cnt++;
		}
	}
	cout << "깊이탐색 결과 : " << cnt << endl;
	
	//초기화
	init();

	//너비탐색
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt;
}