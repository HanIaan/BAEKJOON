#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, count = 0;
    string chat;
    unordered_set<string> name;
    cin >> N;       // N개의 기록 수 입력
    while(N-- > 0) {
        bool valid = true;
        cin >> chat;
        if (chat == "ENTER")
            name.clear();      // 해시 초기화
        else {
            if (name.find(chat) != name.end())
                valid = false;      // 중복이면 valid false

            if (valid) {
                count++;        // 중복 아니면 count 증가
                name.insert(chat);      // 중복 아니면 해시에 이름 넣기
            }
        }
    }
    cout << count;

    return 0;
}