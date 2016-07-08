/*
 * 4.cpp
 *
 *  Created on: Jul 7, 2016
 *      Author: tpl
 */
#include <math.h>
#include <assert.h>


//A palindromic number reads the same both ways.
//The largest palindrome made from the product of two 2-digit numbers is
//9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.

int count_digits(int n) {
	assert(n>0);
	int exp = 0;
	while ((n*10)/10!=0){
		exp++;
		n=n/10;
	}
	return exp;
}

int flip_digits(int n){ // 301
	int ans = 0; //
	while ((n*10)/10!=0) {
		ans = ans*10; // 0
		ans = ans + (n%10); // 1
		n = n/10; // 30
	}
	return ans;
}

int largest_palindrome(int n) {
	int numDigits = count_digits(n);
	if (numDigits%2==0) {
		int left = n/((int) pow(10,numDigits/2));
		int right = n%((int) pow(10,numDigits/2));
		if (right > flip_digits(left) ) {
			return left*pow(10,numDigits/2) + flip_digits(left);
		}
		else {
			return (left - 1)*pow(10,numDigits/2) + flip_digits(left-1);
		}
	}
	else {
		int midDigit = (n/((int) pow(10,numDigits/2))) % 10;

		int left = n/((int) pow(10,numDigits/2) + 1);
		int right = n%((int) pow(10,numDigits/2) +1 );

		if (right > flip_digits(left) ) {
			int output = (int) midDigit*pow(10,numDigits/2) + flip_digits(left);
			output += (int) left*pow(10,numDigits/2 +1);
			return output;
		}
		else {
			int output = (int) (midDigit - 1)*pow(10,numDigits/2) + flip_digits(left);
			output += (int) left*pow(10,numDigits/2 +1);
			return output;
		}
	}
}


int problem4() {
	// METHOD 1
	// find the minimum product of three digit number (MAX)
	// find the maximum product of three digit number (MIN)
	// find a largest palindromes in between MIN and MAX
	// verify that it is a product of three digit number

	// METHOD 2
	// breadth first tree search
	// i : level of tree
	// j : breadth of tree
	for (int i=0; i<999; i++){
		for (int j=0; j<i/2; j++){
			int product = (999-i+j)*(999-j);
			if (product == flip_digits(product)) {
				return product;
			}
		}
	}
	return -1;
}

