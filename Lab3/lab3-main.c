/* Author: Meha Gupta 
 * Date: 01 February 2019
 * Lab3 Assignment: Simple program for a specific "loyal customer" service offered by some coffeehouse (with input validity check) */

#include <stdio.h>

int main(int argc, char **argv)
{
    //Defining all required variables
	double budget, coffeePrice, avgPrice, moneyRemaining;
    int numReqCoupon, numPurchasedCoffee, numCoupon, numRemainingCoupon, numFreeCoffee;
    
    //Asking for user input and reading and assigning them to appropriate variables
    printf("How much does the coffee cost?\n");
    scanf("%lf",&coffeePrice);
    printf("How many coupons does it taketo get a free coffee?\n");
    scanf("%d",&numReqCoupon);
    printf("How much money do you have to spend on coffee this month?\n");
    scanf("%lf",&budget);
    
    //Checking for valid inputs and performing required calculations if all inputs are valid
    //Program crashes if invalid input
    if(coffeePrice >= 0.01){
        if(numReqCoupon >= 1){
            if(budget >= 0.00){
                numFreeCoffee = 0; //Initializing variable for proper implementation within while loop
                numPurchasedCoffee = (int)(budget/coffeePrice);
                numCoupon = numPurchasedCoffee;

                while(numCoupon >= numReqCoupon){
                    numFreeCoffee = numFreeCoffee + (int)(numCoupon/numReqCoupon);
                    numCoupon = (numCoupon - (numFreeCoffee*numReqCoupon)) + numFreeCoffee;
                }
                
                avgPrice = (numFreeCoffee + numPurchasedCoffee)/(numPurchasedCoffee*coffeePrice);
                moneyRemaining = budget - (numPurchasedCoffee*coffeePrice);
                numRemainingCoupon = numCoupon;
            }
            else { 
                printf("Invalid Input\n");
                return 0;
            }
        }
        else {
            printf("Invalid Input\n");
            return 0;
        }
    }
    else {
        printf("Invalid Input");
        return 0;
    }
    
    //Printing output results in required format
    if(numFreeCoffee != 0){
        printf("This month, you can purchase %d coffees at $%0.2lf.\n", numPurchasedCoffee, coffeePrice);
        printf("You will be able to redeem an additional %d free coffees from coupons.\n", numFreeCoffee);
        printf("At the end of the month, you will have $%0.2lf and %d coupon(s) remaining.\n", moneyRemaining, numRemainingCoupon);
        printf("On average, you spent $%0.2lf on each cup of coffee this month.\n", avgPrice);
    }
    else {
        printf("This month, you can purchase %d coffees at $%0.2lf.\n",numPurchasedCoffee, coffeePrice);
        printf("You will not be able to redeem any free coffees this month.\n");
        printf("At the end of the month, you will have $%0.2lf and %d coupon(s) remaining.\n",moneyRemaining, numRemainingCoupon);
        printf("On average, you spent $%0.2lf on each cup of coffee this month.\n",avgPrice);
    }  
    
	return 0;
}



