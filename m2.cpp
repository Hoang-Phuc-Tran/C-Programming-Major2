/*
 * Filename:	m2.cpp
 * Project:	    Major Assignment 2
 * By:	    	Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		January 28, 2022
 * Description:  The functions in this file are used to calculate powers. It calculate two numbers
                 of the user input (the base number and the exponent number). The program loops displaying 
                 the menu each time that menu input is required and Only quit the program when the user selects
                 menu item 4. 
 */


#include <stdio.h>
#pragma warning(disable: 4996)   // required by Visual Studio 


 // Prototypes
int getNum(void);
int powerCalculation(int, int);
int rangeChecker(int, int, int);



int main(void)
{ 
    // Initialize maximum and minimum for the base nummber in the range 1 to 25.
    const int kMaximumBase = 25;
    const int kMinimumBase = 1;
    // Initialize maximum and minimum for the exponent number in the range 1 to 5.
    const int KMaximumExponent = 5;
    const int kMinimumExponent = 1;

    int base = 1;
    int exponent = 1;
    int menu = 0;

    do {
        // Display menu
        printf("\n\nPower Menu\n\n");
        printf("     1. Change base\n");
        printf("     2. Change exponent\n");
        printf("     3. Display base raised to exponent\n");
        printf("     4. Exit program\n\n");
        printf("Option?  ");

        // Take option input from the user
        menu = getNum();

        // Check the number of user is valid or not
        if (menu < 1 || menu > 4)
        {
            // If the number is not in the range 1 to 4, displaying "invalid entry"
            printf("Invalid entry");
        }
        // Change base
        else if (1 == menu)
        {   
            int changeBase = 1;
            int check = 0;

            printf("\nChange Base:  ");

            // Get base number from the user
            changeBase = getNum();

            /* Call the rangeCheker function to check the number is valid or not.It will return 1 if 
            the number is valid, and return 0 if the number is out of range */
            check = rangeChecker(changeBase, kMinimumBase, kMaximumBase);

            if (1 == check) 
            {   
                // if the value of the user is valid then put it in base variable.
                base = changeBase;
            }
            else
            {   
                // if the value of the user is out of range, displaying message.
                printf("Base value is out of range!");
            }
        }
        // Change exponent
        else if (2 == menu)
        {
            int changeExponent = 1;
            int check = 0;

            printf("\nChange Exponent:  ");

            // Get exponent number from the user
            changeExponent = getNum();

            // Call the rangeCheker function to check the number is valid or not
            // It will return 1 if the number is valid, and return 0 if the number is out of range
            check = rangeChecker(changeExponent,kMinimumExponent, KMaximumExponent);

            if (1 == check)
            {
                // if the value of the user is valid then put it in exponent variable.
                exponent = changeExponent;
            }
            else
            {
                // if the value of the user is out of range, displaying message.
                printf("Exponent value is out of range!");
            }
        }
        // Calculate and Display base raised to exponent
        else if (3 == menu)
        {   
            int power = 1;

            // calculate and assign the value to power variable
            power = powerCalculation(base, exponent);

            // display base, exponent and power after calculate
            printf("%d to the power of %d is %d", base, exponent, power);
        }
        // Return 0 if the number of user is 4
        else
        {   
            return 0;
        }
    // Exit if the number is 4
    } while (menu != 4);

	return 0;
}

/*
* Function: getNum()
* Description: This function will return the number which user input
* Parameters: void
* Returns: int: -1 if the user did not enter a number recognizable by the system,
otherwise it will return the number of user.
*/
int getNum(void)
{
    /* the array is 121 bytes in size; we'll see in a later lecture how we can
    improve this code */
    char record[121] = { 0 }; /* record stores the string */
    int number = 0;
    /* NOTE to student: brace this function consistent with your others */

    /* use fgets() to get a string from the keyboard */
    fgets(record, 121, stdin);

    /* extract the number from the string; sscanf() returns a number
     * corresponding with the number of items it found in the string */
    if (sscanf(record, "%d", &number) != 1)
    {
        /* if the user did not enter a number recognizable by
         * the system, set number to -1 */
        number = -1;
    }
    return number;
}


/*
* Function: powerCalculation()
* Description: This function will calculate the power from user's inputs. It takes the value 
               of base variable to power the value of exponent varialbe,then put it in power varialbe.
* Parameters: There are two int parameters (int base and int exponent)
* Returns: int: power
*/
int powerCalculation(int base, int exponent)
{   
    int power = 1;
    // Stop the loop if exponent is 0
    while (exponent != 0) 
    {
        // Multiply power to base then put the value into the power variable.
        power *= base;
        // Decrease exponent to 1
        --exponent;
    }
    return power;
}


/*
* Function: rangeChecker()
* Description: Check the value variable whether it's within the range of minimum variable and maximum variable or not.
* Parameters: There are three int parameters (int value, int minimum and int maximum).
* Returns: int: 0 if the value is out of range and int: 1 if the value is within the specified range.
*/
int rangeChecker(int value, int minimum, int maximum)
{   
    // Check if the value is in the rage minimum to maxumum
    if (value >= minimum && value <= maximum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}