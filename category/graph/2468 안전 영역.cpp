#include<iostream>
#include<queue>
#define MAX 101
using namespace std;


int map[MAX][MAX];
bool visited[MAX][MAX];
int n;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0, 1,0,-1 };
 
int safeAreaMaxCnt = 0; //���������� �ִ밳��
int safeAreaCnt = 0; //���������� ����

//�������븦 ã�� �� ���
void bfs(int x, int y, int h) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	visited[x][y] = true;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n && visited[nx][ny] == false&&map[nx][ny]>h) {
				q.push(pair<int, int>(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
} 
void reset() {
	safeAreaCnt = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {
	//input
	cin >> n;
	for (int i = 1; i<= n; i++) {
		for (int j = 1; j <= n; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}

	

	//�ִ� �������� ������ ã�� ���� ���� ���̸� 1�� ������Ű�� �˻� 
	for (int i = 0; i <= 100; i++) { 
		
		for (int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				if (map[j][k] > i&&visited[j][k]==false) {
					bfs(j, k, i);
					safeAreaCnt++;
				}
				
			}
		}

		if (safeAreaCnt > safeAreaMaxCnt) {
			safeAreaMaxCnt = safeAreaCnt;
		}

		//�湮���� �� �������� ���� �ʱ�ȭ
		reset();

	}

	cout << safeAreaMaxCnt;

	//�� �������� �ʴ� ��츦 ����ؾ��Ѵ�.



}