#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

char *table[7]={" ","main","int","if","then","else","return"};    //定义关键字
char *operator[10]={"+","-","*","/","<",">","=",">=","<=","!="};    //定义运算符符号
char ch;

int lookup(char *token)   //关键字匹配函数,查询所述程序中的关键字
{
    int m,i;
    for(i=0;i<=6;i++)
    {
        if((m=strcmp(token,table[i]))==0)
            return 1;
    }
    return 0;
}
int isOp(char *token)    //判断>= <= !=
{
    int m,i;
    for(i=0;i<=9;i++)
    {
        if((m=strcmp(token,operator[i]))==0)
            return 1;
    }
    return 0;

}

int judge(int i,char *token)
{
    int j;
    for(j=1;j<i;j++)
    {
        if(token[j]>='a'||token[j]>='A')
            return 1;
    }
    return 0;
}

bool zimu(char ch)//判断是否为字母
{
    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
        return true;
    else
        return false;
}

bool shuzi(char ch)//判断是否为数字
{
    if(ch>='0'&& ch<='9')
        return true;
    else
        return false;
}

bool fuhao(char ch)
{
    if(ch=='>'||ch=='<'||ch=='!'||ch=='=')
        return true;
    else
        return false;
}

void out(int c,char *token)    //输出函数
{
    printf("( %d,“%s”)\n",c,token);
}

void scanner(FILE *fp)     //扫描函数
{
    char token[20]={'\0'};
    int i;
    ch=fgetc(fp);  //获取字符，指针fp并自动指向下一个字符
    if(zimu(ch))  //判断该字符是否是字母
    {
        token[0]=ch;
        ch=fgetc(fp);  //fgetc(fp)从数据流中读取一个字符
        i=1;
        while(shuzi(ch)|| zimu(ch)) //判断该字符是否是字母或数字
        {
            token[i]=ch;
            ch=fgetc(fp);
            i++;
        }
        fseek(fp,-1,1);
        if(lookup(token)) //判断是关键字还是普通的标识符
            out(1,token);
        else
            out(2,token);
    }
    else if(shuzi(ch))
    {
        token[0]=ch;
        ch=fgetc(fp);  //fgetc(fp)从数据流中区下一个字符
        i=1;
        while(shuzi(ch)||zimu(ch)) //判断该字符是否是字母或数字
        {
            token[i]=ch;
            ch=fgetc(fp);
            i++;
        }
        fseek(fp,-1,1);
        if(judge(i,token))
            printf("<error,%s>\n",token);
        else
            out(3,token);
    }
    else if(fuhao(ch))
    {
        token[0]=ch;
        ch=fgetc(fp);
        i=1;
        while(fuhao(ch))
        {
            token[i]=ch;
            ch=fgetc(fp);
            i++;
        }
        fseek(fp,-1,1);
        if(isOp(token))
            out(4,token);
        else
            out(4,token);
    }
        //判断分隔符并输出
    else if(ch==',')
    {
        token[0]=ch;
        out(5,token);
    }
    else if(ch==';')
    {
        token[0]=ch;
        out(5,token);
    }
    else if(ch=='{')
    {
        token[0]=ch;
        out(5,token);
    }
    else if(ch=='}')
    {
        token[0]=ch;
        out(5,token);
    }
    else if(ch=='(')
    {
        token[0]=ch;
        out(5,token);
    }
    else if(ch==')')
    {
        token[0]=ch;
        out(5,token);
    }
    else if(ch=='[')
    {
        token[0]=ch;
        out(5,token);
    }
    else if(ch==']')
    {
        token[0]=ch;
        out(5,token);
    }


}

int main()
{
    FILE* fp;
    if ((fp = fopen("C:\\Users\\fox\\Desktop\\error.txt", "r")) == NULL) {   //读取文件内容，并返回文件指针，该指针指向文件的第一个字符
        fprintf(stderr, "error opening.\n");
        exit(1);
    }
    do {
        ch = fgetc(fp);
        if (ch == '#')                //文件以#结尾，作为扫描结束条件
            break;
        if (ch == ' ')                //如果是空格，自动跳到下个字符
            scanner(fp);
        else {
            fseek(fp, -1, 1);        //如果不是空格，则回退一个字符并扫描
            scanner(fp);
        }
    } while (ch != '#');
    return(0);
}
