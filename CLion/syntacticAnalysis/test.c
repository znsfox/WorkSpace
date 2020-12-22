//
// Created by fox on 2020/11/5.
//
#include<stdio.h>
#include <stdbool.h>
#include "stdlib.h"
#include "string.h"
typedef struct
{
    char data[10];
    int top;
    int num;
} message;//栈内元素对象 
void create(message* m)
{
m = (message*)malloc(sizeof(message));
m->top = -1;
m->num = 0;
}
void push(message* m, char i)//进栈操作 
{
if (m->top < 10)
{
m->top++;
m->data[m->top] = i;
m->num++;
}
else
printf("栈满");
}
char pop(message* m)//出栈操作 
{
char i;
if (m->top != -1)
{
i = m->data[m->top];
m->top--;
m->num--;
return i;
}
else
printf( "栈空");
}
void getStr(char str[])//将输入的以$结尾的字符串 保存于字符串数组中
{
    int j = 0;
    while (true)
    {
        scanf("%c",str[j]);
        if (str[j] == '$')
            break;
        else
            j++;
    }
}
void output(message* m, char* j)//用于输出符号栈与输入串的代码 
{
    int countj = 0;
    for (int i = 0; i < m->num; i++) {
        printf("%c", m->data[i]);
    }
    printf("\t\t") ;
    while (*j != '$')
    {
        printf("%c",*j);
        j++;
        countj++;
    }
    printf("$");
    while (countj != 0)
    {
        j--;
        countj--;
    }
}
int main()
{
    char *b[5][6] = { {"DT","","","DT","",""},//对应分析表
                       {"","DT+","","","#","#"},
                       {"CF","","","CF","",""},
                       {"","#","CF*","","#","#"},
                       {"i","","","(E)","",""} };
    int i = -1;
    message* m;
    create(m);
    printf( "输入字符串，字符串以$结尾。\n");
    char str[20];
    getStr(str);//获取字符串 
    char* j = str;
    push(m, '$');//'$'进栈 
    push(m, 'E');//'s'进栈 
    printf( "*************************************符号串分析过程*************************************\n");
    printf( "符号栈m\t\t输入串str[j]\t\t产生式b[][]\n");
    while (true) {
        //终结符时的判断 
        if (m->data[m->top] == 'i' || m->data[m->top] == '+' || m->data[m->top] == '*' || m->data[m->top] == '(' || m->data[m->top] == ')' || m->data[m->top] == '#' || m->data[m->top] == '$')
        {
            if (m->data[m->top] == *j)
            {
                if (m->data[m->top] == '$')//设定终结条件 
                {
                    output(m, j);//用于输出符号栈与输入串的代码 
                    printf("           \n");
                    printf( "ok");
                    break;
                }
                else
                {
                    output(m, j);//用于输出符号栈与输入串的代码 
                    printf("\n");
                    j++;
                    pop(m);
                }
            }
            else
            {
                printf( "不是一个句子");
                break;
            }
        }
        else{
            output(m, j);//用于输出符号栈与输入串的代码 
            int m1 = -1;
            int n = -1;
            switch (*j)
            {
                case 'i':n = 0; break;
                case '+':n = 1; break;
                case '*':n = 2; break;
                case '(':n = 3; break;
                case ')':n = 4; break;
                case '$':n = 5; break;
            }
            switch (m->data[m->top])
            {
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
            if (b[m1][n] == "#")
            {
                printf( "     ");
                printf( "\t\t%c->空\n", m->data[m->top]);//输出产生式（给非终结符赋空值的表达式统一用‘#’表达）
                pop(m);
            }
            else
            {
                printf( "     ");
                printf( "\t\t %c->%s\n",m->data[m->top] ,b[m1][n]);//输出产生式
                pop(m);
                int k = sizeof(b[m1])/sizeof(b[m1][n]);
                if (b[m1][n] != "")
                {
                    char c[20] = "0";
                    strcpy(c, b[m1][n]);//将String转化为 char[]
                    for (int j = 0; j < k; j++)
                    {
                        push(m, c[j]);
                    }
                }
                else
                {
                    printf( "不是一个句子");
                    break;
                }
            }
        }
    }
}


