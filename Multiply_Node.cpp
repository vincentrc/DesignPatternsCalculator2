// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Multiply_Node.h"
#include "Expr_Node_Visitor.h"

//Initializing Constructor
Multiply_Node::Multiply_Node (std::shared_ptr <Expr_Node> num1, std::shared_ptr <Expr_Node> num2)
	: Binary_Expr_Node (num1, num2)
{}

//Calls visit on this node
void Multiply_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Multiply_Node(*this);
}

//Returns the product of the children
int Multiply_Node::eval(void)
{
	return this->right_->eval() * this->left_->eval();
}