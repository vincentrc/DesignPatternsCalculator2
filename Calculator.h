// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
#include <map>
#include "Stack.h"
#include "Expr_Tree_Builder.h"

class Calculator 
{
public:

	Calculator();
	
	//Detects variables and prompts user to assign values
	bool set_variables(std::string & infix);

	//Makes sure parentheis strucutre is correct
	bool check_parenthesis(const std::string & infix);

	//Checks to make sure there a no missing operators (two nums in a row: "4 4 - 6 + 8" for example) or two+ operators in a row
	bool check_missing_operators(const std::string & infix);

	//Method for determining the precedence of an operator
	int get_precedence(std::string op);

	//Method to add an operator to the tree by calling builder
	bool add_tree(std::shared_ptr <Expr_Tree_Builder> builder, std::string op);
	
	//Direct builder to make tree based on infix string
	std::shared_ptr<Expr_Node> parse_expr (const std::string & infix, std::shared_ptr<Expr_Node> tree);

private:
	std::map <char, int> map;	//Stores variable values

};

#endif