#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};

unordered_map<int, unordered_map<int, bool>> lited;
unordered_map<int, unordered_map<int, bool>> visited;
unordered_map<int, unordered_map<int, int>> dis;
int n, m, k;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int drc[] = {1, 0, -1};

void input() {
	cin>>n>>m>>k;
	for(int i = 0; i < k; ++i) {
		int a, b;
		cin>>a>>b;
		a--;
		b--;
		lited[a][b] = true;
	}
}


void solve() {
	input();
	if(n == 1 && m == 1) {
		cout<<"0";
		return;
	}
	deque<Point> q;
	visited[0][0] = true;
	dis[0][0] = 0;
	q.push_back({0, 0});
	while(!q.empty()) {
		Point front = q.front();
		cout<<front.x<<" "<<front.y<<" "<<dis[front.x][front.y]<<"\n";
		q.pop_front();
		for(int i = 0; i < 4; ++i) {
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(!visited[nx][ny] && lited[nx][ny]) {
					visited[nx][ny] = true;
					dis[nx][ny] = dis[front.x][front.y];
					q.push_front({nx, ny});
				}
			}
		}
		if(lited[front.x][front.y]) {
			for(int i = 0; i < 3; ++i) {
				int nc = front.y + drc[i];
				int nr = front.x + drc[i];
				if(nc >= 0 && nc < m) {	
					for(int j = 0; j < n; ++j) {
						if(!visited[j][nc]) {
							visited[j][nc] = true;
							dis[j][nc] = dis[front.x][front.y] + 1;
							q.push_back({j, nc});
						}
					}
				}
				if(nr >= 0 && nr < n) {	
					for(int j = 0; j < m; ++j) {
						if(!visited[nr][j]) {
							visited[nr][j] = true;
							dis[nr][j] = dis[front.x][front.y] + 1;
							q.push_back({nr, j});
						}
					}
				}
			}
		}
	}
	if(visited[n - 1][m - 1]) {
		cout<<dis[n-1][m-1];
	} else cout<<"-1";
}

int main() {
	solve();
}