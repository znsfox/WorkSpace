#include <stdio.h>


unsigned int  Gcd(unsigned int M, unsigned int N)
{
    unsigned int Rem;
    while (N > 0)
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}

int main() {
    int Rel,Tot,i,j;
    int N = 100;
    Rel = 0;
    Tot = 0;
    for ( i = 0; i <= N; i++)
    {
        for (j = i + 1; i <= N; i++)
        {
            Tot++;
            if (Gcd(i, j) == 1)
            {
               Rel++; 
            }
        }
    }
    printf("Percentage of relatively prime pairs is %f\n", (double) Rel / Tot);
    
}

