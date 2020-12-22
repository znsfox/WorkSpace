#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct
{
    char data[10];
    int top;
    int num;
} message;//ջ��Ԫ�ض���
void create(message*& m)
{
    m = (message*)malloc(sizeof(message));
    m->top = -1;
    m->num = 0;
}
void push(message*& m, char i)//��ջ����
{
    if (m->top < 10)
    {
        m->top++;
        m->data[m->top] = i;
        m->num++;
    }
    else
        cout << "ջ��";
}
char pop(message*& m)//��ջ����
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
        cout << "ջ��";
}
void getStr(char str[])//���������$��β���ַ��� �������ַ���������
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
void output(message* m, char* j)//�����������ջ�����봮�Ĵ���
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
    string b[5][6] = { {"GT","","","GT","",""},//��Ӧ������
                       {"","GT+","","","#","#"},
                       {"SF","","","SF","",""},
                       {"","#","SF*","","#","#"},
                       {"i","","","(E)","",""} };
    int i = -1;
    message* m;
    create(m);
    cout << "�����ַ������ַ�����$��β��" << endl;
    char str[20];
    getStr(str);//��ȡ�ַ���
    char* j = str;
    push(m, '$');//'$'��ջ
    push(m, 'E');//'s'��ջ
    cout << "*************************************���Ŵ���������*************************************" << endl;
    cout << "����ջm\t\t���봮str[j]\t\t����ʽb[][]" << endl;
    while (true) {
        //�ս��ʱ���ж�
        if (m->data[m->top] == 'i' || m->data[m->top] == '+' || m->data[m->top] == '*' || m->data[m->top] == '(' || m->data[m->top] == ')' || m->data[m->top] == '#' || m->data[m->top] == '$')
        {
            if (m->data[m->top] == *j)
            {
                if (m->data[m->top] == '$')//�趨�ս�����
                {
                    output(m, j);//�����������ջ�����봮�Ĵ���
                    cout << "           " << endl;
                    cout << "ok";
                    break;
                }
                else
                {
                    output(m, j);//�����������ջ�����봮�Ĵ���
                    cout << endl;
                    j++;
                    pop(m);
                }
            }
            else
            {
                cout << "����һ������";
                break;
            }
        }
        else{
            output(m, j);//�����������ջ�����봮�Ĵ���
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
                cout << "\t\t" << m->data[m->top] << "->" << "��" << endl;//�������ʽ�������ս������ֵ�ı��ʽͳһ�á�#����
                pop(m);
            }
            else
            {
                cout << "     ";
                cout << "\t\t" << m->data[m->top] << "->" << b[m1][n] << endl;//�������ʽ
                pop(m);
                int k = b[m1][n].size();
                if (b[m1][n] != "")
                {
                    char c[20] = "0";
                    strcpy(c, b[m1][n].c_str());//��Stringת��Ϊ char[]
                    for (int j = 0; j < k; j++)
                    {
                        push(m, c[j]);
                    }
                }
                else
                {
                    cout << "����һ������";
                    break;
                }
            }
        }
    }
}
