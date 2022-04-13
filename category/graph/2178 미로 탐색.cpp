#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int n; //�̷��� ��
int m; //�̷��� �� 
int dx[4] = { -1, 0,1,0 };
int dy[4] = { 0,1,0,-1 };
int maze[MAX][MAX] = { 0, }; //�̷�
int map[MAX][MAX] = { 0, }; //�̵�Ƚ���� ������ ���� �迭
bool visited[MAX][MAX] = { false, }; //�湮���� ������ ���� �迭 


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

	//�̷� �Է�
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

	//�ʺ�켱Ž��
	map[1][1] = 1;
	bfs(1, 1);
	cout << map[n][m];


}