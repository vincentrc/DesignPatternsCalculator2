// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef EXPR_BUILDER_H_
#define EXPR_BUILDER_H_

#include "Expr_Node.h"
#include <memory>

class Expr_Builder
{
public:

	//Methods for building the expression
	virtual void build_number (int n) = 0;
	virtual void build_add_operator (void) = 0;
	virtual void build_subtract_operator (void) = 0;
	virtual void build_multiply_operator (void) = 0;
	virtual bool build_divide_operator (void) = 0;
	virtual bool build_modulus_operator (void) = 0;

};

#endif