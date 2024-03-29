// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// Natalie Vogel Oct 2023

// This file - subexpression.h - contains the class definition of the SubExpression class, which is a subclass of Expression.
// Because it does not implement the abstract function evalauate, it is an abstract class. SubExpression
// objects are represented with the left and right subexpressions. For conditional operators, additional right subexpressions
// are provided.  The body of its constructor and the static (class) function parse are defined in subexpression.cpp. 

class SubExpression: public Expression {
public:
    SubExpression(Expression* left, Expression* right);
	SubExpression(Expression* left, Expression* right, Expression* rightwo);
	SubExpression(Expression* left, Expression* right, Expression* rightwo, Expression* righthree);
    static Expression* parse(stringstream& in);
protected: 
    Expression* left;
    Expression* right;
	Expression* rightwo;
	Expression* righthree;
};    