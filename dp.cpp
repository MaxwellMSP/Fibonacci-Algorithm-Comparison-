//file where the Dynamic Programming algorithm is created
#include "algorithms.h"

// Function for Dynamic Programming Fibonnaci
int dp_Fib(int num) {
	// Base cases
	// check if fibonacci number is at 0
	if (num == 0) {
		return 0;
	}

	//check if fibonacci number is at 1
	else if (num == 1) {
		return 1;
	}

	// Variables to store the recent Fibonnacci numbers
	int prev1 = 0, prev2 = 1, current = 0;

	// Loop from 2 up to num to build a sequence
	for (int i = 2; i <= num; i++) {
		current = prev1 + prev2;
		prev1 = prev2;
		prev2 = current;
	}

	return current;
}