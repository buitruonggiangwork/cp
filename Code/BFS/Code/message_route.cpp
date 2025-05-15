#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> connections;
vector<int> dis;
vector<bool> visited;



void bfs() {
	visited[0] = true;
	dis[0] = 0;
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int front = q.front();
		q.pop();
		for(int adj : connections[front]) {
			if(!visited[adj]) {
				dis[adj] = dis[front] + 1;
				visited[adj] = true;
				if(adj == n - 1)
					return;
				q.push(adj);

			}
		}
	}
}


void traceRoute(int i) {
	if(i != 0) {
		for(int adj : connections[i]) {
			if(visited[adj] && dis[adj] == dis[i] - 1) {
				traceRoute(adj);
				break;
			}
		}
	} 
	cout<<i + 1<<" ";

}


int main() {
	cin>>n>>m;
	connections = vector<vector<int>>(n);
	dis = vector<int> (n);
	visited = vector<bool> (n);
	for(int i = 0; i < m; ++i) {
		int a, b;
		cin>>a>>b;
		connections[a - 1].push_back(b - 1);
		connections[b - 1].push_back(a - 1);
	}
	bfs();

	if(visited[n -1]) {
		cout<<dis[n - 1] + 1<<"\n";
		traceRoute(n - 1);
	} else {
		cout<<"IMPOSSIBLE";
	}

}