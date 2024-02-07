// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// Natalie Vogel - Oct 2023


// This file - subexpression.cpp - contains the body of the functions contained in The SubExpression class, which includes
// the constructor that initializes the left and right subexpressions and the static function parse
// parses the subexpression. Addition and subtraction are the two operators that are implemented plus
// all additional ones requested by project.

#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "multiply.h"
#include "divide.h"
#include "remainder.h"
#include "exponent.h"
#include "min.h"
#include "max.h"
#include "avg.h"
#include "negate.h"
#include "ternary.h"
#include "quaternary.h"


SubExpression::SubExpression(Expression* left, Expression* right) {
    this->left = left;
    this->right = right;
}

SubExpression::SubExpression(Expression* left, Expression* right, Expression* rightwo) {
    this->left = left;
    this->right = right;
	this->rightwo = rightwo;
}

SubExpression::SubExpression(Expression* left, Expression* right, Expression* rightwo, Expression* righthree) {
    this->left = left;
    this->right = right;
	this->rightwo = rightwo;
	this->righthree = righthree;
}

Expression* SubExpression::parse(stringstream& in) {
    Expression* left;
    Expression* right;
	Expression* rightwo;
	Expression* righthree;
    char operation, paren;
    
    left = Operand::parse(in);
	
    in >> operation;
	
    right = Operand::parse(in);
	
	// check for additional right operands if conditional operators ...
	if ( operation == '?' ) {
		rightwo = Operand::parse(in);
	} 
	if ( operation == '#' )  { 
	  rightwo = Operand::parse(in); 
	  righthree = Operand::parse(in); 
	}
	
	cout << "   subexpression.cpp -> peek at curr token (paren) in stringstream in -> " << (char)in.peek() << endl;  //nv
    in >> paren;
    switch (operation) {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
		// add additional binary operators ...
		case '*':
            return new Multiply(left, right);
		case '/':
            return new Divide(left, right);
		case '%':
            return new Remainder(left, right);
		case '^':
            return new Exponent(left, right);
		case '<':
            return new Min(left, right);
		case '>':
            return new Max(left, right);
		case '&':
            return new Avg(left, right);
		case '~':
            return new Negate(left, right);  
		case '?':
            return new Ternary(left, right, rightwo);  
		case '#':
            return new Quaternary(left, right, rightwo, righthree); 
    }
    return 0;
}
        