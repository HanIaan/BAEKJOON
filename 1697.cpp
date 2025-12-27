#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, K, K_count = 100000;
    cin >> N >> K;

    if (K <= N) {
        cout << N - K;
        return 0;
    }

    vector<int> grid(100001, -1);
    grid[N] = 0;
    queue<int> q;

    q.push(N);

    while(!q.empty()) {
        int n = q.front();
        q.pop();
        
        if (n > 0) {
            if (grid[n - 1] == -1) {
                grid[n - 1] = grid[n] + 1;
                q.push(n - 1);
            }
        }
        if (n + 1 < 100001) {
            if (grid[n + 1] == -1) {
                grid[n + 1] = grid[n] + 1;
                q.push(n + 1);
            }
        }
        if (2 * n < 100001) {
            if (grid[2 * n] == -1) {
                grid[2 * n] = grid[n] + 1;
                q.push(2 * n);
            }
        }
        
        if (n == K)
            break;
    }

    cout << grid[K];
    
    return 0;
}