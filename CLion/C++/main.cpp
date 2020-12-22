#include <stdio.h>
#include <malloc.h>
void push(char pch);       //符号的入栈函数
char pop();              //符号的出栈函数
void guiyue();           //规约函数
int getint(char ch);      //得到算符优先值函数
void scanner();          //扫描函数
void show();             //显示函数

//优先关系表
//用1表示大于。-1表示小于，0表示等于，-2表示没有关系
const int table[8][8]={
        {1,1,-1,-1,-1,1,-1,1},
        {1,1,-1,-1,-1,1,-1,1},
        {1,1,1,1,-1,1,-1,1},
        {1,1,1,1,-1,1,-1,1},
        {-1,-1,-1,-1,-1,0,-1,-2},
        {1,1,1,1,-2,1,-2,1},
        {1,1,1,1,-2,1,-2,1},
        {-1,-1,-1,-1,-1,-2,-1,0}
};
//算符
const char suanfu[8]={'-','*','/','(',')','i','#','\0'};
//定义全局变量
char curch;        //当前字符
char curcmp;        //当前比较字符
int right;        //判断是否出错,出错则为0
int k;             //比较字符在栈的位置
int i,j;
//定义一个链表
typedef struct node{
    char lch;
    struct node *next;
}node,Lchar,Lch;

//结点
node *base,*top,*p,*q,*temp;

//显示函数
void show(){
    printf("***************************************************\n");
    printf("|  +  | -  |  * |  /  | (  |  ) |  i  | #  |\n");
    printf("***************************************************\n");
    printf("+");
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(table[i][j]==1){
                printf("|  >  ");
            }
            else if(table[i][j]==-1){
                printf("| <  ");
            }
            else if(table[i][j]==0){
                printf("|  = ");
            }
            else{
                printf("| null");
            }
        }
        printf("|\n%c",suanfu[i]);
    }
    printf("***************************************************\n");
}

//扫描字符串
void scanner(){
    k=1;
    for(;;){
        curch=q->lch;
        temp=top;
        if(temp->lch=='E'){
            break;
        }
        else{
            for(;;){
                if(temp->lch=='E'||temp->lch=='T'||temp->lch=='F'){
                    temp=temp->next;
                    k++;
                }
                else{
                    curcmp=temp->lch;
                    break;
                }
            }
            i=getint(curcmp);
            j=getint(curch);
            printf("\n%d\t%d\t",table[i][j],k);
            temp=top;
            for(;;){        //打印栈
                printf("%c",temp->lch);
                if(temp->lch=='#'){
                    break;
                }
                else
                    temp=temp->next;
            }
            printf("\t\t");
            temp=q;
            for(;;){        //打印待比较的字符
                printf("%c",temp->lch);
                if(temp->lch=='#'){
                    break;
                }
                else
                    temp=temp->next;
            }
            //i=getint(curcmp);
            //j=getint(curch);
            if(table[i][j]==-2){        //算符优先值为空
                printf("\n%d\t%d\t%c\t\t%c\n该字符串不是算符优先法",table[i][j],k,curcmp,curch);
                right=0;
                break;
            }
            else{                      //算法优先值不为空
                if(table[i][j]==-1||table[i][j]==0){
                    if(curch=='#'){
                        if(k==2){           //当前比较字符在栈的位置为两个元素
                            break;
                        }
                        else{
                            printf("\n%d\t%d\t%c\t\t%c\n该字符串不是算符优先法",table[i][j],k,curcmp,curch);
                            right=0;
                            break;
                        }
                    }
                    push(curch);
                    k=1;
                    curcmp=curch;
                    q=q->next;
                }
                else{              //算符优先值为1时，发生归约
                    guiyue();
                }
            }
        }
    }
}

//得到算符优先值函数
int getint(char ch){
    int a;
    switch(ch){
        case '+':a=0;break;
        case '-':a=1;break;
        case '*':a=2;break;
        case '/':a=3;break;
        case '(':a=4;break;
        case ')':a=5;break;
        case 'i':a=6;break;
        case '#':a=7;break;
    }
    return a;
}

//符号的入栈函数
void push(char pch){
    temp=(Lch *)malloc(sizeof(Lchar));
    temp->lch=pch;
    temp->next=top;
    top=temp;
}

//符号的出栈函数
char pop(){
    char ch;
    ch=top->lch;
    if(top->lch!='#'){
        top=top->next;
    }
    return ch;
}

//规约函数
void guiyue(){
    char ch1;
    char ch2;
    char ch3;
    char popch;
    ch1=pop();
    ch2=pop();
    if((ch1>='a'&&ch1<='z')||(ch1>='0'&&ch1<='9')){
        if(ch2=='#'){
            push('F');
            k=1;
        }
        else{
            switch(ch2){
                case '+':popch='T';break;
                case '-':popch='T';break;
                case '*':popch='F';break;
                case '/':popch='F';break;
            }
            push(ch2);
            push(popch);
            k=1;
        }
    }
    else{
        if(ch1=='F'){
            ch3=pop();
            if(ch2=='*'&&ch3=='T'){
                push('T');
            }
            else if(ch2=='/'&&ch3=='T'){
                push('T');
            }
            else
                right=0;
        }
        else if(ch1=='T'){
            ch3=pop();
            if(ch2=='+'&&ch3=='E'){
                push('E');
            }
            else if(ch2=='-'&&ch3=='E'){
                push('E');
            }
            else
                right=0;
        }
    }
}

//主函数
int main(){
    char ch;
    right=1;

    base=(Lch *)malloc(sizeof(Lchar));
    base->next=NULL;
    base->lch='#';
    top=base;
    q=(Lch *)malloc(sizeof(Lchar));
    q->next=NULL;
    p=q;
    printf("本文法为算符优先分析法\n");
    printf("E->E+T|E-T|T\n");
    printf("T->T*F|T/E|F\n");
    printf("F->(E)|i\n");
    show();
    printf("Please input a string(End with#)\n");
    printf("[eg]i+i*i#\n");
    do{                    //输入待比较字符串以#结束
        ch=getchar();
        putchar(ch);
        if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')||
           ch=='+'||ch=='*'||ch=='-'||ch=='/'||ch=='('||ch==')'||ch=='#'){
            temp=(Lch *)malloc(sizeof(Lchar));
            temp->next=NULL;
            temp->lch=ch;
            q->next=temp;
            q=q->next;
        }
        else{
            temp=p->next;
            printf("\nInput a wrong char!Please InputAgain:\n");
            for(;;){
                if(temp!=NULL){
                    printf("%c",temp->lch);
                }
                else
                    break;
                temp=temp->next;
            }
        }
    }while(ch!='#');
    p=p->next;
    q=p;
    scanner();
    if(right){
        printf("\n该字符串归约成功！\n");
    }
    else{
        printf("\n该字符串归约失败！\n");
    }
    getchar();
    getchar();
}