// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef EVAL_EXPR_TREE_H_
#define EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"

class Eval_Expr_Tree : public Expr_Node_Visitor
{
public:
	Eval_Expr_Tree (void);
	virtual ~Eval_Expr_Tree (void);

	//Methods for visiting concrete nodes
	virtual void Visit_Add_Node (const Add_Node & node);
	virtual void Visit_Subtract_Node (const Subtract_Node & node);
	virtual void Visit_Multiply_Node (const Multiply_Node & node);
	virtual void Visit_Divide_Node (const Divide_Node & node);
	virtual void Visit_Modulus_Node (const Modulus_Node & node);
	virtual void Visit_Num_Node (Num_Node & node);

	int get_result (void) const;

private:
	//Stores the result of an evaluation
	int result;
};


#endif