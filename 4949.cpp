#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    stack<char> stk;
    bool valid = true;
    while(true) {
        valid = true;       // 문장 받을 때마다 valid = true 초기화
        getline(cin, str);
        if(str == ".") break;       // . 입력시 종료
        for(int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[')    
                stk.push(str[i]);       // ( or [ 입력시 Stack에 push
            else if (str[i] == ')' || str[i] ==']') {
                if (stk.empty()) {      // ) or ] 입력 받았는데 Stack이 비었다면 break
                    valid = false;
                    break;
                }
                if ((str[i] == ')' && stk.top() != '(') || (str[i] == ']' && stk.top() != '[')) { 
                    valid = false;      // ) or ] 입력 받았는데 Stack 최상단이 그에 대응되는 괄호가 아닐 경우 break
                    break;
                }
                stk.pop();      // 정상 통과시 pop
            }
            if (i == str.length() - 1 && !stk.empty())  valid = false;      // 문장 마지막까지 돌았는데 Stack이 비어있지 않다면 false
        }
        cout << (valid ? "yes" : "no") << '\n';
        while(!stk.empty()) stk.pop();      // Stack 초기화
    }
    
    return 0;
}