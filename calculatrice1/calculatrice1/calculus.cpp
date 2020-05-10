
#define MATH_H_INCLUDED


#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <string>
#include <vector>
#include <regex>
#include "calculus.h"


double Calculate(std::smatch matches)
{
	double firstOperand = std::stod(matches[1]);
	double secondOperand = std::stod(matches[3]);
	std::string operation = matches[2];

	if (operation == "+")
	{
		return firstOperand + secondOperand; // Does an addition
	}
	else if (operation == "-")
	{
		return firstOperand - secondOperand; // Does a substraction
	}
	else if (operation == "*")
	{
		return firstOperand * secondOperand; // Does a multiplication
	}
	else if (operation == "/")
	{
		return firstOperand / secondOperand; // Does a division
	}
	else if (operation == "%")
	{
		return int(firstOperand) % int(secondOperand); // Does a modulo with the closest rounded down integer
	}
}

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
	std::regex sousOperation("[\\(]([^\\(\\)]*)[\\)]");
	std::smatch matches;
	double resultat = 0;



	if (std::regex_search(operation, matches, sousOperation))
	{
		resultat = PriorityOp(matches.prefix().str() + std::to_string(PriorityOp(matches[1])) + matches.suffix().str());

	}
	else
	{
		double firstOperand, secondOperand; //operands for the calculation

		std::regex operationPrio1Regex("(\\d*\\.?\\d+)([\\/\\*])(\\d*\\.?\\d+)");
		std::regex operationPrio2Regex("(\\d*\\.?\\d+)([\\+\\-])(\\d*\\.?\\d+)");
		std::regex endOfOperationRegex("^(\\d*\\.?\\d*)$");


		if (std::regex_search(operation, matches, operationPrio1Regex))
		{
			resultat = Calculate(matches);
		}
		else if (std::regex_search(operation, matches, operationPrio2Regex))
		{
			resultat = Calculate(matches);
		}
		else if (std::regex_search(operation, matches, endOfOperationRegex))
		{
			return std::stod(matches[1]);
		}
		else
		{
			std::cout << "Incorrect operation type. Please try again" << std::endl;
		}
		std::string newOp = matches.prefix().str() + std::to_string(resultat) + matches.suffix().str();
		resultat = PriorityOp(newOp);
		return resultat;

	}

		return resultat;
}

double GiveResultToDesiredOperation()
{
	std::string desiredSousOperation = AskToWriteOperation();
	double result = PriorityOp(desiredSousOperation);

	return result;
}