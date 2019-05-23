// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Expr_Node_Visitor.h"
#include "Num_Node.h"

//Initializing constructor
Num_Node::Num_Node (int num)
	: num_ (num)
{}

void Num_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Num_Node(*this);
}

//Returns the number
int Num_Node::eval (void)
{
	return this->num_;
}