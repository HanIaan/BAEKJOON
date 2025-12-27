#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N, M, temp, max = 0;
    
    cin >> N >> M;
    vector<int> v;
    v.assign(N, 0);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    for(int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                temp = v[i] + v[j] + v[k];
                if (temp > M) continue;
                if (temp > max) max = temp;    
            }
        }
    }

    cout << max;
    
    return 0;
}
