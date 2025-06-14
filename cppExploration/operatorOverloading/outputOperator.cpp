#include <iostream>
#include <thread>

using namespace std;

struct Cell {
    int row, col;

    // Overload << as a friend function (so it can access private members if needed)
    friend ostream& operator<<(ostream& os, const Cell& cell) {
        os << "Cell(row=" << cell.row << ", col=" << cell.col << ")";
        return os;
    }
};

int main() {

    Cell cellA = {1, 2};

    cout<<"(<<) operator has been overloaded and it will print the cell as it prints built-in types"<<endl; 
    
    cout<<cellA<<endl;

    return 0;
}
