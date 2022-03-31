/* 1697 숨바꼭질 */
#include<iostream>
#include<queue>
#include<cmath>
#define MAX 100001
using namespace std;

int n; // 수빈이의 위치
int m; // 동생의 위치 
int visited[MAX] = { false };
int cnt = 0;
void bfs(int n, int m) {
	queue<pair<int, int>> q;
	q.push(pair<int, int>(n, cnt));
	visited[n] = true;
	while (!q.empty()) {
		if (q.front().first == m) {
			cout << q.front().second;
			return;
		}
		else {
			
			pair<int, int> cur = q.front();
			
			q.pop();
			int nx1 = cur.first-1;
			int nx2 = cur.first + 1;
			int nx3 = cur.first * 2;
			cnt = cur.second;
			

			if (nx1 > -1 && visited[nx1] == false) {
				visited[nx1] = true;	
				q.push(pair<int, int>(nx1, cnt+1));
			}
			if (nx2 < m + 1 && visited[nx2] == false) {
				visited[nx2] = true;
				q.push(pair<int, int>(nx2, cnt+1));
			}
			if (nx3 < MAX && visited[nx3] == false) {
				visited[nx3] = true;
				q.push(pair<int, int>(nx3, cnt+1));
			}


			
		}
	}
}

int main(){
	cin >> n >> m;
	bfs(n, m);
}