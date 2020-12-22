#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "string.h"

typedef struct {
    char data[10];
    int top;
    int num;
}message;

void create(message *m)
{
    m = malloc(sizeof(message));
    m->top = -1;
    m->num = 0;
}

void push(message *m, char i) {
    if (m->top < 10) {
        m->data[m->top] = i;
        m->top++;
        m->num++;
    }
}

int pop(message *m) {
    char i;
    if (m->top != -1) {
        i = m->data[m->top];
        m->top--;
        m->num--;
        return i;
    }
    else {
        printf( "ջ��");
    }
}

 void getStr(char* str) {
    int j = 0;
    while (true) {
        scanf("%c",&str[j]);
        if (str[j] == '$')
            break;
        else
            j++;
    }
}

void outPut(message* m, char* strIn) {
    int count = 0;
    for (int i = 0; i < m->num ; i++) {
        printf("%c",m->data[i]);
    }
   printf("\t\t");
    while (*strIn != '$') {
        printf("%c", *strIn);
        strIn++;
        count++;
    }
    printf("$");
    while (count != 0) {
        strIn--;
        count--;
    }
}

int main() {
    char*  table[5][6] = {
                         {"DT","","","DT","",""},//��Ӧ������
                         {"","DT+","","","#","#"},
                         {"CF","","","CF","",""},
                         {"","#","CF*","","#","#"},
                         {"i","","","(E)","",""}
                         };
    int i = -1;
    message* m;
    create(m);
    printf("�����ַ�������$��β��\n");
    char str[20];
    getStr(str);
    char* strInt = str;
    push(m,'$');
    push(m,'E');
    printf("*******************�Ƶ�����*****************\n");
    printf("����ջm\\t\\t���봮str[j]\\t\\t����ʽtable[][]");
    while (true) {
        if (m->data[m->top] == 'i' || m->data[m->top] == '+' || m->data[m->top] == '*' || m->data[m->top] == '(' ||
            m->data[m->top] == ')' || m->data[m->top] == '#' || m->data[m->top] == '$')
        {
            if (m->data[m->top] == *strInt)
            {
                if (m->data[m->top] == '$') {
                    outPut(m, strInt);
                    printf("           \n");
                    printf("ok");
                    break;
                } else
                {
                    outPut(m, strInt);
                    printf("\n");
                    strInt++;
                    pop(m);
                }
            }
            else
            {
                printf("����һ������");
                break;
            }
        }
        else
        {
            outPut(m, strInt);
            int m1 = -1;
            int n = -1;
            switch (*strInt) {
                case 'i':
                    n=0;
                    break;
                case '+':
                    n=1;
                    break;
                case '*':
                    n=2;
                    break;
                case '(':
                    n=3;
                    break;
                case ')':
                    n=4;
                    break;
                case '$':
                    n=5;
                    break;
            }
            switch (m->data[m->top]) {
                case 'E' :
                    m1 = 0;
                    break;
                case 'D':
                    m1 = 1;
                    break;
                case 'T':
                    m1 = 2;
                    break;
                case 'C':
                    m1 = 3;
                    break;
                case 'F':
                    m1 = 4;
                    break;
                default:
                    break;
            }
            if (table[m1][n] == '#') {
                printf("     ");
                printf("\t\t%c->��\n",m->data[m->top]);
                pop(m);
            }
            else
            {
                printf("     ");
                printf("\t\t%c->%c\n",m->data[m->top],table[m1][n]);
                pop(m);
                int k = sizeof(table[m1][n]);
                if (table[m1][n] != ' ') {
                    char c[20] = "0";
                    strcpy(c,table[m1][n]);
                    for (int j = 0; j < k ; j++) {
                        push(m,c[j]);
                    }
                } else
                {
                    printf("����һ������");
                    break;
                }
            }
        }
    }
    return 0;
}
