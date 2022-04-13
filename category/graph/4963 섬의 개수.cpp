#include<iostream>
#include<queue>
#define MAX 51
using namespace std;

int dx[8] = { -1, -1 , 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int map[MAX][MAX];
bool visited[MAX][MAX];
int landCnt = 0;
int h;
int w;

void init() {
	landCnt = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	visited[x][y] = true;
	while (!q.empty()) {
		pair<int, int> p;
		p = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];
			
			if (nx > 0 && nx <= h && ny > 0 && ny <= w && map[nx][ny] == 1 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				q.push(pair<int, int>(nx, ny));
			}
		}

	}
}

int main() {
	
	while (1) {

		cin >> w >> h;
		if (h == 0 && w == 0) {
			break;
		}

		//init
		init();

		//input 
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				int temp;
				cin >> temp;
				if (temp == 1) {
					map[i][j] = temp;
				}
			}
		}

		//bfs
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] == 1 && visited[i][j] == false) {
					bfs(i,j);
					landCnt++;
				}
			}
		}

		//print
		cout << landCnt << endl;

	}

}

