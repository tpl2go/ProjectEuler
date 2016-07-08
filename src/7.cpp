/*
 * 7.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: tpl
 */
#include <vector>
#include <iostream>
#include "solutions.h"
using namespace std;

//
//By listing the first six prime numbers:
//2, 3, 5, 7, 11, and 13,
//we can see that the 6th prime is 13.
//
//What is the 10001st prime number?

int problem7(){

	// generate primes
	vector<int> primes;
	primes.push_back(2);

	int i = 2;
	int numPrime = 1;
	while (numPrime<10001){
		bool is_prime = true;
		for (unsigned int j = 0; j < primes.size(); j++) {
			if (i % primes[j] == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			primes.push_back(i);
			numPrime++;
		}
		i++;
	}
	return primes[10000];
}

