// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Expr_Node_Visitor.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Num_Node.h"

//Constructor
Expr_Node_Visitor::Expr_Node_Visitor()
{}

Expr_Node_Visitor::~Expr_Node_Visitor()
{}

//Visit addition node
void Expr_Node_Visitor::Visit_Add_Node (Add_Node & node)
{ 
	int leftresult;
	node.getleft()->accept(*this);
	leftresult = this->result;
	node.getright()->accept(*this);
	this->result += leftresult; //Add the results of the children
}

//Visit subtraction nore
void Expr_Node_Visitor::Visit_Subtract_Node (Subtract_Node & node)
{
	int leftresult;
	node.getleft()->accept(*this);
	leftresult = this->result;
	node.getright()->accept(*this);
	this->result -= leftresult; //Subtract the results of the children
}

//Visit multiplication node
void Expr_Node_Visitor::Visit_Multiply_Node (Multiply_Node & node)
{ 
	int leftresult;
	node.getleft()->accept(*this);
	leftresult = this->result;
	node.getright()->accept(*this);
	this->result *= leftresult; //Multiply the results of the children
}

//Visit division node
void Expr_Node_Visitor::Visit_Divide_Node (Divide_Node & node)
{ 
	int leftresult;
	node.getleft()->accept(*this);
	leftresult = this->result;
	node.getright()->accept(*this);
	this->result /= leftresult; //Divide the results of the children
}

//Visit modulus node
void Expr_Node_Visitor::Visit_Modulus_Node (Modulus_Node & node)
{ 
	int leftresult;
	node.getleft()->accept(*this);
	leftresult = this->result;
	node.getright()->accept(*this);
	this->result %= leftresult; //Modulus the results of the children
}

//Visit number node
void Expr_Node_Visitor::Visit_Num_Node (Num_Node & node)
{ 
	this->result = node.eval();
}

int Expr_Node_Visitor::get_result()
{
	return this->result;
}