
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

    void operator+=(int value) {
        row += value;
        col += value;
    }
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

    return 0;
}

/*
    1. An operator function must have at least one function parameter or implicit object parameter whose type
        is a class, a reference to a class, an enumeration, or a reference to an enumeration.


    First Observation
        we can't change the number of arguments list while overloading the operator, ex -> below
        we can't receive two arguments like "Cell operator=(const Cell& otherA, const Cell& otherB)" or 
        "Cell operator=(const Cell& otherA, int a)"

            Cell operator=(const Cell& other) {
                if (&other == this) return *this; // must have
                row = other.row;
                col = other.col;
                return *this;
            }

        so this tells us that the syntax for overloading an operator is fixed across classes and we can only put
        out logic inside the defined function.

    According to this rule my first understanding is that since in the first overloading(=) we are taking (const Cell& other)
    as argument so it's fine as per the rule. but when i tried to override operator(+=) then it also works fine. And the reason for that
    as per Deepseek is below
        
        Great observation! Let me clarify why your `operator+=` works even though it doesn't explicitly take a `Cell` parameter.

        ### The Implicit `this` Parameter
        In C++, **non-static member functions** (including overloaded operators) have an **implicit `this` parameter** that refers to the object on which the function is called. This means:
        
            void operator+=(int value) {
                row += value;   // equivalent to: this->row += value;
                col += value;   // equivalent to: this->col += value;
            }
        
        is treated as if it were:
        
            void operator+=(Cell* this, int value) {
                this->row += value;
                this->col += value;
            }
        
        (Note: You can't actually write it this way—it's just how the compiler sees it.)

        ---

        ### Why It Doesn't Violate the First Rule
        The rule states:
        > *"An operator function must have at least one function parameter or implicit object parameter whose type is a class, a reference to a class, an enumeration, or a reference to an enumeration."*

        In your case:
        - The **implicit `this` parameter** (of type `Cell*`) satisfies this requirement because it points to a class (`Cell`).
        - The explicit parameter is `int value` (a built-in type).

        Thus, the rule is **not violated** because the implicit `this` counts as a class-type parameter.

*/
