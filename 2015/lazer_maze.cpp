#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

#define MAXN 101

using namespace std;

struct point {
    int x, y, cost;
    point( ) { }
    point( int x, int y, int cost ) : x(x), y(y), cost(cost) { }
};

int t, Row, Col;
char maze[MAXN][MAXN];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool visited[MAXN][MAXN][4];

bool valid( int x, int y ) {
    if ( x < 0 || y < 0 || x >= Row || y >= Col ) {
        return ( false );
    }
    return ( true );
}

bool is_turret( int x, int y ) {
    return ( maze[x][y] == '<' || maze[x][y] == '>' || maze[x][y] == '^' || maze[x][y] == 'v' );
}

char get_next( char c ) {
    
    if ( c == '^' ) return ( '>' );
    if ( c == '>' ) return ( 'v' );
    if ( c == 'v' ) return ( '<' );
    if ( c == '<' ) return ( '^' );
    
}

bool is_fired( const point tmp ) {

    //down
    for ( int i = 1; tmp.x + i < Row; ++i ) {
    
        int next_x = tmp.x + i;
    
        if ( maze[ next_x ][ tmp.y ] == '#' ) {
            break;
        }
        
        if ( is_turret( next_x, tmp.y ) ) {
            
            int rot = tmp.cost % 4;
            
            int c = maze[ next_x ][ tmp.y ];
            
            while ( rot-- ) {
                c = get_next( c );
            }
            
            if ( c == '^' ) {
                return ( true );
            }
            
            break;
            
        }
        
    }
    
    //up
    for ( int i = 1; tmp.x - i >= 0; ++i ) {
    
        int next_x = tmp.x - i;
    
        if ( maze[ next_x ][ tmp.y ] == '#' ) {
            break;
        }
        
        if ( is_turret( next_x, tmp.y ) ) {
            
            int rot = tmp.cost % 4;
            
            int c = maze[ next_x ][ tmp.y ];
            
            while ( rot-- ) {
                c = get_next( c );
            }
            
            if ( c == 'v' ) {
                return ( true );
            }
            
            break;
            
        }
        
    }
    
    //right
    for ( int i = 1; tmp.y + i < Col; ++i ) {
    
        int next_y = tmp.y + i;
    
        if ( maze[ tmp.x ][ next_y ] == '#' ) {
            break;
        }
        
        if ( is_turret( tmp.x, next_y ) ) {
            
            int rot = tmp.cost % 4;
            
            int c = maze[ tmp.x ][ next_y ];
            
            while ( rot-- ) {
                c = get_next( c );
            }
            
            if ( c == '<' ) {
                return ( true );
            }
            
            break;
            
        }
        
    }
    
    //left
    for ( int i = 1; tmp.y - i >= 0; ++i ) {
    
        int next_y = tmp.y - i;
    
        if ( maze[ tmp.x ][ next_y ] == '#' ) {
            break;
        }
        
        if ( is_turret( tmp.x, next_y ) ) {
            
            int rot = tmp.cost % 4;
            int c = maze[ tmp.x ][ next_y ];
            
            while ( rot-- ) {
                c = get_next( c );
            }
            
            if ( c == '>' ) {
                return ( true );
            }
            
            break;
            
        }
        
    }
    
    return ( false );
    
}

int main( ) {

    scanf( "%d", &t );
    
    for ( int T = 0; T < t; ++T ) {
    
        scanf( "%d %d", &Row, &Col );
        
        for ( int i = 0; i < Row; ++i )
            scanf( " %s", maze[i] );
 
        for ( int i = 0; i < Row; ++i )
            for ( int j = 0; j < Col; ++j )
                for ( int k = 0; k < 4; ++k )
                   visited[i][j][k] = false;
                   
        queue <point> q;
 
        for ( int i = 0; i < Row; ++i )
            for ( int j = 0; j < Col; ++j )
                if ( maze[i][j] == 'S' ) {
                    q.push( point( i, j, 0 ) );
                    maze[i][j] = '.';
                    visited[i][j][0] = true;
                }
     
        printf( "Case #%d: ", T+1 );
        
        bool found = false;
        
        while ( !q.empty() && !found ) {
        
            point top = q.front();
            q.pop();
            
            for ( int k = 0; k < 4 && !found; ++k ) {
                int x = top.x + dx[k];
                int y = top.y + dy[k];
                int next_cost = top.cost + 1;
                if ( valid( x, y ) ) {
                    if ( ( maze[x][y] == '.' || maze[x][y] == 'G' ) && !visited[ x ][ y ][ next_cost%4 ] && !is_fired( point( x, y, next_cost ) ) ) {
                        q.push( point( x, y, next_cost ) );
                        visited[ x ][ y ][ next_cost % 4 ] = true;
                        
                        if ( maze[x][y] == 'G' ) {
                            printf( "%d\n", next_cost );
                            found = true;
                        }
                        
                    }
                }
            }
        
        }
        
        if ( !found ) {
            printf( "impossible\n" );
        }
        
    }

    return 0;
    
}