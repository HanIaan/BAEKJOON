#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    
    string s;
    bool pal = true;
    while (cin >> s && s != "0") {
        bool pal = true;
        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - i - 1]) {
                pal = false;
                break;
            }
        }
        if(pal) cout << "yes" << endl;
        else    cout << "no" << endl;
    }

    return 0;
}