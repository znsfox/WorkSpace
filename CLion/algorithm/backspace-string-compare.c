//
// Created by fox on 2020/11/17.
//

#include <stdbool.h>
#include <mem.h>
#include <stdio.h>
#include <malloc.h>

char *build(char* t) {
    int len = strlen(t);
    int top = -1;
    char *stack = malloc(sizeof(char) * (len + 1));
    for(int i = 0; i < len; i++)
    {
        if(t[i] != '#' ) stack[++top] = t[i];
        else if (top >= 0)
            top--;
    }
    stack[++top] = '\0';
    return stack;
}

int main() {
  char* t = "abcd";
  char *m = build(t);
  puts(m);

}