999. Available Captures for Rook
Easy

60

116

Favorite

Share
On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively. Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions (north, east, west, and south), then moves in that direction until it chooses to stop, reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies.  Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

 

Example 1:



Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
In this example the rook is able to capture all the pawns.
Example 2:



Input: [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 0
Explanation: 
Bishops are blocking the rook to capture any pawn.
Example 3:



Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
The rook can capture the pawns at positions b5, d6 and f5.
 

Note:

board.length == board[i].length == 8
board[i][j] is either 'R', '.', 'B', or 'p'
There is exactly one cell with board[i][j] == 'R'

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rx=-1, ry=-1, res=0;
        for (int i=0; i<8; ++i) {
            for (int j=0; j<8; ++j) {
                if (board[i][j]=='R') {
                    rx=i;
                    ry=j;
                    break;
                }
            }
            if (rx!=-1) break;
        }
        
        for (int k=0; k<4; ++k) {
            for (int i=rx+delta[k][0], j=ry+delta[k][1]; i>=0 && i<8 && j>=0 && j<8; i+=delta[k][0], j+=delta[k][1]) {
                if (board[i][j]=='p') res++;
                if (board[i][j]!='.') break;
            }
        }
        
        return res;
    }
private:
    const int delta[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
};
