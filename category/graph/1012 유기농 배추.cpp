/* �׷����̷� - 1012 ����� ����
* BFS �̿��Ͽ� Ǯ��
*/

#include<iostream>
#include<queue>

#define MAX 51

using namespace std;
int count = 0;
int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false };

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0 ,-1 };

int m; // ���߹� ���� ����
int n; // ���߹� ���� ����
int k; // ���߰� �ɾ��� �ִ� ��ġ�� ���� 
int testCaseNum; //�׽�Ʈ ���̽��� ���� 
int cnt = 0; // �ʿ��� ������������ �� 

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	visited[x][y] = true;
	while (!q.empty()){
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx > -1 && ny > -1 && nx < m && ny < n && map[nx][ny] == 1 && visited[nx][ny] == false) {
				visited[nx][ny] = true;
				q.push(pair<int,int>(nx, ny));
			}
		}
	}
}

void init() {
	cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

int main() {
	cin >> testCaseNum;

	for (int i = 0; i < testCaseNum; i++) {
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			int temp;
			int temp2;
			cin >> temp >> temp2; // ���߰� �ɾ��� �ִ� ��ġ�� ���� ��ǥ
			map[temp][temp2] = 1;
		}
		for (int j = 0; j < m; j++) {
			for (int t = 0; t < n; t++) {
				if (map[j][t] == 1 && visited[j][t] == false) {
					bfs(j, t);
					cnt++;
				}
			}
		}
		cout << cnt;
		cout << endl;
		init();
		

	}
}
