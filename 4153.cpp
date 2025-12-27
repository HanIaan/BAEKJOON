#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int a, b, c;
    vector<int> t;
    while(cin >> a >> b >> c) {
        if (a == 0 && b == 0 && c == 0)
            break;
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        
        sort(v.begin(), v.end());
        
        if (pow(v[2], 2) == pow(v[0], 2) + pow(v[1], 2))
            t.push_back(1);
        else
            t.push_back(0);
    }
    for (auto it = t.begin(); it != t.end(); ++it) {
        if(*it)
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
    return 0;
}