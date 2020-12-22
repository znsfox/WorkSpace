//
// Created by fox on 2020/11/18.
//

#include <stdbool.h>
#include <stdio.h>
#include "string.h"
bool even(char *s) {
    int n = strlen(s);
    int i = 0;
    while(2*i < n )
    {
        if(s[i] == s[2*i])
        {
            if((2*i) == (n-1))
            {
                return true;
            }
            i++;
        }
    }
    return false;
}
int main() {
    char *s = "abcabcabcabc";
    // bool j = repeatedSubstringPattern(s);
    //bool j1 = even(s);
   //  printf("%d\n",j1);
    puts(s);
    return 0;
}