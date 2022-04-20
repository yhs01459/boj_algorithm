/* 2667 단지번호 붙이기 */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 26

using namespace std;

int n;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> v;


void bfs(int x, int y) {
	int houseCnt = 1;
	queue<pair<int, int>> q;
	q.push(pair<int, int>(x, y));
	visited[x][y] = true;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx > 0 && nx <= n && ny > 0 && ny <= n && visited[nx][ny] == false && map[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push(pair<int, int>(nx, ny));
				houseCnt++;
			}
		}
	}
	v.push_back(houseCnt);
}
int main() {
	cout << "입력:";
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			if (temp[j] == '1') {
				map[i][j + 1] = 1;
			}
		}
	}

	//solve
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 1 && visited[i][j] == false) {
				bfs(i, j);
			}
		}
	}

	//print
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}

//입력이 문자열로 주어지는것에 주의