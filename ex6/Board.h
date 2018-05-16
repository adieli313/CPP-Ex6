#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <list>

#include "CheckBoard.h"
#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"

using namespace std;


class Board {
    public:
    
        //friend class CheckBoard;
    
        Board(const int squer);
        
        Board(const Board& board); 
        
        ~Board();
        
        Board& operator= (char Char);
        
        Board& operator= (const Board& board);

        CheckBoard& operator [](vector<int> point);
     
        friend ostream& operator<< (ostream& os, const Board& board);
        
        void printBoard();
        
    private:
    
        CheckBoard** board;
    
        int squer;

};

#endif
