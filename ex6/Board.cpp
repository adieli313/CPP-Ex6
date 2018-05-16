#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

#include "Board.h"

Board::Board(const int squer){
    this->squer = squer;
    board = new CheckBoard*[squer];
    for(int i = 0; i < squer; ++i){
    board[i] = new CheckBoard[squer];
    }
        
     for(int i = 0; i < squer; i++) {
       for(int  j = 0; j <  squer; j++) {
           board[i][j] = '.';
        }
    }
}
         
Board::Board(const Board& _board) {
     squer = _board.squer;
     board = new CheckBoard*[squer];
        
     for(int i = 0; i < squer; i++)
        board[i] = new CheckBoard[squer];
                
      for(int i = 0; i < squer; i++) {
         for(int j = 0; j < squer; j++) {
            board[i][j] = _board.board[i][j];
        }
    }
}

Board::~Board(){
    for(int i = 0; i <squer ; ++i) {
       delete[] board[i];
       }
       delete[] board;
}

    
CheckBoard& Board::operator[] (vector<int> point) {
     if (point.at(0) < 0 || point.at(0) >= squer || point.at(1) < 0 || point.at(1) >= squer)
     throw IllegalCoordinateException(point.at(0), point.at(1));
        
     return board[point.at(0)][point.at(1)];
}   

/*   //this doesnt work.
    void Board::printBoard(){ 
         
      int row, col;
     printf("\n    ****Tic Tac Toe****\n");
      for(row = 0; row < squer; row++){
         cout<<row;
          for(col = 0; col < squer; col++){
             printf("  |  ");
            cout<<board[row][col] ;
          }
          printf("  |\n");
          printf("   ------------------------\n");
      }
      for(int i = 0 ; i < squer ; i++){
          printf("     ");
          cout<< i;
      }
    }
    */
    
Board& Board::operator= (char Char) {
     if(Char != '.' && Char != 'X' && Char != 'O')
     throw IllegalCharException(Char);
       
     for(int i = 0; i < squer; i++){
        for(int j = 0; j < squer; j++){
           board[i][j] = Char;
        }
    }
    return *this;
}

Board& Board::operator= (const Board& _board) {
        this->~Board();
        squer = _board.squer;
        board = new CheckBoard*[squer];
        
        for(int i = 0; i < squer; i++)
        board[i] = new CheckBoard[squer];
        
        for(int i = 0; i < squer; i++) {
                for(int j = 0; j < squer; j++) {
                  board[i][j].setP(_board.board[i][j].getP());
        }
    }
    return *this;
}

ostream& operator<<(ostream& os , const Board& board) {
         for(int i=0; i < board.squer; i++){
            for(int j=0; j < board.squer; j++){
                os << board.board[i][j];
               }
               os<< endl;
           }
    return os;
}