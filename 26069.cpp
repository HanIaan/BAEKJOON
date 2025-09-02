#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    bool A_dancing = false, B_dancing = false;
    string A, B;
    unordered_set<string> DancingPeople;       //춤추는 사람이 들어갈 set
    DancingPeople.insert("ChongChong");    //총총이는 이미 포함
    cin >> N;       // N개의 기록 수 입력
    
    while (N--) {
        cin >> A >> B;
        if (DancingPeople.find(A) != DancingPeople.end())       // A가 춤추고 있는지
            A_dancing = true;
        if (DancingPeople.find(B) != DancingPeople.end())       // B가 춤추고 있는지
            B_dancing = true;
        
        if (A_dancing && !B_dancing)
            DancingPeople.insert(B);        // A만 춤추면 B도 set에 추가
        else if(!A_dancing && B_dancing)
            DancingPeople.insert(A);        // B만 춤추면 A도 set에 추가

        A_dancing = false;
        B_dancing = false;
    }
    cout << DancingPeople.size();
    return 0;
}