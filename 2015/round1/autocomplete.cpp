#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <algorithm>

#define MAXN 1000001

using namespace std;

int t, N;
char text[MAXN];

struct state {
    int children[ 26 ];
    int wordCount;
};

state Trie[MAXN];
int trieCount;

void Build( ) {
    trieCount = 1;
    memset( Trie, 0, sizeof( Trie ) );
}

int add( char *text ) {

    int length = strlen( text );
    
    int curNode = 1, nextNode;
    
    int ret = length;
    
    for ( int i = 0; i < length; ++i ) {
        nextNode = Trie[curNode].children[ text[i]-'a' ];
        
        if ( nextNode == 0 ) {
            ret = min( ret, i+1 );
            ++trieCount;
            Trie[ curNode ].children[ text[i]-'a' ] = trieCount;
            curNode = trieCount;
        }else {
            curNode = nextNode;
        }
        
    }
    
    ++Trie[ curNode ].wordCount;

    return ( ret );
    
}

int main( ) {    
    
    scanf( "%d", &t );
    
    for ( int T = 0; T < t; ++T ) {
    
        Build( );
    
        scanf( "%d", &N );
        
        long long ans = 0;
        
        for ( int i = 0; i < N; ++i ) {
            scanf( "%s", text );
            ans += add( text );
        }
        
        printf( "Case #%d: %I64d\n", T+1, ans );
        
    }
    
    return 0;
    
}