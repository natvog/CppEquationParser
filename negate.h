// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// Natalie Vogel - Oct 2023

// This file - negate.h - contains the class definition of the Negate class, which is a subclass of SubExpression,
// which in turn is a subclass of the Expression. Because both of its functions are one line functions, 
// they are implemented as inline functions. Its constructor initializes the left and right subexpressions
// it inherits from SubExpression by calling the constructor of the SubExpression class. Because
// it is an indirect subclass of Expression it must implement the evaluate function, which it does
// by returning the negation of the results of the expressions.

class Negate: public SubExpression {
public:
    Negate(Expression* left, Expression* right): SubExpression(left, right) {
    }
    double evaluate()  {
       return ( left->evaluate() ) * -1;    // return negative
    }
};