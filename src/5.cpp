/*
 * 5.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: tpl
 */
#include <iostream>
#include <vector>
#include "solutions.h"
#include <math.h>
#include <assert.h>
using namespace std;
//2520 is the smallest number that can be divided by each of the numbers
//from 1 to 10 without any remainder.
//What is the smallest positive number that is evenly divisible
//by all of the numbers from 1 to 20?

int problem5(){
	int n = 20;

	// generate primes
	vector<int> primes;
	primes.push_back(2);

	for (int i = 2; i < n; i++) {
		bool is_prime = true;
		for (unsigned int j = 0; j < primes.size(); j++) {
			if (i % primes[j] == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			primes.push_back(i);
		}
	}

	// find greatest exponents needed
	vector<int> exponents(primes.size(),0); // initialize a vector of 0
	for (int i=1; i<n+1; i++) {
		// find prime factors
		for (int j=0; j<primes.size(); j++) {
			int num = i;
			int exp = 0;
			while(num%primes[j]==0){
				exp++;
				num = num/primes[j];
			}
			// take the highest
			if (exp > exponents[j]) {
				exponents[j] = exp;
			}
		}
	}
	// generate product
	assert( primes.size() == exponents.size());
	int product = 1;
	for (int i=0; i<primes.size(); i++) {
		product = product * pow (primes[i], exponents[i]);
	}
	return product;
}
