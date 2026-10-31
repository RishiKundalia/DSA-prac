
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *next;
};

struct Node *top = NULL;

void push(char x) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}

char pop() {
    if (!top) return '\0';
    struct Node *t = top;
    char x = t->data;
    top = top->next;
    free(t);
    return x;
}

int prec(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

void postfix(char in[], char out[]) {
    int i, j = 0;
    for (i = 0; in[i]; i++) {
        char c = in[i];

        if (isalnum(c)) out[j++] = c;
        else if (c == '(') push(c);
        else if (c == ')') {
            while (top && top->data != '(')
                out[j++] = pop();
            pop();
        }
        else {
            while (top && top->data != '(' &&
                   prec(top->data) >= prec(c))
                out[j++] = pop();
            push(c);
        }
    }
    while (top) out[j++] = pop();
    out[j] = '\0';
}

void reverse(char s[]) {
    int i, j = strlen(s) - 1;
    char t;
    for (i = 0; i < j; i++, j--) {
        t = s[i]; s[i] = s[j]; s[j] = t;
    }
}

int main() {
    char in[100], post[100], pre[100];

    printf("Enter infix: ");
    scanf("%99s", in);

    postfix(in, post);
    printf("Postfix: %s\n", post);

    reverse(in);
    for (int i = 0; in[i]; i++) {
        if (in[i] == '(') in[i] = ')';
        else if (in[i] == ')') in[i] = '(';
    }

    postfix(in, pre);
    reverse(pre);

    printf("Prefix: %s\n", pre);
    return 0;
}
