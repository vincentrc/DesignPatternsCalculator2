// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Calculator.h"
#include <sstream>
#include <string>
#include <iostream>
#include <exception>

//Constructor
Calculator::Calculator()
{}

//Detects variables and prompts user to assign values
bool Calculator::set_variables(std::string & infix)
{
	std::istringstream input(infix);
	std::string token, instring;
	std::map <char, int>::iterator iter;
	char temp;
	int num;

	//Clears map of old variables
	this->map.clear();

	//Iterate through tokens looking for variables
	while(!input.eof())
	{
		input >> token;

		//Convert to char if possible
		if (token.length() == 1)
			temp = token.c_str()[0];
		else 
			continue;

		//If token is a variable
		if ( (temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') )
		{
			//Add the variable to the map
			this->map[temp];
		}

	}

	//Iterate thorugh map and assign values to variables
	for (iter=this->map.begin();iter!=this->map.end();iter++)
	{
		std::cout << "\nEnter value for " << iter->first << ":\n";

		std::cin >> instring;

		try	//Check if input is an integer
		{
			num = stoi(instring);
		}
		//If an exception was thrown, either wasn't an integer or out of range
		catch (std::exception& e)
		{
			return false;
		}

		iter->second = num;
	}

	return true;
}

//Checks to make sure parenthesis structure is correct
bool Calculator::check_parenthesis(const std::string & infix)
{
	std::istringstream input(infix);	//Create an input stream parser
	std::string token;					//Current token in string stream
	Stack <std::string> temp;			//Stack for storing parenthesis


	while(!input.eof())
	{
		input >> token;

		//Push all "("
		if (token == "(")
			temp.push(token);

		//For ")", check for matching "("
		else if (token == ")")
		{
			//If no parenthesis in stack, then must be invalid
			if (temp.is_empty())
				return false;

			//If there are, pop one to match the current ")"
			else
				temp.pop();
		}
	}

	//If the stack is empty, all parenthesis have a match, otherwise there was some error
	if (temp.is_empty())
		return true;
	else
		return false;
}

//Checks to make sure there a no missing operators (two nums in a row: "4 4 - 6 + 8" for example) or two+ operators in a row
bool Calculator::check_missing_operators(const std::string & infix)
{
	int prevop = -1;					//Variable to tell if prev token was an operator/parenthesis: 3 = left parenthesis 2 = right parenthesis 1 = operator 0 = operand
	std::istringstream input(infix);	//Create an input stream parser
	std::string token;					//Current token in string stream
	Stack <std::string> temp;			//Stack for storing parenthesis
	int numcount = 0, opcount = 0;		//Counts to make sure at least 2 numbers/operands and 1 operator
	int first = 1;

	while(!input.eof())
	{
		input >> token;

		//If token is an operator
		if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
		{
			//First token is operator
			if (first == 1)
				return false;

			//Two operators in a row or last token was left parenthesis
			if (prevop == 1 || prevop == 3)
				return false;

			prevop = 1;
			opcount++;
		}

		//If token is a left parenthesis
		else if (token == "(")
		{
			//Check if last token was an operand
			if (prevop == 0)
				return false;

			prevop = 3;
		}

		//If token is a right parenthesis
		else if  (token == ")")
		{
			//Check if last token was an operand
			if (prevop == 1)
				return false;

			prevop = 2;
		}

		//Otherwise assume it's an operand/number (not a number error handling is in conversion formula)
		else
		{
			//Missing operator
			if (prevop == 0)
				return false;

			prevop = 0;
			numcount++;
		}

		first = 0;
	}

	//Check operator and operand counters and make sure last token wasn't operator
	if ((numcount < 2 && opcount > 0) || (opcount < 1 && numcount > 1) || prevop == 1)
		return false;

	return true;
}

//Returns the precedence of the given operator or -1 in invalid op
int Calculator::get_precedence(std::string op)
{
	int num;

	if (op == "+" || op == "-")
		return 1;

	else if (op == "*" || op == "/" || op == "%")
		return 2;

	else if (op == "(" || op == ")")
		return 3;

	else	//Invalid
	{
		try	//Try converting the token to an integer
		{
			num = stoi(op);
		}
		//If an exception was thrown, either wasn't a num or out of range
		catch (std::exception& e)
		{
			return -1;
		}

		return 0;
	}
}

//Method to add an operator to the tree by calling builder
bool Calculator::add_tree(std::shared_ptr <Expr_Tree_Builder> builder, std::string op)
{
	std::shared_ptr<Expr_Node> temp, left, right;

	//If the stack for some reason doesn't have two elements
	if (builder->stacksize() < 2)
		return false;


	if (op == "+")
		builder->build_add_operator();
	else if (op == "-")
		builder->build_subtract_operator();
	else if (op == "*")
		builder->build_multiply_operator();
	else if (op == "/")
	{
		if (!builder->build_divide_operator()) //Checks for divide by zero
			return false;
	}
	else if (op == "%")
	{
		if(!builder->build_modulus_operator()) //Checks for mod 0
			return false;
	}
	else
		return false;

	return true;

}

//Parses the infix expression and directs builder to build postfix tree
std::shared_ptr<Expr_Node> Calculator::parse_expr(const std::string & infix, std::shared_ptr<Expr_Node> tree)
{
	std::istringstream input (infix);
	std::string token, temp;
	char chartemp;
	std::shared_ptr <Expr_Tree_Builder> builder (new Expr_Tree_Builder());
	Stack <std::string> opstack = Stack <std::string> ();
	int prec;

	//Iterate through entire expression
	while (!input.eof())
	{
		input >> token;

		//Check for variable
		//Convert to char if possible
		if (token.length() == 1)
		{
			chartemp = token.c_str()[0];

			//If token is a variable, replace token with string of its value
			if ( (chartemp >= 'a' && chartemp <= 'z') || (chartemp >= 'A' && chartemp <= 'Z') )
			{
				token = std::to_string((long long)this->map[chartemp]);
			}

		}
		       
		//Evaluate the token 
		if ((prec = this->get_precedence(token)) == -1)
			return nullptr;

		else if (token == ")")
		{
			//Pop off stack until matching open parenthesis found
			while(1)
			{
				//Check for invalid expression structure
				if (opstack.is_empty())
					return nullptr;

				temp = opstack.pop();
				
				//If matching parenthesis found
				if (temp == "(")
					break;

				//Add to expression tree
				if (!this->add_tree(builder, temp))
					return nullptr;
			}
		}

		//Number
		else if (prec == 0)
		{
			builder->build_number(stoi(token)); //stoi was already checked for errors
		}

		//operators and open parenthesis
		else
		{
			//Iterate until token is highest precedence 
			while(1)
			{
				//If stack is empty
				if (opstack.is_empty())
				{
					opstack.push(token);
					break;
				}

				//If token is higher precedence than top
				if ( (this->get_precedence(opstack.top()) < prec) || (opstack.top() == "("))
				{
					opstack.push(token);
					break;
				}

				//Pop off stack and call builder
				temp = opstack.pop();
				if (!this->add_tree(builder, temp))
					return nullptr;
			}
		}
	}

	//Finish building tree by popping off stack until empty
	while(!opstack.is_empty())
	{
		temp = opstack.pop();
		if (!this->add_tree(builder, temp))
			return nullptr;
	}

	//Assign tree variable to root node
	tree = builder->get_tree();
	return tree;
}