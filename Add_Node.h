// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef ADD_NODE_H_
#define ADD_NODE_H_

#include "Binary_Expr_Node.h"

class Add_Node : public Binary_Expr_Node
{
public:

	Add_Node (std::shared_ptr <Expr_Node> num1, std::shared_ptr <Expr_Node> num2);
	virtual void accept (Expr_Node_Visitor & v);
	int eval (void);
};

#endif