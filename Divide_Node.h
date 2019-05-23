// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef DIVIDE_NODE_H_
#define DIVIDE_NODE_H_

#include "Binary_Expr_Node.h"

class Expr_Node_Visitor;

class Divide_Node : public Binary_Expr_Node
{
public:

	Divide_Node (std::shared_ptr <Expr_Node> num1, std::shared_ptr <Expr_Node> num2);
	virtual void accept (Expr_Node_Visitor & v);
	virtual int eval (void);
};

#endif