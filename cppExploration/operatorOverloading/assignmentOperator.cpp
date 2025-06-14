#include <iostream>
#include <thread>

using namespace std;

struct Cell {
    int row, col;

    Cell operator=(const Cell& other) {
        if (&other == this) return *this; // must have
        row = other.row;
        col = other.col;
        return *this;
    }

    // Cell operator+=(int value) {
    //     row += value;
    //     col += value;
    //     return *this;
    // }

    // static void operator+=( int value) {
    //     row += value;
    //     col += value;
    // }

    // Cell operator+=(const Cell& other) {
    //     row += other.row;
    //     col += other.col;
    //     return *this;
    // }

};

int main() {

    Cell cellA = {1, 2};
    
    Cell cellB = {3, 4};

    cellA = cellB;

    cout<<"after modification, the cell will be row:3 , col: 4"<<endl;
    cout<<cellA.row<<" "<<cellA.col<<endl;

    cellA += 2;
    cout<<"after +=2, the cell will be row:5 , col: 6"<<endl;
    cout<<cellA.row<<" "<<cellA.col<<endl;
    
    // cellA += cellB;
    // cout<<"after += cellB, the cell will be row:8 , col: 10"<<endl;
    // cout<<cellA.row<<" "<<cellA.col<<endl;

    return 0;
}

/*
    some learnings from this example
        1. this is a pointer (of type Cell* in your example) that points to the current object.
        2. *this dereferences the this pointer, giving you the actual object itself (of type Cell in your example).
*/