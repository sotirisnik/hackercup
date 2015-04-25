#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

#define MAXN 10000001

using namespace std;

int t, A, B, K;
bool P[MAXN+10];
int Primacity[MAXN], Primes[MAXN], idx;

int primacity( int n ) {

    int ret = 0;
    
    int index = 0;
    int i = Primes[index];
    
    while ( n != 1 &&  (i * i) <= n ) {
    
        if ( n % i == 0 ) {
            ++ret;
        }
    
        while ( n % i == 0 ) {
            n /= i;
        }
        
        i = Primes[++index];
    
    }
    
    if ( n != 1 ) {
        ++ret;
    }
    
    return ( ret );

}

bool isprime( int x ) {

    if ( x < 2 ) {
        return ( false );
    }
    
    if ( x % 2 == 0 ) {
        return ( false );
    }
        
    int sqrt_x = sqrt(x)+1;
    
    for ( int i = 3; i < sqrt_x; i += 2 ) {
        if ( x % i == 0 ) {
            return ( false );
        }
    }
    
    return ( true );
    
}

void Sieve( ) {

    for ( int i = 2; i < MAXN; ++i )
        P[i] = true;
    
    int sqrt_MAXN = sqrt( MAXN );
    
    for ( int i = 2; i < sqrt_MAXN; ++i )
        if ( P[i] )
            for ( int j = i*i; j < MAXN; j += i )
                P[j] = false;

    for ( int i = 2; i < MAXN; ++i )
        if ( P[i] ) {
            Primes[ idx++ ] = i;
        }

}

int main( ) {

    Sieve( );
  
    for ( int i = 1; i < MAXN; ++i ) {
        if ( P[i] ) {
            Primacity[i] = 1;
        }else {
            Primacity[i] = primacity( i );
        }
    }
    
    scanf( "%d", &t );
    
    for ( int T = 0; T < t; ++T ) {
    
        scanf( "%d %d %d", &A, &B, &K );
        
        int ans = 0;
        
        for ( int i = A; i <= B; ++i )
            if ( Primacity[i] == K )
                ++ans;
        
        printf( "Case #%d: %d\n", T+1, ans );

    }
    
    return 0;
    
}