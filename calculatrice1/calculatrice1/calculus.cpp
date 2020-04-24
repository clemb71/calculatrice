
#define MATH_H_INCLUDED


#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <string>
#include <vector>
#include <regex>
#include "calculus.h"

std::string AskToWriteOperation()
{
	std::string operation; // operation to be calculated

	std::cout << "Enter operation to be solved" << std::endl; //Asks to enter the operation desired
	std::cin >> operation;
	std::cin.ignore();

	return operation;
}

double PriorityOp(std::string operation)
{
	std::regex sousOperation("[\\(](.*)[\\)]");
	std::smatch matches;
	double resultat =0;
	

	if (std::regex_search(operation, matches, sousOperation))
	{
		resultat = PriorityOp(matches[1]) ;
	}
	else
	{
		double firstOperand, secondOperand; //operands for the calculation
		
		std::regex operationRegex("(\\d*\\.?\\d+)([\\+\\-\\/\\*])(\\d*\\.?\\d+)");
		std::regex endOfOperationRegex("^(\\d*\\.?\\d*)$");

		if (std::regex_search(operation, matches, operationRegex))
		{
			firstOperand = std::stod(matches[1]);
			secondOperand = std::stod(matches[3]);
			std::string operation = matches[2];
			
			if (operation == "+")
			{
				resultat = firstOperand + secondOperand; // Does an addition
			}
			else if (operation == "-")
			{
				resultat = firstOperand - secondOperand; // Does a substraction
			}
			else if (operation == "*")
			{
				resultat = firstOperand * secondOperand; // Does a multiplication
			}
			else if (operation == "/")
			{
				resultat = firstOperand / secondOperand; // Does a division
			}
			else if (operation == "%")
			{
				resultat = int(firstOperand) % int(secondOperand); // Does a modulo with the closest rounded down integer
			}
			else
			{
				std::cout << "Incorrect operation type. Please try again" << std::endl;
			}
			std::string newOp = std::to_string(resultat) + matches.suffix().str();
			resultat = PriorityOp(newOp);
			return resultat;
			
		}
		else if(std::regex_search(operation, matches, endOfOperationRegex))
		{
			return std::stod(matches[1]);
		}
		else
		{
			std::cout << "Incorrect operation type. Please try again" << std::endl;
		}
	
	}
	return resultat;
}

double GiveResultToDesiredOperation()
{
	std::string desiredSousOperation = AskToWriteOperation();
	double result = PriorityOp(desiredSousOperation);

	return result;
}