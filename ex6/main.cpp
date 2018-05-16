#include "Board.h"

#include <iostream>
using namespace std;

int main() {
    Board board1{4};  // Initializes a 4x4 board
    cout << board1 << endl;   /* Shows an empty board:
	....
	....
	....
	....
	*/
    board1[{1,1}]='X';
    board1[{1,2}]='O';
    cout << board1 << endl;  /* Shows the following board:
	....
	.XO.
	....
	....
	*/

    try {
        board1[{3,4}]='O';   // This should raise an exception
    } catch (const string& message) {
        cout << message << endl;
    }

    board1 = '.';     // Fill the entire board with "."
    cout << board1 << endl;  /* Shows an empty board, as above */
    try {
        board1 = 'a';        // This should raise an exception
    } catch (const string& message) {
        cout << message << endl;  // "Illegal char: a"
    }

    try {
        board1[{0,1}] = 'x';  // This should raise an exception
    } catch (const string& message) {
        cout << message << endl;
    }
    Board board2 = board1;
    board2[{0,0}] = 'X';
    cout << board1 << endl;  /* Shows an empty board, as above */
    cout << board2 << endl;  /* Shows a board with an X at top-left */

    board1 = board2;
    board1[{3,3}] = 'O';
    cout << board2 << endl;  /* Shows a board with an X at top-left */
    cout << board1 << endl;  /* Shows a board with an X at top-left and O at bottom-right */

    return 0;
}