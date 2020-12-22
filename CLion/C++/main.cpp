#include <stdio.h>
#include <malloc.h>
void push(char pch);       //���ŵ���ջ����
char pop();              //���ŵĳ�ջ����
void guiyue();           //��Լ����
int getint(char ch);      //�õ��������ֵ����
void scanner();          //ɨ�躯��
void show();             //��ʾ����

//���ȹ�ϵ��
//��1��ʾ���ڡ�-1��ʾС�ڣ�0��ʾ���ڣ�-2��ʾû�й�ϵ
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
//���
const char suanfu[8]={'-','*','/','(',')','i','#','\0'};
//����ȫ�ֱ���
char curch;        //��ǰ�ַ�
char curcmp;        //��ǰ�Ƚ��ַ�
int right;        //�ж��Ƿ����,������Ϊ0
int k;             //�Ƚ��ַ���ջ��λ��
int i,j;
//����һ������
typedef struct node{
    char lch;
    struct node *next;
}node,Lchar,Lch;

//���
node *base,*top,*p,*q,*temp;

//��ʾ����
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

//ɨ���ַ���
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
            for(;;){        //��ӡջ
                printf("%c",temp->lch);
                if(temp->lch=='#'){
                    break;
                }
                else
                    temp=temp->next;
            }
            printf("\t\t");
            temp=q;
            for(;;){        //��ӡ���Ƚϵ��ַ�
                printf("%c",temp->lch);
                if(temp->lch=='#'){
                    break;
                }
                else
                    temp=temp->next;
            }
            //i=getint(curcmp);
            //j=getint(curch);
            if(table[i][j]==-2){        //�������ֵΪ��
                printf("\n%d\t%d\t%c\t\t%c\n���ַ�������������ȷ�",table[i][j],k,curcmp,curch);
                right=0;
                break;
            }
            else{                      //�㷨����ֵ��Ϊ��
                if(table[i][j]==-1||table[i][j]==0){
                    if(curch=='#'){
                        if(k==2){           //��ǰ�Ƚ��ַ���ջ��λ��Ϊ����Ԫ��
                            break;
                        }
                        else{
                            printf("\n%d\t%d\t%c\t\t%c\n���ַ�������������ȷ�",table[i][j],k,curcmp,curch);
                            right=0;
                            break;
                        }
                    }
                    push(curch);
                    k=1;
                    curcmp=curch;
                    q=q->next;
                }
                else{              //�������ֵΪ1ʱ��������Լ
                    guiyue();
                }
            }
        }
    }
}

//�õ��������ֵ����
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

//���ŵ���ջ����
void push(char pch){
    temp=(Lch *)malloc(sizeof(Lchar));
    temp->lch=pch;
    temp->next=top;
    top=temp;
}

//���ŵĳ�ջ����
char pop(){
    char ch;
    ch=top->lch;
    if(top->lch!='#'){
        top=top->next;
    }
    return ch;
}

//��Լ����
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

//������
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
    printf("���ķ�Ϊ������ȷ�����\n");
    printf("E->E+T|E-T|T\n");
    printf("T->T*F|T/E|F\n");
    printf("F->(E)|i\n");
    show();
    printf("Please input a string(End with#)\n");
    printf("[eg]i+i*i#\n");
    do{                    //������Ƚ��ַ�����#����
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
        printf("\n���ַ�����Լ�ɹ���\n");
    }
    else{
        printf("\n���ַ�����Լʧ�ܣ�\n");
    }
    getchar();
    getchar();
}