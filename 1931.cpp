#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
bool compare1(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) 
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int N, start, end, count = 0;
    cin >> N;
    vector<pair<int, int>> v;
    
    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }

    sort(v.begin(), v.end(), compare1);

    auto it = v.begin();
    start = v[0].first;
    end = v[0].second;
    count++;
    ++it;
    for (; it != v.end(); ++it) {
        if(it->first < end) continue;
        start = it->first;
        end = it->second;
        count++;
    }
    
    cout << count;

    return 0;
}