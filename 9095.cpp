#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    int T, n;
    cin >> T;
    while (T-- > 0) {
        cin >> n;
        int count = 0;
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (x == n) {
                count++;
                continue;
            }
            if (x + 1 <= n)
                q.push(x + 1);
            if (x + 2 <= n) 
                q.push(x + 2);
            if (x + 3 <= n)
                q.push(x + 3);
        }
        cout << count << endl;
    }

    return 0;
}