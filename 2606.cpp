#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, M, count = 0;;
    queue<int> q;
    cin >> N >> M;

    vector<vector<int>> com(N + 1); 
    vector<int> visited(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        com[u].push_back(v);
        com[v].push_back(u);
    }
    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        for(int i = 0; i < com[idx].size(); i++) {
            int x = com[idx][i];
            if(!visited[x]) {
                visited[x] = 1;
                q.push(x);
                count++;
            }
        }
    }
    cout << count;
    return 0;
}