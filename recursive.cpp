//file where the recursive algorithm is created
#include "algorithms.h"
//function to calculate fibonacci using recursion 
int recursive_Fib(int num) {

	//check if fibonacci number is at 0
	if (num == 0) {
		return 0;
	}

	//check if fibonacci number is at 1
	else if (num == 1) {
		return 1;
	}

	//recursive case 
	else {
		return (recursive_Fib(num - 1) + recursive_Fib(num - 2));
	}

}