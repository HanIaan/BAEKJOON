#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> name(N + M), t_name;

    for (int i = 0; i < N; i++) 
        cin >> name[i];
    for (int i = N; i < N + M; i++) 
        cin >> name[i];
    sort(name.begin(), name.end());
    for (int i = 0; i < N + M - 1; i++) {
        if (name[i] == name[i + 1]) 
            t_name.push_back(name[i++]);
        
    }
    cout << t_name.size() << endl;
    for (auto it = t_name.begin(); it != t_name.end(); ++it)
        cout << *it << endl;
    return 0;
}