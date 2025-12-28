#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, n;
    cin >> N;

    while (N-- > 0) {
        int count[2] = {1, 2};
        cin >> n;
        if (n == 0) {
            count[0] = 1;
            count[1] = 0;
        } 
        else if (n == 1) {
            count[0] = 0;
            count[1] = 1;
        }
        else if (n == 2) {
            count[0] = 1;
            count[1] = 1;
        }
        else {
            for (int i = 3; i < n; i++) {
                int temp = count[1];
                count[1] += count[0];
                count[0] = temp;
            }
        }
        cout << count[0] << " " << count[1] << endl;
    }

    return 0;
}