#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 9
using namespace std;




int n; //세로 크기
int m; //가로 크기
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


void bfs(int map[][MAX], int x, int y) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	
	while (!q.empty()) {
		pair<int, int> temp = q.front();

		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && map[nx][ny] == 0) {
				map[nx][ny] = 2;
				q.push(pair<int, int>(nx, ny));
			}
		}

	}

}
int findSafeArea(int map[][MAX]) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
}

int main() {

	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}


	int map2[MAX][MAX];
	copy(map, map + MAX*MAX, map2);

	//bfs - virus
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map2[i][j] == 2) {
				bfs(map2,i, j);
			}
			
		}
	}
	//findSafeArea
	int max = 0;
	int temp = findSafeArea(map2);
	if (temp > max) {
		max = temp;
	}

	int size = max * (max - 1) * (max - 2) / 6;
	
	
	//벽 세우기
	//0인곳에만 세울 수 있고
	//3개를 세우고 
	//nCr(max C 3) max개 중에서 3개를 중복없이 3개를 순서상관없이 뽑는다.
}