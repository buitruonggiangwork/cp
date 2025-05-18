#include <iostream>
#include <queue>
using namespace std;
struct Point {
	int x, y;
};


Point monsterPoses[1000000];
Point st, out;
char matrix[1000][1000];
int dangerAt[1000][1000];
int dis[1000][1000];
bool visited[1000][1000];
int n, m, nMonters;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

void debug() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout<<dis[i][j]<<" ";
		}
		cout<<"\n";
	}
}

void input() {
	cin>>n>>m;
	nMonters = 0;
	out.x = out.y = -1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin>>matrix[i][j];
			if(matrix[i][j] == 'A') {
				st.x = i;
				st.y = j;
			}
			if(matrix[i][j] == 'M') {
				monsterPoses[nMonters].x = i;
				monsterPoses[nMonters].y = j;
				nMonters++;
			}
		}
	}
}

void bfs_monster() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			visited[i][j] = false;
			dangerAt[i][j] = 1000000;
		}
	}

	queue<Point> q;
	for(int i = 0; i < nMonters; ++i) {
		visited[monsterPoses[i].x][monsterPoses[i].y] = true;
		dangerAt[monsterPoses[i].x][monsterPoses[i].y] = 0;
		q.push(monsterPoses[i]);
	}

	while(!q.empty()) {
		Point front = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(!visited[nx][ny] && matrix[nx][ny] != '#') {
					dangerAt[nx][ny] = dangerAt[front.x][front.y] + 1;
					visited[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
	}
}

void bfs() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			visited[i][j] = false;
		}
	}

	queue<Point> q;
	dis[st.x][st.y] = 0;
	visited[st.x][st.y] = true;

	if(st.x == 0 || st.x == n - 1 || st.y == 0 || st.y == m - 1) {
		out.x = st.x;
		out.y = st.y;
		return;
	}

	q.push(st);	
	while(!q.empty()) {
		Point front = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = front.x + dx[i];
			int ny = front.y + dy[i];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(!visited[nx][ny] && dis[front.x][front.y] + 1 < dangerAt[nx][ny] && matrix[nx][ny] != '#') {
					dis[nx][ny] = dis[front.x][front.y] + 1;
					visited[nx][ny] = true;
					if(nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) {
						out.x = nx;
						out.y = ny;
						return;
					}
					q.push({nx, ny});
				}
			}
		}
	}
}

void trace(Point last) {
	if(last.x != st.x || last.y != st.y) {
		for(int i = 0; i < 4; ++i) {
			int px = last.x - dx[i];
			int py = last.y - dy[i];
			if(dis[px][py] + 1 == dis[last.x][last.y] && visited[px][py]) {
				trace({px, py});
				//cout<<i<<' ';
				if(i == 0) {
					cout<<"D";
				}
				if(i == 1) {
					cout<<"L";
				}
				if(i == 2) {
					cout<<"U";
				}
				if(i == 3) {
					cout<<"R";
				}
				break;
			}
		}
	}

}

void solve() {
	input();
	bfs_monster();
	bfs();
	if(out.x == -1) {
		cout<<"NO\n";
	} else {
		cout<<"YES\n";
		cout<<dis[out.x][out.y]<<"\n";
		trace(out);
	}
}

int main() {
	solve();

}