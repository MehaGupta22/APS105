/* Author: Meha Gupta 
 * Date: 25 January 2019
 * Lab2 Assignment: Simple program to calculate monthly payments and total cost by anylyzing user input data */

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    //Defining all required variables
    double purchasePrice, interestRatePercent, monthlyPayment, totalCost, interestRateMonthlyDec;
    int numMonths;
    
    //Asking user for input and reading and assigning all inputs to appropriate variables
	printf("Enter the purchase price of the item: ");
    scanf("%lf", &purchasePrice);
    printf("Enter the interest rate per year as a percentage: ");
    scanf("%lf", &interestRatePercent);
    printf("Enter the number of months for repayment: ");
    scanf("%d", &numMonths);
    
    //Computing required results
    interestRateMonthlyDec = interestRatePercent/1200;
    if(interestRateMonthlyDec == 0){ //Special case: when interest rate = 0
        monthlyPayment = purchasePrice/numMonths;
        totalCost = purchasePrice;
    } else {
        monthlyPayment = (interestRateMonthlyDec*purchasePrice)/(1 - (pow((1 + interestRateMonthlyDec),(-numMonths))));
        totalCost = monthlyPayment*numMonths;
    }
    
    //Printing output in desired format
    printf("The monthly payment is: %0.2lf\n", monthlyPayment);
    printf("The total cost of the purchase is: %0.2lf\n", totalCost);
    
	return 0;
}
