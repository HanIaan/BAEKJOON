#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N;
    map<string, int> temp;
    multimap<int, string> real;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        temp.insert(make_pair(s, s.length()));
    }
    
    for (auto it = temp.begin(); it != temp.end(); ++it) 
        real.insert(make_pair(it->second, it->first));
    
    for (auto it = real.begin(); it != real.end(); ++it)
        cout << it->second << endl;

    return 0;
}