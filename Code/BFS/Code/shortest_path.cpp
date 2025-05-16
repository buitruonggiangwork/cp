#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
struct vertical {
	int a, b;
};


int n, m, k;
vector<vector<int>> adj;
unordered_map<int, unordered_map<int, unordered_map<int, bool>>> isBan; 
int dis[3001][3001];
bool visited[3001][3001];
vertical parent[3001][3001];

void input() {
	cin>>n>>m>>k;
	adj = vector<vector<int>>(n);
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin>>a>>b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	for(int i = 0; i < k; ++i) {
		int a, b, c;
		cin>>a>>b>>c;
		isBan[a - 1][b - 1][c - 1] = true;
	}
}


vertical bfs() {
	
	// duyet do thi 
	queue<vertical> q;
	q.push({-1, 0});
	while(!q.empty()) {
		vertical front = q.front();
		q.pop();
		for(int i : adj[front.b]) {
			if(!visited[front.b][i] && !isBan[front.a][front.b][i]) {
				visited[front.b][i] = true;
				if(front.b == 0) {
					dis[front.b][i] = 1;
				} else dis[front.b][i] = dis[front.a][front.b] + 1;
				q.push({front.b, i});
				parent[front.b][i] = front;
				if(i == n - 1) {
					return {front.b, i};
				}
			}

		}
	}
	return {-1, -1};

}

void trace(vertical last) {
	if(last.a != -1) {	
		trace(parent[last.a][last.b]);
	}
	cout<<last.b+1<<" ";
}


void solve() {
	input();
	vertical last = bfs();
	if(last.b == -1) {
		cout<<-1;
		return;
	}
	cout<<dis[last.a][last.b]<<"\n";
	trace(last);
}




int main() {
	solve();

}