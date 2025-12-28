#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> visited(N + 1, 0);
    queue<int> q;
    q.push(N);
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        if (n == 0) continue;
        if (n == 1) break;

        int x = visited[n] + 1;
        if (n % 3 == 0 && (x < visited[n / 3] || visited[n / 3] == 0)) {
            q.push(n / 3);
            visited[n / 3] = x;
        }
        if (n % 2 == 0 && (x < visited[n / 2] || visited[n / 2] == 0)) {
            q.push(n / 2);
            visited[n / 2] = x;
        }
        if (x < visited[n - 1] || visited[n - 1] == 0) {
            q.push(n - 1);
            visited[n - 1] = x;
        }
    }

    cout << visited[1];
    return 0;
}