#include <stdio.h>


static int Max3(int A, int B, int C)
{
    int max = A;
    if(B > max) { max = B; }
    if(C > max) { max = C; }
    return max;
}


int maxSubArray(const int A[], int N) {
    int subSum = 0;
    int maxSum = A[0];
    for (int i = 0; i < N; i++) {
        subSum += A[i];
        if (subSum > maxSum)
            maxSum = subSum;
        if (subSum < 0)
            subSum = 0;
    }
    return maxSum;
}

        static int
        MaxSubSum( const int A[ ], int Left, int Right )
        {
            int MaxLeftSum, MaxRightSum;
            int MaxLeftBorderSum, MaxRightBorderSum;
            int LeftBorderSum, RightBorderSum;
            int Center, i;

/* 1*/      if( Left == Right )  /* Base case */
/* 2*/          if( A[ Left ] > 0 )
/* 3*/              return A[ Left ];
                else
/* 4*/              return 0;

/* 5*/      Center = ( Left + Right ) / 2;
/* 6*/      MaxLeftSum = MaxSubSum( A, Left, Center );
/* 7*/      MaxRightSum = MaxSubSum( A, Center + 1, Right );

/* 8*/      MaxLeftBorderSum = 0; LeftBorderSum = 0;
/* 9*/      for( i = Center; i >= Left; i-- )
            {
/*10*/          LeftBorderSum += A[ i ];
/*11*/          if( LeftBorderSum > MaxLeftBorderSum )
/*12*/              MaxLeftBorderSum = LeftBorderSum;
            }

/*13*/      MaxRightBorderSum = 0; RightBorderSum = 0;
/*14*/      for( i = Center + 1; i <= Right; i++ )
            {
/*15*/          RightBorderSum += A[ i ];
/*16*/          if( RightBorderSum > MaxRightBorderSum )
/*17*/              MaxRightBorderSum = RightBorderSum;
            }

/*18*/      return Max3( MaxLeftSum, MaxRightSum,
/*19*/                          MaxLeftBorderSum + MaxRightBorderSum );
        }

        int
        MaxSubsequenceSum( const int A[ ], int N )
        {
            return MaxSubSum( A, 0, N - 1 );
        }
/* END */

int main() {
    static int A[ ] = { 4, -3, 5, -2, -1, 2, 6, -2 };
   // int max = maxSubArray(A,9);
printf( "Maxsum = %d\n",
            MaxSubsequenceSum( A, sizeof( A ) / sizeof( A[ 0 ] ) ) );;
printf( "Maxsum = %d\n",
            maxSubArray( A, sizeof( A ) / sizeof( A[ 0 ] ) ) );//the best answer
}
