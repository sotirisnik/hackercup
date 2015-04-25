#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <algorithm>

#define MAXN 2001
#define MODN 1000000007

using namespace std;

int t, A, B, K;
int memodp_free[MAXN][MAXN], memodp_full[MAXN][MAXN];

int dp_free( int A, int B ) {

    if ( A < 0 || B < 0 ){
        return 0;
    }

    if ( A > 0 && B == 0 ) {
        return 1;
    }
    
    if ( memodp_free[A][B] != -1 ) {
        return ( memodp_free[A][B] );
    }
    
    int Best = 0;
    
    if ( A-1 > B ) {
        Best += dp_free( A-1, B );
        Best %= MODN;
    }
    
    Best += dp_free( A, B-1 );
    Best %= MODN;
    
    memodp_free[A][B] = Best;
    
    return ( memodp_free[A][B] );

}

int dp_full( int A, int B, int finalA, int finalB ) {

    if ( A == finalA && B == finalB ) {
        return 1;
    }
    
    if ( A > finalA || B > finalB ) {
        return 0;
    }
    
    if ( memodp_full[A][B] != -1 ) {
        return ( memodp_full[A][B] );
    }
    
    int Best = 0;
    
    if ( A+1 <= B && B != finalB  ) {
        Best += dp_full( A+1, B, finalA, finalB );
        Best %= MODN;
    }
    
    if ( B == finalB ) {
        Best += dp_full( A+1, B, finalA, finalB );
        Best %= MODN;
    }
    
    Best += dp_full( A, B+1, finalA, finalB );
    Best %= MODN;
    
    memodp_full[A][B] = Best;
    
    return ( memodp_full[A][B] );
    
}

int main( ) {

    scanf( "%d", &t );
    
    for ( int T = 0; T < t; ++T ) {
    
        scanf( "%d-%d", &A, &B );
        
        memset( memodp_free, -1, sizeof( memodp_free ) );
        memset( memodp_full, -1, sizeof( memodp_full ) );
        
        int ans = dp_free( A, B );
        int ans2 = dp_full( 0, 0, A, B );
        
        printf( "Case #%d: %d %d\n", T+1, ans, ans2 );

    }
    
    return 0;
    
}