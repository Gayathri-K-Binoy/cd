#include <stdio.h>
#include <string.h>
#define MAX 50
char stack[MAX], input[MAX], terminals[10], table[10][10];
int n;
int idx(char c) {
    for (int i = 0; i < n; i++)
        if (terminals[i] == c) return i;
    return -1;
}
int main() {
    int i, j, top = 0;
    char a, b;
    printf("No. of terminals: ");
    scanf("%d", &n);
    printf("Enter terminals (e.g. + * i $): ");
    scanf("%s", terminals);
    printf("Enter precedence table (<, >, =):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf(" %c", &table[i][j]);
    printf("\nInput string: ");
    scanf("%s", input);
    strcat(input, "$");
    stack[top] = '$';
    i = 0;
    printf("\nStack\tInput\tAction\n");
    while (1) {
        a = stack[top];
        while (a == '<' && top > 0) a = stack[--top];
        b = input[i];
        int x = idx(a), y = idx(b);
        if (x == -1 || y == -1) { printf("Error\n"); break; }
        if (a == '$' && b == '$') { printf("Accepted\n"); break; }
        if (table[x][y] == '<' || table[x][y] == '=') {
            stack[++top] = '<';
            stack[++top] = b;
            stack[top + 1] = '\0';
            i++;
            printf("%s\t%s\tShift\n", stack, &input[i]);
        } 
        else if (table[x][y] == '>') {
            while (top > 0 && stack[top] != '<') top--;
            stack[top + 1] = '\0';
            printf("%s\t%s\tReduce\n", stack, &input[i]);
        } 
        else {
            printf("Rejected\n");
            break;
        }
    }
}