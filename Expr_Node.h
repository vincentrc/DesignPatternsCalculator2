// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef EXPR_NODE_H_
#define EXPR_NODE_H_

#include <memory>

class Expr_Node_Visitor;

class Expr_Node
{

public:

	virtual ~Expr_Node (void);

	// Used to traverse the tree
	virtual void accept (Expr_Node_Visitor & v)=0;
	virtual int eval (void) = 0; 
	

};

#endif