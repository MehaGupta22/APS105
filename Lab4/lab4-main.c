/* Author: Meha Gupta
 * Date: 05 February 2019
 * Lab4 Assignment: Finding the area under the graph using Riemann Sums */
 
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//Declaration of functions and global variables. Functions are defined at the end//
double evalFunc(double x);
void validateInputs(double a, double b, int n);
double leftBound, rightBound, x, stepSize, leftArea, rightArea, midArea, height;
int numRectangles;

int main(int argc, char **argv) {
    
    //Asking user for information and assigning entered values to appropriate variables.
    printf ("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use. To exit enter 0 0 0\n");
    scanf ("%lf%lf%d", &leftBound, &rightBound, &numRectangles);
    
    //Providing exit or quit option
    if (leftBound == 0 && rightBound == 0 && numRectangles == 0) {
        printf("Invalid Inputs...\n");
        printf("Terminating main!\n");
        return 0;
    }
    
    //Using "validateInput" function to check the validity of the inputs
    validateInputs(leftBound, rightBound, numRectangles); 
    
    stepSize = (rightBound - leftBound)/numRectangles;

    //Using "for" loops for repetitive summation
    leftArea = 0;
    for (x = leftBound; x <= (rightBound - (stepSize/2)); x = x + stepSize) {
        leftArea = leftArea + ((evalFunc(x))*stepSize); //Using "evalFunc" function to find the height of the specific rectangles
    };
    
    rightArea = 0;
    for (x = (leftBound + stepSize); x <= (rightBound + (stepSize/2)); x = x + stepSize) {
        rightArea = rightArea + ((evalFunc(x))*stepSize); 
    };
    
    midArea = 0;
    for (x = (leftBound + (stepSize/2)); x <= rightBound; x = x + stepSize) {
        midArea = midArea + ((evalFunc(x))*stepSize); 
    };
    
    //Printing required outputs
    printf("With Step Size: %0.4lf\n", stepSize);
    printf("The approximate integral of the f(x) = 2(x^2)-7x-2\n");
    printf("Bound between %0.2lf and %0.2lf, using %d rectangles is as follows\n\n", leftBound, rightBound, numRectangles);
    printf("Mid point evaluation approximate: %0.4lf\n", midArea);
    printf("Left point evaluation approximate: %0.4lf\n", leftArea);
    printf("Right point evaluation approximate: %0.4lf\n", rightArea);
    
    return 0;
}


//Defining required functions
//validateInputs checks user input validity and asks for new inputs if invalid
void validateInputs(double a,double b,int n) {
        while (leftBound <= -10 || rightBound >= 10 || rightBound<leftBound || numRectangles<=0) {
        printf("Invalid Inputs...\n\n");
        printf ("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use. To exit enter 0 0 0\n");
        scanf("%lf%lf%d", &leftBound, &rightBound, &numRectangles);
        }
}

//evalFunc assists in Reimann Sum calculation by finding the height of specific rectangles
double evalFunc(double x) {
    return (2*x*x) - (7*x) - 2;
}

