#include <iostream>
#include "algorithms.h"
#include <chrono> //for track time
#include <cmath> //for pow() function
#include <fstream> //for file output
#include <iomanip> //for scientific notation


int main()
{
	int choice;
	int n;
	int result;

	// Menu for user selection
	while (true)
	{
		std::cout << "\n***************************************\n";
		std::cout << "1. Recursive Algorithm\n";
		std::cout << "2. Dynamic Programming Algorithm\n";
		std::cout << "3. Generate Spreadsheet for Test Values\n";
		std::cout << "4. Exit\n";
		std::cout << "\n***************************************\n";
		std::cout << "Please input your selection\n";
		std::cin >> choice;

		//exit condition
		if (choice == 4)
		{
			std::cout << "Exiting Program.\n";
			break;
		}

		//gets user input for n the calculates and prints fibb at n using recusive alg
		if (choice == 1)
		{
			//gets user input
			int n = 0;
			std::cout << " Please enter an integer for n: ";
			std::cin >> n;

			//calculate and print fibb(n) using recursive function
			int result = 0;
			result = recursive_Fib(n);
			std::cout << " Fibbonacci at " << n << " = " << result;

		}

		//gets user input for n the calculates and prints fibb at n using DP alg
		if (choice == 2)
		{
			//gets user input
			int n = 0;
			std::cout << " Please enter an integer for n: ";
			std::cin >> n;

			//calculate and print fibb(n) using DP function
			int result = 0;
			result = dp_Fib(n);
			std::cout << " Fibbonacci at " << n << " = " << result;

		}

		if (choice == 3)
		{
			//create spreadsheet
			std::ofstream fout("Fibonacci_Time.cvs");
			fout << "n,F(n),T_recursive(ns),T_DP(ns),(2^n)/n,T_recursive/T_DP\n";

			int test_values[] = { 10,12,15,20,23,25,30 };

			for (int val : test_values)
			{
				// Recursive Fibonacci timing
				auto start_recursive = std::chrono::high_resolution_clock::now();	//start clock
				int recursive_result = recursive_Fib(val);	// calculate Fibonacci using recursive algorithm
				auto stop_recursive = std::chrono::high_resolution_clock::now(); 	//end clock
				auto duration_recursive = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_recursive - start_recursive).count(); 	//calculate time


				// DP Fibonnaci timing
				auto start_dp = std::chrono::high_resolution_clock::now();	//start clock
				int dp_result = dp_Fib(val);	// calculate Fibonacci using recursive algorithm
				auto stop_dp = std::chrono::high_resolution_clock::now(); 	//end clock
				auto duration_dp = std::chrono::duration_cast<std::chrono::nanoseconds>(stop_dp - start_dp).count(); 	//calculate time

				// calculate (2^n)/n
				double num1 = (pow(2,val) / val);

				//calcuate recursive time / DP time
				double num2 = duration_recursive / duration_dp;

				//print results
				fout << val << ", " << dp_result << ", " << duration_recursive << ", " << duration_dp << ", ";
				
				fout << std::fixed << std::setprecision(2); //for scientific notation to 2 decimal places
				fout << num1 << ", " << num2 << "\n";


			}
		}

	}

}

