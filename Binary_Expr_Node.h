// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef BINARY_EXPR_NODE_H_
#define BINARY_EXPR_NODE_H_

#include "Expr_Node.h"


class Binary_Expr_Node : public Expr_Node 
{

public:

	Binary_Expr_Node (std::shared_ptr <Expr_Node> num1, std::shared_ptr <Expr_Node> num2);
	virtual int eval (void) = 0;

	//Getters/Setters
	std::shared_ptr <Expr_Node> getright();
	std::shared_ptr <Expr_Node> getleft();
	void setright(std::shared_ptr <Expr_Node> in);
	void setleft(std::shared_ptr <Expr_Node> in);


protected:

	std::shared_ptr <Expr_Node> right_;
	std::shared_ptr <Expr_Node> left_;

}; 

#endif
