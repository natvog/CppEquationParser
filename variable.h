// CMSC 330 Advanced Programming Languages
// Project 2 Skeleton
// Natalie Vogel Oct 2023


// This file - variable.h - contains the class definition of the Variable class. The variable is represented by its
// name, which the construcor initializes. Because this class is a subclass of Operand which in turn is 
// a subclass of Expression, it must implement the function evaluate, whose body is defined in variable.cpp.

class Variable: public Operand {
public:
    Variable(string name) {
        this->name = name;
    }
    double evaluate();
private:
    string name;
};