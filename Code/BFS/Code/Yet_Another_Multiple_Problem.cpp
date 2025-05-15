#include <iostream>
#include <queue>
using namespace std;
int n, numban;
bool banDigit[10];
bool visited[10001];

struct number {
	string num;
	int remain;
};


void solve() {
	for(int i = 0; i <= n; ++i)
		visited[i] = false;
	for(int i = 0; i < 10; ++i)
		banDigit[i] = false;
	cin>>numban;
	for(int i = 0; i < numban; ++i) {
		int a;
		cin>>a;
		banDigit[a] = true;
	}

	queue<number> q;
	q.push({"", 0});
	while(!q.empty()) {
		number front = q.front();
		//cout<<front<<"\n";
		q.pop();
		if(front.remain == 0 && front.num != "0" && front.num != "") {
			cout<<front.num<<"\n";
			return;
		}
		for(int i = 0; i < 10; ++i) {
			if(banDigit[i] == false) {
				number next = {front.num + (char)('0' + i), (front.remain*10 + i) % n};
				if(!visited[next.remain] && next.num != "0" && next.num != "") {
					visited[next.remain] = true;
					q.push(next);
				}	
			}
		} 
	}
	cout<<"-1\n";

}


int main() {
	for(int i = 1; cin>>n; ++i) {
		cout<<"Case "<<i<<": ";
		solve();

	}	
}