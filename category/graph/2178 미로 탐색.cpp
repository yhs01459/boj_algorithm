#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int n; //미로의 행
int m; //미로의 열 
int dx[4] = { -1, 0,1,0 };
int dy[4] = { 0,1,0,-1 };
int maze[MAX][MAX] = { 0, }; //미로
int map[MAX][MAX] = { 0, }; //이동횟수를 저장을 위한 배열
bool visited[MAX][MAX] = { false, }; //방문여부 저장을 위한 배열 


void bfs(int x, int y) {
	queue<pair<int,int>> q;
	q.push(pair<int, int>(x, y));
	visited[x][y] = true;
	while (!q.empty()) {

		pair<int, int> temp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = temp.first+dx[i];
			int ny = temp.second+dy[i];

			if (nx > 0 && nx <= n && ny > 0 && ny <= m && maze[nx][ny] == 1 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				q.push(pair<int, int>(nx, ny));
				map[nx][ny] = map[temp.first][temp.second] + 1;
			}

		}
	}
}

int main() {

	//미로 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			if (temp[j] == '1') {
				maze[i+1][j+1] = 1;
			}
		}
	}

	//너비우선탐색
	map[1][1] = 1;
	bfs(1, 1);
	cout << map[n][m];


}