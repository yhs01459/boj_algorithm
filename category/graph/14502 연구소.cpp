#include<iostream>
#include<queue>
#include<algorithm>
#define MAX 9
using namespace std;




int n; //세로 크기
int m; //가로 크기
int safeMax = 0;
int map[MAX][MAX];
int mapCopy[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void printMap(int map[MAX][MAX]) {
	cout << "print map>>>" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << "<<<<end print map" << endl;
}
void bfs(int map[MAX][MAX], int x, int y) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
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
int findSafeArea(int map[MAX][MAX]) {
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

void wall(int cnt) {
	if (cnt == 3) {
		int mapCopy2[MAX][MAX];
		copy(&mapCopy[0][0], &mapCopy[0][0] + MAX * MAX, &mapCopy2[0][0]);

		//bfs - virus
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (mapCopy2[i][j] == 2) {
					bfs(mapCopy2, i, j);
				}

			}
		}

		//findSafeArea
		int temp = findSafeArea(mapCopy2);
		if (temp > safeMax) {
			safeMax = temp;
		}

		return;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mapCopy[i][j] == 0) {
				mapCopy[i][j] = 1;
				wall(cnt+1);
				mapCopy[i][j] = 0;
			}
		}
	}
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
	copy(&map[0][0], &map[0][0] + MAX * MAX, &mapCopy[0][0]);
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				mapCopy[i][j] = 1;
				wall(1);
				mapCopy[i][j] = 0;
			}
		}
	}
	cout << safeMax;
	




	/*
	* 3개의 벽을 세우는 방법을 찾는 과정에서 어려움을겪음
	* 기존 배열에 000 인곳을 탐색하면서 맵을 복사해 111을 넣어준 뒤 bfs -> find safe area 하면 될꺼같은데...
	* 재귀를 이용하여 해결
	* 
	*/

}