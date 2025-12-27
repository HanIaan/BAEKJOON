#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M;
    int u, v, count = 0;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    queue<int> q;

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visit(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        if (visit[i]) continue;
        visit[i] = 1;
        q.push(i);
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            
            for (int nx : graph[n]) {
                if (!visit[nx]) {
                    q.push(nx);
                    visit[nx] = 1;
                }
            }
        }
        count++;
    }

    cout << count;
    return 0;
}