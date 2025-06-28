#include <stdio.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int count = 0;

void push(char value) {             // push 함수
    stack[count++] = value;
}

char pop() {                        // pop 함수
    return stack[--count];
}

int main() {
    int n, hit;
    char str[50];
    scanf("%d", &n);
    while(n != 0) {
        count = 0;
        hit = 1;                    // 새로운 문자열 받을 때마다 hit와 count 초기화
        scanf("%s", str);
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == '(')
                push('(');          // '('가 입력되면 스택에 추가
            else if (str[i] == ')') {
                if (count == 0) {   // ')'가 입력되고 스택이 비어있다면 VPS가 아니므로 빠져나와서 NO 출력
                    hit = 0;
                    break;
                }
                pop();              // 이상 없다면 pop으로 스택에서 하나 제거
            }
            if (i == strlen(str) - 1 && count != 0)         // 루프가 끝까지 돌았는데 스택이 비어있지 않다면 VPS가 아니므로 NO 출력
                hit = 0;  
        }
        if (hit == 1) 
            printf("YES\n");
        else
            printf("NO\n");
        
        n--;
    }
    return 0;
}