/*
 * 6.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: tpl
 */
#include "solutions.h"
//The sum of the squares of the first ten natural numbers is,
//12 + 22 + ... + 102 = 385
//
//The square of the sum of the first ten natural numbers is,
//(1 + 2 + ... + 10)2 = 552 = 3025
//
//Hence the difference between the sum of the squares of the
//first ten natural numbers and the square of the sum is
//3025 − 385 = 2640.
//
//Find the difference between the sum of the squares of the
//first one hundred natural numbers and the square of the sum.

long sum_of_square(int n) {
	long ans = 0;
	for (int i=1; i<n+1; i++) {
		ans += i*i;
	}
	return ans;
}

long square_of_sum(int n) {
	long sum = 0;
	for (int i=1; i<n+1; i++) {
		sum += i;
	}
	return sum*sum;
}

int problem6(){
	int n = 100;

	return (int) square_of_sum(n) - sum_of_square(n);
}
