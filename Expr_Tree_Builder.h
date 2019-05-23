// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef EXPR_TREE_BUILDER_H_
#define EXPR_TREE_BUILDER_H_

#include "Expr_Builder.h"
#include "Stack.h"

class Expr_Tree_Builder : Expr_Builder
{
public:

	Expr_Tree_Builder();

	//Method to get the size of the treestack
	int stacksize();

	//Returns the root node
	std::shared_ptr<Expr_Node> get_tree();

	//Methods for building the expression.
	virtual void build_number (int n);
	virtual void build_add_operator (void);
	virtual void build_subtract_operator (void);
	virtual void build_multiply_operator (void);
	virtual bool build_divide_operator (void);
	virtual bool build_modulus_operator (void);


private:
	std::shared_ptr<Expr_Node> tree;				//Root node of expression tree
	Stack <std::shared_ptr<Expr_Node>> treestack;	//For numbers and "filled" operators
};

#endif