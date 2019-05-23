// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <iostream>
#include "Binary_Expr_Node.h"


//Initializing constructor
Binary_Expr_Node::Binary_Expr_Node (std::shared_ptr <Expr_Node> num1, std::shared_ptr <Expr_Node> num2)
	: right_ (num1),
	left_ (num2)
{}


//Getters/setters

std::shared_ptr <Expr_Node> Binary_Expr_Node::getright()
{
	return this->right_;
}

std::shared_ptr <Expr_Node> Binary_Expr_Node::getleft()
{
	return this->left_;
}

void Binary_Expr_Node::setright(std::shared_ptr <Expr_Node> in)
{
	this->right_ = in;
}

void Binary_Expr_Node::setleft(std::shared_ptr <Expr_Node> in)
{
	this->left_ = in;
}