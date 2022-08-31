// =================================================================
//
// File: activity.h
// Author: Santiago Rodriguez Murialdo
// Date: 8/25/2022
//
// =================================================================
#ifndef ACTIVITY_H
#define ACTIVITY_H

// =================================================================
// sumaIterativa. Calculate the sum from 1 to n with an iterative
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(n)
// =================================================================

unsigned int sumaIterativa(unsigned int n) {
	int suma = 0;
	for (int i=0; i<n+1; i++)
		suma += i;

	return suma;
}

// =================================================================
// sumaRecursiva. Calculate the sum from 1 to n with an recursive
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(n)
// =================================================================

unsigned int sumaRecursiva(unsigned int n) {
	if (n==0)
		return 0;
	else
		return n + sumaRecursiva(n+1);
}

// =================================================================
// sumaDirecta. Calculate the sum from 1 to n with a mathematical
// method.
//
// @param n	The maximum limit of the sum.
// @return	The result of the addition from 1 to n.
// @Complexity	O(1)
// =================================================================
unsigned int sumaDirecta(unsigned int n) {
	int suma = 0;
	suma = (n*(n+1)/2);
	return suma;
}

#endif /* ACTIVITY_H */
