// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// Natalie Vogel Oct 2023

// This file - ternary.h - contains the class definition of the Ternary class, which is a subclass of SubExpression,
// which in turn is a subclass of the Expression. Because both of its functions are one line functions, 
// they are implemented as inline functions. Its constructor initializes the left, right, and rightwo subexpressions
// it inherits from SubExpression by calling the constructor of the SubExpression class. Because
// it is an indirect subclass of Expression it must implement the evaluate function, which it does
// by returning the Ternary of the 3 operands

class Ternary: public SubExpression {
public:
    Ternary(Expression* left, Expression* right, Expression* rightwo): SubExpression(left, right, rightwo) {
    }
    double evaluate()  {
       return left->evaluate() ? right->evaluate() : rightwo->evaluate();       // return ternary
    }
};