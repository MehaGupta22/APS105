/* Author: Meha Gupta
 * Date: 20 January 2019
 * Lab1 Assignment: This program takes in two positive integers and returns their product, difference (first - second) 
 * and sum of their square roots, always assuming valid input */

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    //Defining all required variables
    int num1, num2;
    double product, difference, sumSquareRoots; 
    
    printf("Enter two positive integers: "); //Asking user for input
    scanf("%d %d", &num1, &num2); //Reads user input and assigns them to appropriate variables
    
    //Computing required results
    product = num1*num2;
    difference = num1 - num2;
    sumSquareRoots = sqrt(num1) + sqrt(num2);
    
    //Printing output result in required format
    printf("The product is: %0.2lf, the difference is: %0.2lf and the sum of roots is: %0.2lf\n", product, difference, sumSquareRoots); 
	
    return 0;
}
