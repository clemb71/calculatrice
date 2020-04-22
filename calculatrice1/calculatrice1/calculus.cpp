
#define MATH_H_INCLUDED


#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <string>
#include <vector>
#include <regex>


double calculus()
{
	double resultat(0); // result of operation
	std::string operationType; // operation to be calculated
	double firstOperand, secondOperand; //operands for the calculation


	std::cout << "Enter operation to be solved" << std::endl; //Asks to enter the operation desired
	std::cin >> operationType;
	std::cin.ignore();


	std::regex operation("(\\d*\\.?\\d+)([\\+\\-\\/\\*])(\\d*\\.?\\d+)");
	std::smatch matches;

	if (std::regex_search(operationType, matches, operation)) 
	{
		firstOperand = std::stod(matches[1]);
		secondOperand = std::stod(matches[3]);
		std::string operatorType = matches[2];

		if (operatorType == "+")
		{
			resultat = firstOperand + secondOperand; // Does an addition
		}
		else if (operatorType == "-")
		{
			resultat = firstOperand - secondOperand; // Does a substraction
		}
		else if (operatorType == "*")
		{
			resultat = firstOperand * secondOperand; // Does a multiplication
		}
		else if (operatorType == "/")
		{
			resultat = firstOperand / secondOperand; // Does a division
		}
		else if (operatorType == "%")
		{
			resultat = int(firstOperand) % int(secondOperand); // Does a modulo with the closest rounded down integer
		}
		else
		{
			std::cout << "Incorrect operation type. Please try again" << std::endl;
		}
	}
	else
	{
		std::cout << "Incorrect operation type. Please try again" << std::endl;
	}
	return resultat;
}

