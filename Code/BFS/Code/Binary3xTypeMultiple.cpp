#include <iostream>
#include <queue>
using namespace std;
struct number {
	int cnt3;
	int cnt0;
	int remain;
};


int n;
bool visited[10000000][2];


void bfs() {
	for(int i = 0; i <= n; ++i)
		visited[i][0] = visited[i][1] = false;

	number start = {1, 0, 3 % n};
	visited[start.remain][start.cnt0 == 0] = true;
	queue<number> q;
	q.push(start);
	while(!q.empty()) {
		number front = q.front();
		q.pop();
		if(front.remain == 0) {
			cout<<front.cnt0 + front.cnt3<<" "<<front.cnt3<<" "<<front.cnt0<<"\n";
			return;
		}
		number add0 = {front.cnt3, front.cnt0 + 1, (front.remain * 10) % n};
		number add3 = {front.cnt3 + 1, front.cnt0, (front.remain*10 + 3)%n};
		if(!visited[add0.remain][add0.cnt0 == 0]) {
			visited[add0.remain][add0.cnt0 == 0] = true;
			q.push(add0);
		}
		if(!visited[add3.remain][add3.cnt0 == 0] && front.cnt0 == 0) {
			visited[add3.remain][add3.cnt0 == 0] = true;
			q.push(add3);
		}
	}


}

int main() {
	while(cin>>n) {
		bfs();
	}
}