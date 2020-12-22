#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct
{
    char data[10];
    int top;
    int num;
} message;//栈内元素对象
void create(message*& m)
{
    m = (message*)malloc(sizeof(message));
    m->top = -1;
    m->num = 0;
}
void push(message*& m, char i)//进栈操作
{
    if (m->top < 10)
    {
        m->top++;
        m->data[m->top] = i;
        m->num++;
    }
    else
        cout << "栈满";
}
char pop(message*& m)//出栈操作
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
        cout << "栈空";
}
void getStr(char str[])//将输入的以$结尾的字符串 保存于字符串数组中
{
    int j = 0;
    while (true)
    {
        cin >> str[j];
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
        cout << m->data[i];
    }
    cout << "\t\t";
    while (*j != '$')
    {
        cout << *j;
        j++;
        countj++;
    }
    cout << "$";
    while (countj != 0)
    {
        j--;
        countj--;
    }
}
int main()
{
    string b[5][6] = { {"GT","","","GT","",""},//对应分析表
                       {"","GT+","","","#","#"},
                       {"SF","","","SF","",""},
                       {"","#","SF*","","#","#"},
                       {"i","","","(E)","",""} };
    int i = -1;
    message* m;
    create(m);
    cout << "输入字符串，字符串以$结尾。" << endl;
    char str[20];
    getStr(str);//获取字符串
    char* j = str;
    push(m, '$');//'$'进栈
    push(m, 'E');//'s'进栈
    cout << "*************************************符号串分析过程*************************************" << endl;
    cout << "符号栈m\t\t输入串str[j]\t\t产生式b[][]" << endl;
    while (true) {
        //终结符时的判断
        if (m->data[m->top] == 'i' || m->data[m->top] == '+' || m->data[m->top] == '*' || m->data[m->top] == '(' || m->data[m->top] == ')' || m->data[m->top] == '#' || m->data[m->top] == '$')
        {
            if (m->data[m->top] == *j)
            {
                if (m->data[m->top] == '$')//设定终结条件
                {
                    output(m, j);//用于输出符号栈与输入串的代码
                    cout << "           " << endl;
                    cout << "ok";
                    break;
                }
                else
                {
                    output(m, j);//用于输出符号栈与输入串的代码
                    cout << endl;
                    j++;
                    pop(m);
                }
            }
            else
            {
                cout << "不是一个句子";
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
                case 'G':
                    m1 = 1;
                    break;
                case 'T':
                    m1 = 2;
                    break;
                case 'S':
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
                cout << "     ";
                cout << "\t\t" << m->data[m->top] << "->" << "空" << endl;//输出产生式（给非终结符赋空值的表达式统一用‘#’表达）
                pop(m);
            }
            else
            {
                cout << "     ";
                cout << "\t\t" << m->data[m->top] << "->" << b[m1][n] << endl;//输出产生式
                pop(m);
                int k = b[m1][n].size();
                if (b[m1][n] != "")
                {
                    char c[20] = "0";
                    strcpy(c, b[m1][n].c_str());//将String转化为 char[]
                    for (int j = 0; j < k; j++)
                    {
                        push(m, c[j]);
                    }
                }
                else
                {
                    cout << "不是一个句子";
                    break;
                }
            }
        }
    }
}
