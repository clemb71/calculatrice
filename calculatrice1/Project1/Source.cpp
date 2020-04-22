#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <typeinfo>
#include <cmath>
#include <math.h>

using namespace std;


void echange(double& a, double& b)
{
	double temporaire(a); //On sauvegarde la valeur de 'a'
	a = b;                //On remplace la valeur de 'a' par celle de 'b'
	b = temporaire;       //Et on utilise la valeur sauvegardée pour mettre l'ancienne valeur de 'a' dans 'b'
}

int main()
{
	double a(1.2), b(4.5);

	cout << "a vaut " << a << " et b vaut " << b << endl;

	echange(a, b);   //On utilise la fonction

	cout << "a vaut " << a << " et b vaut " << b << endl;
	return 0;
}