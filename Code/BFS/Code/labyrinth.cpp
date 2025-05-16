#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int x, y;
};

Point s, e;
int n, m;
char matrix[1000][1000];
int dis[1000][1000];
bool visited[1000][1000];

void input() {
	cin>>n>>m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin>>matrix[i][j];
			if(matrix[i][j] == 'A') {
				s.x = i;
				s.y = j;
			}
			if(matrix[i][j] == 'B') {
				e.x = i;
				e.y = j;
			}
		}
	}
}

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


void bfs() {
	queue<Point> q;
	dis[s.x][s.y] = 0;
	visited[s.x][s.y] = true;
	q.push(s);
	while(!q.empty()) {
		Point front = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(matrix[nx][ny] != '#' && !visited[nx][ny]) {
					visited[nx][ny] = true;
					dis[nx][ny] = dis[front.x][front.y] + 1;
					if(matrix[nx][ny] == 'B') {
						return;
					}
					q.push({nx, ny});
				}
			}
		}

	}
}


void trace(Point e) {
	//cout<<dis[e.x][e.y]<<"\n";
	for(int i = 0; i < 4; ++i) {
		int px = e.x - dx[i];
		int py = e.y - dy[i];
		if(px >= 0 && px < n && py >= 0 && py < m) {
			// da duoc tham
			// dis[truocdo] = dis[e] - 1;
			if(dis[px][py] == dis[e.x][e.y] - 1 && visited[px][py]) {
				trace({px, py});
				if(i == 0) {
					cout<<"D";
				}
				if(i == 1) {
					cout<<"U";
				}
				if(i == 2) {
					cout<<"R";
				}
				if(i == 3) {
					cout<<"L";
				}
				return;
			}
		}

	}
}


void solve() {
	input();
	bfs();
	// for(int i = 0; i < n; ++i) {
	// 	for(int j = 0; j < m; ++j) {
	// 		cout<<dis[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<"\n";
	// for(int i = 0; i < n; ++i) {
	// 	for(int j = 0; j < m; ++j) {
	// 		cout<<visited[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }


	if(visited[e.x][e.y]) {
		cout<<"YES\n";
		cout<<dis[e.x][e.y]<<"\n";
		trace(e);
		cout<<"\n";
	} else {
		cout<<"NO\n";
	}
}

int main() {
	solve();

}