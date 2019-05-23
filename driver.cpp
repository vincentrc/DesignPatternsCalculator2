// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <iostream>
#include <memory>
#include <cstring>
#include "Add_Node.h"
#include "Subtract_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Num_Node.h"
#include "Expr_Node_Visitor.h"
#include "Calculator.h"

int main(int argc, char * argv[])
{
	std::string expression;
	std::shared_ptr<Expr_Node> tree;
	std::shared_ptr <Calculator> Calc (new Calculator());
	std::shared_ptr<Expr_Node_Visitor> Eval (new Expr_Node_Visitor());

	//Main program loop
	while(1)
	{
		//Take in a line from stdin
		std::getline(std::cin, expression);

		//Quit the program when the user enters QUIT
		if (expression == "QUIT")
			return 0;

		if (expression.empty())
			continue;
		
		//Check the expression for validity
		if (!Calc->check_parenthesis(expression))	//Parenthesis structure check
		{
			std::cout << "\n\nInvalid Expression!\n\n";
			continue;
		}

		if (!Calc->check_missing_operators(expression)) //Missing or back-to-back operators check
		{
			std::cout << "\n\nInvalid Expression!\n\n";
			continue;
		}

		//Prompt user to assign any variables in expression
		if (!Calc->set_variables(expression)) //Checks for invalid variable assinment
		{
			std::cout << "\n\nInvalid Variable!\n\n";
			continue;
		}

		//Run the infix to postfix director method
		if ((tree = Calc->parse_expr(expression, tree)) == nullptr)
		{
			std::cout << "\n\nInvalid Expression!\n\n";
			continue;
		}

		//Use the visitor to evaluate the expression tree
		tree->accept(*Eval);
		std::cout << "\n\nThe answer is: " << Eval->get_result() << "\n\n";

		fflush(stdin);

	}

}
