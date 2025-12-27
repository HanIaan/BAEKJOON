#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    pair<int, int> target;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push(make_pair(i, j));
                target = make_pair(i, j);
            }
            else if (grid[i][j] == 0)
                grid[i][j] = 2;
        }
    }

    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    while (!q.empty()) {   
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + row[i];
            int nc = c + col[i];
            if (nc < 0 || nc >= m || nr < 0 || nr >= n) continue;
            if (grid[nr][nc] == 1) {
                grid[nr][nc] = grid[r][c] + 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
    
    bool target_close = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] - 2;
            if (j != m - 1) cout << " ";
            else cout << endl;
        }
    }


    return 0;
}