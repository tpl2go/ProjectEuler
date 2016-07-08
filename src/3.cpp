/*
 * 3.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: tpl
 */
#include "solutions.h"
#include <math.h>
#include <vector>
using namespace std;

//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?
int problem3() {
	long bignum = 600851475143;
	long endInt = (long) sqrt(bignum) + 1;


	vector<int> primes;
	primes.push_back(2);

	// generate primes
	for (int i = 2; i < endInt; i++) {
		bool is_prime = true;
		for (int j = 0; j < primes.size(); j++) {
			if (i % primes[j] == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			primes.push_back(i);
		}
	}

	// test factors
	int largestP = 1;
	for (int i = 0; i < primes.size(); i++) {
		if (bignum % primes[i] == 0){
			largestP = primes[i];
		}
	}
	return largestP;
}

