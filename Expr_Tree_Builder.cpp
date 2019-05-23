// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <string>
#include <iostream>
#include "Expr_Tree_Builder.h"
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Num_Node.h"

Expr_Tree_Builder::Expr_Tree_Builder()
{}

//Method to get the size of the treestack
int Expr_Tree_Builder::stacksize()
{
	return this->treestack.size();
}

//Instantiates number node and adds to tree
void Expr_Tree_Builder::build_number(int n)
{	
	std::shared_ptr<Expr_Node> temp (new Num_Node(n));
	this->treestack.push(temp);
}

//Returns the root node
std::shared_ptr<Expr_Node> Expr_Tree_Builder::get_tree()
{
	if (this->treestack.is_empty())
		return nullptr;
	return this->treestack.top();
}

//Instantiates add node and adds to tree
void Expr_Tree_Builder::build_add_operator()
{	
	std::shared_ptr<Expr_Node> left, right;

	//Pop off stack for children
	right = this->treestack.pop();
	left = this->treestack.pop();

	//Create a new add node
	std::shared_ptr <Expr_Node> temp (new Add_Node(left, right));

	//Make temp new root node
	this->tree = temp;

	//Add to treestack
	this->treestack.push(temp);
}

//Instantiates subtract node and adds to tree
void Expr_Tree_Builder::build_subtract_operator()
{	
	std::shared_ptr<Expr_Node> left, right;

	//Pop off stack for children
	right = this->treestack.pop();
	left = this->treestack.pop();

	//Create a new subtract node
	std::shared_ptr <Expr_Node> temp (new Subtract_Node(left, right));

	//Make temp new root node
	this->tree = temp;

	//Add to treestack
	this->treestack.push(temp);
}

//Instantiates multiply node and adds to tree
void Expr_Tree_Builder::build_multiply_operator()
{	
	std::shared_ptr<Expr_Node> left, right;

	//Pop off stack for children
	right = this->treestack.pop();
	left = this->treestack.pop();

	//Create a new multiply node
	std::shared_ptr <Expr_Node> temp (new Multiply_Node(left, right));

	//Make temp new root node
	this->tree = temp;

	//Add to treestack
	this->treestack.push(temp);
}

//Instantiates divide node and adds to tree
bool Expr_Tree_Builder::build_divide_operator()
{	
	std::shared_ptr<Expr_Node> left, right;

	//Pop off stack for children
	right = this->treestack.pop();
	left = this->treestack.pop();

	//Check for divide by zero
	if (right->eval() == 0)
		return false;

	//Create a new divide node
	std::shared_ptr <Expr_Node> temp (new Divide_Node(left, right));

	//Make temp new root node
	this->tree = temp;

	//Add to treestack
	this->treestack.push(temp);

	return true;
}

//Instantiates modulus node and adds to tree
bool Expr_Tree_Builder::build_modulus_operator()
{	
	std::shared_ptr<Expr_Node> left, right;

	//Pop off stack for children
	right = this->treestack.pop();
	left = this->treestack.pop();

	//Check for divide by zero
	if (right->eval() == 0)
		return false;

	//Create a new add node
	std::shared_ptr <Expr_Node> temp (new Modulus_Node(left, right));

	//Make temp new root node
	this->tree = temp;

	//Add to treestack
	this->treestack.push(temp);

	return true;
}


