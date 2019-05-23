// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Num_Node.h"
#include "Eval_Expr_Tree.h"



//Visit addition node
void Eval_Expr_Tree::Visit_Add_Node (const Add_Node & node)
{ 
	int leftresult;
	node.left_->accept(*this);
	leftresult = this->result;
	node.right_->accept(*this);
	this->result += leftresult; //Add the results of the children
}

//Visit subtraction nore
void Eval_Expr_Tree::Visit_Subtract_Node (const Subtract_Node & node)
{
	int leftresult;
	node.left_->accept(*this);
	leftresult = this->result;
	node.right_->accept(*this);
	this->result -= leftresult; //Subtract the results of the children
}

//Visit multiplication node
void Eval_Expr_Tree::Visit_Multiply_Node (const Multiply_Node & node)
{ 
	int leftresult;
	node.left_->accept(*this);
	leftresult = this->result;
	node.right_->accept(*this);
	this->result *= leftresult; //Multiply the results of the children
}

//Visit division node
void Eval_Expr_Tree::Visit_Divide_Node (const Divide_Node & node)
{ 
	int leftresult;
	node.left_->accept(*this);
	leftresult = this->result;
	node.right_->accept(*this);
	this->result /= leftresult; //Divide the results of the children
}

//Visit modulus node
void Eval_Expr_Tree::Visit_Modulus_Node (const Modulus_Node & node)
{ 
	int leftresult;
	node.left_->accept(*this);
	leftresult = this->result;
	node.right_->accept(*this);
	this->result %= leftresult; //Modulus the results of the children
}

//Visit number node
void Eval_Expr_Tree::Visit_Num_Node (Num_Node & node)
{ 
	this->result = node.eval();
}