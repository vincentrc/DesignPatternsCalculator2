// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef EXPR_NODE_VISITOR_H_
#define EXPR_NODE_VISITOR_H_

class Add_Node;
class Subtract_Node;
class Multiply_Node;
class Divide_Node;
class Modulus_Node;
class Num_Node;

class Expr_Node_Visitor
{
public:
	Expr_Node_Visitor (void);
	virtual ~Expr_Node_Visitor (void);

	//Methods for visiting concrete nodes
	virtual void Visit_Add_Node (Add_Node & node);
	virtual void Visit_Subtract_Node (Subtract_Node & node);
	virtual void Visit_Multiply_Node (Multiply_Node & node);
	virtual void Visit_Divide_Node (Divide_Node & node);
	virtual void Visit_Modulus_Node (Modulus_Node & node);
	virtual void Visit_Num_Node (Num_Node & node);

	int get_result (void);

private:
	//Stores the result of an evaluation
	int result;
};


#endif