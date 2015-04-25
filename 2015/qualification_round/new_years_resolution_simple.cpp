#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

#define MAXN 21

using namespace std;

int t, Gp, Gc, Gf, N, p, c, f;
int P[MAXN], C[MAXN], F[MAXN];
bool found;

int main( ) {

    scanf( "%d", &t );
    
    for ( int T = 0; T < t; ++T ) {
    
        scanf( "%d %d %d", &Gp, &Gc, &Gf );
        
        scanf( "%d", &N );
        
        for ( int i = 0; i < N; ++i ) {
            scanf( "%d %d %d", &P[i], &C[i], &F[i] );
        }
 
        found = false;
 
        for ( int i = 0; i < (1<<N); ++i ) {
        
            p = Gp;
            c = Gc;
            f = Gf;
            
            for ( int j = 0; j < N; ++j ) {
                if ( i & (1<<j) ) {
                    p -= P[j];
                    c -= C[j];
                    f -= F[j];
                }
            }
            
            if ( p == 0 && c == 0 && f == 0 ) {
                found = true;
                break;
            }
            
        }
 
        printf( "Case #%d: ", T+1 );
        
        if ( found ) {
            printf( "yes\n" );
        }else {
            printf( "no\n" );
        }
        
    }

    return 0;
    
}