#include "common.h"

#define Index(x,y,size)	((x) * (size) + (y))

/********************* The Knight¡¯s tour problem  *****************/
/*
The knight is placed on the first block of an empty board and,
moving according to the rules of chess, must visit each square exactly once.

The 8 moves the knight can go are:

     (-1,2)		(1,2)
(-2,1)				(2,1)
            (0,0)
(-2,-1)				(2,-1)
     (-1,-2)		(1,-2)

Solution:

If all squares are visited
     print the solution
Else
   a) Add one of the next moves to solution vector and recursively
   check if this move leads to a solution.

   b) If the move chosen in the above step doesn't lead to a solution
   then remove this move from the solution vector and try other
   alternative moves.

   c) If none of the alternatives work then return false (Returning false
   will remove the previously added item in recursion and if false is
   returned by the initial call of recursion then "no solution exists" )
*/

#define MOVE_NUM    8

typedef enum _MoveType {
     UpRight = 0,
     RightUp,
     RightDown,
     DownRight,
     DownLeft,
     LeftDown,
     LeftUp,
     UpLeft
}MoveType;

int NextMove[MOVE_NUM][2] = {
     {1,2},{2,1},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}
};

bool CanMove( vector<int> Visited, int x, int y, int BoardSize ) {
     // Check if the move is outside the board
     if ( x<0 || x>BoardSize - 1 || y<0 || y>BoardSize - 1 )
          return false;

     // Check if the move has been visited
     for ( auto i : Visited )
          if ( i == Index(x,y,BoardSize) )
               return false;

     return true;
}

bool KnightSubtour( vector<int>& Visited, int x, int y, int BoardSize ) {
     Visited.push_back( Index(x,y,BoardSize) );
     if ( Visited.size() == BoardSize * BoardSize )
          return TRUE;

     // Try move to next position
     int nextX = 0, nextY = 0;
     for ( int i = 0; i < MOVE_NUM; i++ ) {
          switch ( i )
          {
               case 0:
                    nextX = x + 1;
                    nextY = y + 2;
                    break;
               case 1:
                    nextX = x + 1;
                    nextY = y - 2;
                    break;
               case 2:
                    nextX = x + 2;
                    nextY = y + 1;
                    break;
               case 3:
                    nextX = x + 2;
                    nextY = y - 1;
                    break;
               case 4:
                    nextX = x - 1;
                    nextY = y + 2;
                    break;
               case 5:
                    nextX = x - 1;
                    nextY = y - 2;
                    break;
               case 6:
                    nextX = x - 2;
                    nextY = y - 1;
                    break;
               case 7:
                    nextX = x - 2;
                    nextY = y + 1;
                    break;
               default:
                    break;
          }
          /*nextX = x + NextMove[i][0];
          nextY = y + NextMove[i][1];*/
          if ( !CanMove( Visited, nextX, nextY, BoardSize ) )
               continue;

          // Check if there is a solution when move to next position (nextX, nextY)
          if ( KnightSubtour( Visited, nextX, nextY, BoardSize ) )
               return true;
     }

     Visited.pop_back();
     return false;
}

vector<vector<int>> KnightTour( int BoardSize, int startx, int starty ) {
     vector<int> visited;
     vector<vector<int>> ret;

     if ( KnightSubtour( visited, startx, starty, BoardSize ) ) {
          ret.resize( BoardSize );
          for ( int i = 0; i < ret.size(); i++ ) {
               ret[i].resize( BoardSize );
          }

          for ( int i = 0; i < visited.size(); i++ ) {
               int x = visited[i] / BoardSize;
               int y = visited[i] % BoardSize;
               ret[x][y] = i;
          }

          return ret;
     }

     return { {0} };
}

/* Iterative solution for Knight'Tour problem */
vector<vector<int>> KnightTour_Iterative( int BoardSize, int startx, int starty ) {
     vector<int> visited;
     vector<vector<int>> ret;
     stack<int> candidate;
     bool found = false;

     candidate.push( Index( startx, starty, BoardSize ) );
     while ( !candidate.empty() ) {
          int current = candidate.top();
          if ( current == -1 ) {
               candidate.pop();
               visited.pop_back();
               continue;
          }

          candidate.pop();
          candidate.push( -1 );
          visited.push_back( current );
          int currentX = current / BoardSize;
          int currentY = current % BoardSize;
          if ( visited.size() == BoardSize * BoardSize ) { // Find a solution
               found = true;
               break;
          }

          int nextX = 0, nextY = 0;
          for ( int i = 0; i < MOVE_NUM; i++ ) {
               nextX = currentX + NextMove[i][0];
               nextY = currentY + NextMove[i][1];
               if ( !CanMove( visited, nextX, nextY, BoardSize ) )
                    continue;

               candidate.push( Index( nextX, nextY, BoardSize ) );
          }

     }

     if ( found ) {
          ret.resize( BoardSize );
          for ( int i = 0; i < ret.size(); i++ ) {
               ret[i].resize( BoardSize );
          }

          for ( int i = 0; i < visited.size(); i++ ) {
               int x = visited[i] / BoardSize;
               int y = visited[i] % BoardSize;
               ret[x][y] = i;
          }

          return ret;
     }
     return { {0} };
}

/* Heuristic method for Knight'tour (Warnsdorff¡¯s algorithm)
* Warnsdorff¡¯s Rule:

1. We can start from any initial position of the knight on the board.
2. We always move to an adjacent, unvisited square with minimal degree (minimum number of unvisited adjacent).

* Some definitions:

A position Q is accessible from a position P if P can move to Q by a single Knight¡¯s move, and Q has not yet been visited.
The accessibility of a position P is the number of positions accessible from P.

* Algorithm:

1. Set P to be a random initial position on the board
2. Mark the board at P with the move number ¡°1¡±
3. Do following for each move number from 2 to the number of squares on the board:
     let S be the set of positions accessible from P.
     Set P to be the position in S with minimum accessibility
     Mark the board at P with the current move number
4.Return the marked board ¡ª each square will be marked with the move number on which it is visited.
*/

bool CanMove2( vector<int>& Board, int x, int y, int BoardSize ) {
     // Check if the move is outside the board
     return !( x<0 || x>BoardSize - 1 || y<0 || y>BoardSize - 1 ) &&
          Board[Index( x, y, BoardSize )] == -1;
}

int GetDegree( vector<int> Board, int x, int y, int BoardSize ) {
     int count = 0;
     for ( int i = 0; i < MOVE_NUM; i++ ) {
          if ( CanMove2( Board, x + NextMove[i][0], y + NextMove[i][1], BoardSize ) )
               count++;
     }

     return count;
}

bool HaveNextMove( vector<int>& Board, int& x, int& y, int BoardSize ) {
     int minDegreeIdx = -1, minDegree = MOVE_NUM + 1, minDegreeX, minDegreeY;

     int random = rand() % MOVE_NUM;
     int idx, nextX, nextY, degree;
     for ( int i = 0; i < MOVE_NUM; i++ ) {
          idx = ( i + random ) % MOVE_NUM;
          nextX = x + NextMove[idx][0];
          nextY = y + NextMove[idx][1];

          if ( CanMove2( Board, nextX, nextY, BoardSize ) &&
               ( degree = GetDegree( Board, nextX, nextY, BoardSize ) < minDegree ) ) {
               minDegree = degree;
               minDegreeIdx = idx;
               minDegreeX = nextX;
               minDegreeY = nextY;
          }
     }

     if ( minDegreeIdx == -1 )	return false;	// Cannot find a valid move

     Board[Index( minDegreeX, minDegreeY, BoardSize )] = Board[Index( x, y, BoardSize )] + 1;

     x = minDegreeX;
     y = minDegreeY;
     return true;
}

vector<vector<int>> KnightTour_Heuristic( int BoardSize, int startx, int starty ) {
     vector<int> Board;
     vector<vector<int>> ret;
     bool found = true;
     Board.resize( BoardSize*BoardSize );

     srand( time( NULL ) );
     while ( 1 ) {
          int sx = rand() % BoardSize;
          int sy = rand() % BoardSize;
          for ( auto &i : Board )
               i = -1;
          Board[Index( sx, sy, BoardSize )] = 1;
          found = true;

          for ( int i = 0; i < BoardSize*BoardSize - 1; i++ ) {
               if ( !HaveNextMove( Board, sx, sy, BoardSize ) ) {
                    found = false;
                    break;
               }
          }
          if ( found )	break;
     }


     if ( found ) {
          ret.resize( BoardSize );
          for ( int i = 0; i < ret.size(); i++ ) {
               ret[i].resize( BoardSize );
          }

          for ( int i = 0; i < Board.size(); i++ ) {
               int x = i / BoardSize;
               int y = i % BoardSize;
               ret[x][y] = Board[i];
          }

          return ret;
     }
     return { {0} };
}