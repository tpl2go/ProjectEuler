/*
 * 10.cpp
 *
 *  Created on: Jul 9, 2016
 *      Author: tpl
 */
#include "solutions.h"
#include <vector>
using namespace std;
//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//Find the sum of all the primes below two million.

long problem10() {
	int endInt = 2000000;

	// initialize prime number store
	vector<int> primes;
	primes.push_back(2);

	// generate primes (sieve of Eratosthenes)
	bool sieve [endInt];

	// initialize sieve
	for (int i = 0; i < endInt; i=i+2) {
		sieve[i] = false;
	}
	for (int i = 1; i < endInt; i = i+2) {
		sieve[i] = true; // true means not a prime
	}

	// sieving
	for (int i = 2; i < endInt; i++) {
		if (!sieve[i]) {
			primes.push_back(i+1);
			for (int j=2*i+1; j<endInt; j = j + i + 1){
				sieve[j] = true;
			}
		}
	}

	// sum
	long total = 0;
	for (int i = 0; i<primes.size(); i++){
		total += primes[i];
	}
	return total;
}

