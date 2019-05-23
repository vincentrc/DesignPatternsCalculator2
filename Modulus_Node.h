// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef MODULUS_NODE_H_
#define MODULUS_NODE_H_

#include "Binary_Expr_Node.h"

class Expr_Node_Visitor;

class Modulus_Node : public Binary_Expr_Node
{
public:

	Modulus_Node (std::shared_ptr <Expr_Node> num1, std::shared_ptr <Expr_Node> num2);
	virtual void accept (Expr_Node_Visitor & v);
	virtual int eval (void);
};

#endif