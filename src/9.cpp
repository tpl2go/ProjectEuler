/*
 * 9.cpp
 *
 *  Created on: Jul 8, 2016
 *      Author: tpl
 */
#include "solutions.h"
#include <iostream>
using namespace std;
//
//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//a2 + b2 = c2
//
//For example, 32 + 42 = 9 + 16 = 25 = 52.
//
//There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//Find the product abc.

int problem9(){
	// 3D search
	int sum = 1000;
	for (int i=1; i<sum/2; i++) {
		for (int j=1; j<(sum-i)/2; j++) {
			// i and j cannot be larger than k.
			int k = sum - i - j;
			if (i*i + j*j == k*k) {
				cout << "a,b,c are: " << i << ", " << j << ", " << k << endl;
				return i*j*k;
			}
		}
	}
	return -1; // error
}
