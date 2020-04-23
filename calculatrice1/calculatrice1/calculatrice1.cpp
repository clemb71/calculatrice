// calculatrice.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* Objectif: 1) Etre capable d'écrire une opération complexe à plusieurs chiffres et obtenir un résultat {ex: (a+b)*c/d }
				a) pour cela le code parcourera l'opération, isolera les opérateurs et les stockeras dans une matrice
				b) Pour chaque indexe dans le matrice effectuer l'opération demandé et mettre à jour le résultat
			 2) La calculatrice devra être capable de faire des opérations complexes comme intégration et dérivation
			 3) créer un interface graphique
			*/


#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <vector>
#include "calculus.h"

using namespace std;

int main()
{
	double firstOperand, secondOperand; //Variables
	double resultat(0);
	char operationType;
	string userChoice;

	/*cout << "Warning! modulo operation takes operands closest interger rounded down. Make sure you have the integers you want for the operation" << endl;
	cout << "Choose your operation: calculus, sinus, cosinus,tangent, square root, exponential, neperian logarithm, base ten logarithm, absolute," << endl;
	cin >> userChoice;*/

	//if (userChoice == "calculus")
	{
		resultat = GiveResultToDesiredOperation();
	}

	//if (userChoice == "sinus")
	//{
	//	cout << "Sinus Operand :" << endl; //Asks to enter the first number of the operation
	//	cin >> firstOperand;
	//	cin.ignore();

	//	resultat = sin(firstOperand*M_PI/180);
	//}

	std::cout << "resultat :" << resultat << endl; //prints the operation result
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
