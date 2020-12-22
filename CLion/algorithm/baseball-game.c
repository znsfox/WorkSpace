//
// Created by fox on 2020/11/13.
//

#include "stdio.h"

int main() {
   // char **ops = {"5","2","C","D","+"};
   /* printf("%d\n",sizeof(ops));
    printf("%c\n",ops[1][0]);*/
  //  int opsSize = sizeof(ops)/sizeof(ops[1][0]);
    //printf("%d\n",opsSize);
   // puts(ops[1][0]);
   int entity = 3;
   /*int *p;
   p = &entity;*/
   int *p = &entity;
   printf("%d",p);
}