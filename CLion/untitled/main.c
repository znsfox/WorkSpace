#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <stdbool.h>

char *table[7]={" ","main","int","if","then","else","return"};    //����ؼ���
char *table1[10]={"+","-","*","/","<",">","=",">=","<=","!="};    //�������������
char ch;

int isKey(char *TOKEN)   //�ؼ���ƥ�亯��,��ѯ���������еĹؼ���
{
    int m,i;
    for(i=0;i<=6;i++)
    {
        if((m=strcmp(TOKEN,table[i]))==0)
            return 1;
    }
    return 0;
}
int isOp(char *TOKEN)    //�ж�>= <= !=
{
    int m,i;
    for(i=0;i<=9;i++)
    {
        if((m=strcmp(TOKEN,table1[i]))==0)
            return 1;
    }
    return 0;

}

int judge(int i,char *TOKEN)
{
    int j;
    for(j=1;j<i;j++)
    {
        if(TOKEN[j]>='a'||TOKEN[j]>='A')
            return 1;
    }
    return 0;
}

bool zimu(char ch)//�ж��Ƿ�Ϊ��ĸ
{
    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
        return true;
    else
        return false;
}

bool shuzi(char ch)//�ж��Ƿ�Ϊ����
{
    if(ch>='0'&& ch<='9')
        return true;
    else
        return false;
}

bool fuhao(char ch)
{
    if(ch=='>'||ch=='<'||ch=='!='||ch=='=')
        return true;
    else
        return false;
}

void out(int c,char *TOKEN)    //�������
{
    printf("( %d,��%s��)\n",c,TOKEN);
}

void scanner(FILE *fp)     //ɨ�躯��
{
    char TOKEN[20]={'\0'};
    int i;
    ch=fgetc(fp);  //��ȡ�ַ���ָ��fp���Զ�ָ����һ���ַ�
    if(zimu(ch))  //�жϸ��ַ��Ƿ�����ĸ
    {
        TOKEN[0]=ch;
        ch=fgetc(fp);  //fgetc(fp)���������ж�ȡһ���ַ�
        i=1;
        while(shuzi(ch)|| zimu(ch)) //�жϸ��ַ��Ƿ�����ĸ������
        {
            TOKEN[i]=ch;
            ch=fgetc(fp);
            i++;
        }
        fseek(fp,-1,1);
        if(isKey(TOKEN)) //�ж��ǹؼ��ֻ�����ͨ�ı�ʶ��
            out(1,TOKEN);
        else
            out(2,TOKEN);
    }
    else if(shuzi(ch))
    {
        TOKEN[0]=ch;
        ch=fgetc(fp);  //fgetc(fp)��������������һ���ַ�
        i=1;
        while(shuzi(ch)||zimu(ch)) //�жϸ��ַ��Ƿ�����ĸ������
        {
            TOKEN[i]=ch;
            ch=fgetc(fp);
            i++;
        }
        fseek(fp,-1,1);
        if(judge(i,TOKEN))
            printf("<error,%s>\n",TOKEN);
        else
            out(3,TOKEN);
    }
    else if(fuhao(ch))
    {
        TOKEN[0]=ch;
        ch=fgetc(fp);
        i=1;
        while(fuhao(ch))
        {
            TOKEN[i]=ch;
            ch=fgetc(fp);
            i++;
        }
        fseek(fp,-1,1);
        if(isOp(TOKEN))
            out(4,TOKEN);
        else
            out(4,TOKEN);
    }
        //�жϷָ��������
    else if(ch==',')
    {
        TOKEN[0]=ch;
        out(5,TOKEN);
    }
    else if(ch==';')
    {
        TOKEN[0]=ch;
        out(5,TOKEN);
    }
    else if(ch=='{')
    {
        TOKEN[0]=ch;
        out(5,TOKEN);
    }
    else if(ch=='}')
    {
        TOKEN[0]=ch;
        out(5,TOKEN);
    }
    else if(ch=='(')
    {
        TOKEN[0]=ch;
        out(5,TOKEN);
    }
    else if(ch==')')
    {
        TOKEN[0]=ch;
        out(5,TOKEN);
    }
    else if(ch=='[')
    {
        TOKEN[0]=ch;
        out(5,TOKEN);
    }
    else if(ch==']')
    {
        TOKEN[0]=ch;
        out(5,TOKEN);
    }
}

int main()
{
    FILE* fp;
    if ((fp = fopen("C:\\Users\\fox\\Desktop\\error.txt", "r")) == NULL) {   //��ȡ�ļ����ݣ��������ļ�ָ�룬��ָ��ָ���ļ��ĵ�һ���ַ�
        fprintf(stderr, "error opening.\n");
        exit(1);
    }
    do {
        ch = fgetc(fp);
        if (ch == '#')                //�ļ���#��β����Ϊɨ���������
            break;
        if (ch == ' ')                //����ǿո��Զ������¸��ַ�
            scanner(fp);
        else {
            fseek(fp, -1, 1);        //������ǿո������һ���ַ���ɨ��
            scanner(fp);
        }
    } while (ch != '#');
    return(0);
}
