// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// Natalie Vogel Oct 2023

// This file - quaternary.h - contains the class definition of the Quaternary class, which is a subclass of SubExpression,
// which in turn is a subclass of the Expression. Because both of its functions are one line functions, 
// they are implemented as inline functions. Its constructor initializes the left remaining right subexpressions
// it inherits from SubExpression by calling the constructor of the SubExpression class. Because
// it is an indirect subclass of Expression it must implement the evaluate function, which it does
// by returning the Quaternary of the 4 operands.

class Quaternary: public SubExpression {
public:
    Quaternary(Expression* left, Expression* right, Expression* rightwo, Expression* righthree): SubExpression(left, right, rightwo, righthree) {
		
    }
    double evaluate()  { 
	   return left->evaluate() < 0 ? right->evaluate() : left->evaluate() == 0 ? rightwo->evaluate() : righthree->evaluate();   
    }
};
