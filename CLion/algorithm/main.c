#include <stdbool.h>
#include "stdio.h"
#include "string.h"
bool odd(char *s) {
    int n = strlen(s);
    int i = 0;
    while(i < n)
    {
        if(s[i++] != s[0])
            return false;
    }
    return true;
}

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
static bool repeatedSubstringPattern(char * s){
    bool judge = false;
    int n = strlen(s);
    if (n%2 == 0 ) {
        judge = even(s);
    } else {
        judge = odd(s);
    }
    puts(s);
    return judge;
}

int main(){
    char *s = "abcabcabcabc";
    bool j = repeatedSubstringPattern(s);
    bool j1 = even(s);
    printf("%d",j1);
    puts(s);
    return 0;
}