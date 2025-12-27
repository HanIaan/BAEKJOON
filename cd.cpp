#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 8; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    if (v[0] == 1) {
        for (int i = 1; i < 8; i++) {
            if(v[i] != i + 1) {
                cout << "mixed";
                return 0;
            }
        }
        cout << "ascending";
    } else if (v[0] == 8) {
        for (int i = 1; i < 8; i++) {
            if(v[i] != 8 - i) {
                cout << "mixed";
                return 0;
            }
        }
        cout << "descending";
    } else {
        cout << "mixed";
    }
    
    return 0;
}