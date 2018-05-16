
#ifndef CHECKBOARD_H
#define CHECKBOARD_H

#include <iostream>


#include "IllegalCharException.h"
#include "IllegalCoordinateException.h"

using namespace std;

class CheckBoard {

    public:
        
        CheckBoard();
        
        CheckBoard(char Char);
    
        void setP(char Char);

        char getP() const;

        void operator= (char Char);

        operator char() const;
    
    
    private:
    
        char piece;
        
        friend ostream& operator<< (ostream& os, const CheckBoard& piece);
};

#endif