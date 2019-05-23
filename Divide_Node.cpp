// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Divide_Node.h"
#include "Expr_Node_Visitor.h"

//Initializing Constructor
Divide_Node::Divide_Node (std::shared_ptr <Expr_Node> num1, std::shared_ptr <Expr_Node> num2)
	: Binary_Expr_Node (num1, num2)
{}

//Calls visit on this node
void Divide_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Divide_Node(*this);
}

//Returns the quotient of the children
int Divide_Node::eval(void)
{
	return this->right_->eval() / this->left_->eval();
}