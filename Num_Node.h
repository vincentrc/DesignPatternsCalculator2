// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef NUM_NODE_H_
#define NUM_NODE_H_

#include "Expr_Node.h"

class Expr_Node_Visitor;

class Num_Node : public Expr_Node 
{

public:

	Num_Node (int num);
	virtual void accept (Expr_Node_Visitor & v);
	virtual int eval (void);

protected:

	int num_;

}; 

#endif