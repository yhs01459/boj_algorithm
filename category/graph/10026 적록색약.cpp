/* 10026 ���ϻ��� */
#include<iostream>
#include<queue>
#define MAX 101
using namespace std;

int n;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt = 0;
int cnt2 = 0;
template <typename T>
void printMap(T map[][MAX]) {
	cout << "print!!"<<endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << "end print!!" << endl;
}
void bfs(int x, int y,char c, bool flag) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	visited[x][y] = true;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			//���ϻ����� ���
			if (flag) {

				if (c == 'R' || c == 'G') {
					if (nx > 0 && nx <= n && ny > 0 && ny <= n && visited[nx][ny] == false && (map[nx][ny] == 'R' || map[nx][ny] == 'G')) {
						q.push(pair<int, int>(nx, ny));
						visited[nx][ny] = true;
					}
				}
				else if (c == 'B') {
					if (nx > 0 && nx <= n && ny > 0 && ny <= n && visited[nx][ny] == false && map[nx][ny] == 'B') {
						q.push(pair<int, int>(nx, ny));
						visited[nx][ny] = true;
					}
				}

				
			}
			//�ƴ� ��� 
			else {
				if (nx > 0 && nx <= n && ny > 0 && ny <= n && visited[nx][ny] == false && map[nx][ny] == c) {
					q.push(pair<int, int>(nx, ny));
					visited[nx][ny] = true;
				
				}
			}
			
		}
	}
}

void reset() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {

	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			map[i+1][j+1] = temp[j];
		}
	}

	//���ϻ����� �ƴ� ����� ��� ���ڰ� �ٸ��� ī��Ʈ 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			
			if (visited[i][j] == false) {
				bfs(i, j, map[i][j], false);
				cnt++;
			}

		}
	}
	reset();
	//���ϻ����� ��� 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (visited[i][j] == false) {
				bfs(i, j, map[i][j], true);
				cnt2++;
			}

		}
	}



	cout << cnt <<" " << cnt2;
}


//���ϻ����� �ƴѰ�� ���ϻ����� ��� �� ��츦 ���