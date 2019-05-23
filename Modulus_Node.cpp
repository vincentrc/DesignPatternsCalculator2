// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Modulus_Node.h"
#include "Expr_Node_Visitor.h"

//Initializing Constructor
Modulus_Node::Modulus_Node (std::shared_ptr <Expr_Node> num1, std::shared_ptr <Expr_Node> num2)
	: Binary_Expr_Node (num1, num2)
{}

//Calls visit on this node
void Modulus_Node::accept (Expr_Node_Visitor & v)
{
	v.Visit_Modulus_Node(*this);
}

//Returns the modulus of the children
int Modulus_Node::eval(void)
{
	return this->right_->eval() % this->left_->eval();
}