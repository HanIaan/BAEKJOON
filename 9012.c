#include <stdio.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int count = 0;

void push(char value) {
    stack[count++] = value;
}

char pop() {
    return stack[--count];
}

int main() {
    int n;
    int hit = 1;
    char str[50];
    scanf("%d", &n);
    while(n != 0) {
        count = 0;
        hit = 1;
        scanf("%s", str);
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == '(')
                push('(');
            else if (str[i] == ')') {
                if (count == 0) {
                    hit = 0;
                    break;
                }
                pop();
            }
            if (i == strlen(str) - 1 && count != 0)
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