/* 7576 토마토 */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1001

using namespace std;

int n;
int m;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int day[MAX][MAX];
queue<pair<int, int>> q;

void printMap(int map[][MAX]) {
	cout << "print map>>" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

}

void bfs() {
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= m && visited[nx][ny] == false && map[nx][ny] == 0) {
				visited[nx][ny] = true;
				q.push(pair<int, int>(nx, ny));
				day[nx][ny] = day[temp.first][temp.second]+1;
				map[nx][ny] = 1;
			}
		}
	}
}

int countDay(){
	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (max < day[i][j]) {
				max = day[i][j];
			}
		}
	}
	return max;
}

bool allRipe() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}



int main() {
	//input
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
			day[i][j] = 0;
		}
	}

	//토마토가 전부 익은 경우
	if (allRipe()) {
		cout << 0;
	}

	//토마토가 전부 익지 않은 경우
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 1) {
					q.push(pair<int, int>(i,j));
					visited[i][j] = true;
				}
			}
		}

		bfs();

		if (allRipe()) {
			cout << countDay();
		}
		else {
			cout << -1;
		}

	}
}

//1. 토마토가 다 익었는지 검사
//2. 다 안익었으면 하루 경과
// 큐에 넣는 순서 주의 