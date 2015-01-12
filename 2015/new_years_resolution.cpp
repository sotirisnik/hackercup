#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

#define MAXN 21

using namespace std;

int t, Gp, Gc, Gf, N;
int P[MAXN], C[MAXN], F[MAXN];
bool found;

void dfs( int i, int p ,int c, int f ) {

    if ( i < 0 || p < 0 || c < 0 || f < 0 || found ) {
        return;
    }
    
    if ( p == 0 && c == 0 && f == 0 ) {
        found = true;
        return;
    }
    
    dfs( i-1, p, c, f );
    dfs( i-1, p - P[i], c - C[i], f-F[i] );

}

int main( ) {

    scanf( "%d", &t );
    
    for ( int T = 0; T < t; ++T ) {
    
        scanf( "%d %d %d", &Gp, &Gc, &Gf );
        
        scanf( "%d", &N );
        
        for ( int i = 1; i <= N; ++i ) {
            scanf( "%d %d %d", &P[i], &C[i], &F[i] );
        }
 
        found = false;
 
        dfs( N, Gp, Gc, Gf );
 
        printf( "Case #%d: ", T+1 );
        
        if ( found ) {
            printf( "yes\n" );
        }else {
            printf( "no\n" );
        }
        
    }

    return 0;
    
}