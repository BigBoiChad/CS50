// Quseiton: https://cs50.harvard.edu/x/2021/psets/1/credit/
// This code's core logic is to find a way to delege digit to always ge the value of the last digit.
// Luhn’s Algorithm
#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    long Card_Number;
    // Digit_Number is used to find out how many digits this card have ( the Vilad one needs to be 13 16 15)
    // Current_Digit_Value is used to stroe the value on one posititon/ digits; ie 10978 ,the current_Digits on the second digits is 7
    // Even_x2_product is a value where when the digit position is even (the frist even digit is the second-last digits in the case 10978 is 7) ,
    // it time the digit by 2 and then store it. in the case 10978 is  7*2=14
    // Even_Digits is the sum of Even_x2_Product, expect when it is bigger than 10, it will move up a digits and only add the left integer (0~9) in the case od 10978
    // the Even_x2_Product is 7*2 0*2 1*2 = 14 , 0 ,2 . and the Even-Digits is 14%10 (it move up a digits) + 1 + 0 + 2 = 7.
    // Total digit sum is the sum of values in odd position and the values of Even_Digits
    int Digit_Number = 0, Current_Digit_Value = 0, Even_x2_Product = 0, Even_Digits = 0, Odd_Digits = 0,
        Total_Digit_Sum = 0;
    // boolean expression here is to used to determine whether the position is a odd position or even
    // in this case by default it should be false, since the lase digit is odd and the second-last digit is even position
    // when move up a digit we need to change the bool expression to true.
    bool is_even = false;

    // Prompt User for Credit Card Number

    do
    {
        Card_Number = get_long("Card Number: ");
    }
    while (Card_Number < 0);

// Check First Digits of Number
// it used the pwo(10,n) means the n power of 10
// the right part is a long / pow (10,n) which is often a floating value
// when we assign a floation value to a int type varible. so it will only store the integer part of value. For example, when the left part is 4.9192419478194. the computer will only
// assign the 4 in the int varibles

    // check mastercard , we need two digits, becase Mastercare can only satrt with 51, 52, 53, 54, or 55
    int Digits_MstrCrd = Card_Number / pow(10, 14);
    int Digits_Visa_16 = Card_Number / pow(10, 15);
    int Digits_AmEx = Card_Number / pow(10, 13);
    int Digits_Visa_13 = Card_Number / (pow(10, 12));

// Loop to determine identity of each digit
// !=0 means not equal to zero
//Notice this loop we change the card number. check the last line : Card_Number /= 10; it means every round we are going to dvide card_number by 10
// Also card_number is a long type which is the same as interger, so when card_number is less than 1 . it will automatically become 0.-- we reach the final digits
    while (Card_Number != 0)
    {
        // Get Last Digit of Number
        // using card_number % 10 to get the remine number
        // in the case of 100978 the remine number would be 8 -- ergo our last digit value is 8.

        Current_Digit_Value = (Card_Number % 10);

        // Increase Digit Number by 1. now we have 8 we need to move up to next digits, however we need to keep track how many digits there are.
        Digit_Number += 1;

        // Check if Current Digit is at Odd or Even Position in Card Number
        // the computer itself cannot check the position, since it donnot konw how many digits there are -- we now only know one digit
        // So we use the bool expression. since we know the first is not the even position. we can first set the bool is even = false in round 1.

        if (is_even == true)
        {
            // Multiply Digit by 2--According to the luhn algorizm

            Even_x2_Product = Current_Digit_Value * 2;

            // Add Digits of Multiplication Product
            // this is to deal with the special case when the 2 times even vaule is bigger than 10
            // in the case of 100978 the 2 *7 =14. we need to move up a digit and store the 4 and then add up the next digit (that is 1)

            // determine whether the E2P is 0-- which means in this loop we are going to change the E2P
            //Notice the last line E2P /= 10. Same logic which is to delete the last digit
            // for 14 we first need to store the remine vlaue this is 4. and then we change 14 to 1 by delete the last digit using /=10 . since its int type-the result 1.4 will be 1
            // Very clever :)
            while (Even_x2_Product != 0)
            {
                Even_Digits += Even_x2_Product % 10;
                Even_x2_Product /= 10;
            }

            // Tell Program Next Digit is Odd

            is_even = false;
        }
        // Here we jump to this. since the frist digit is the odd position
        else
        {
            // Add Odd Digits -- Accoirding to the luhn algorizm
            // we need to store the value and sum the odd gidit value up

            Odd_Digits += Current_Digit_Value;

            // Tell Program Next Number is Even --- Very smart!!!

            is_even = true;
        }

        //Finnaly we need to remove the last digit. in the case of 100978 when it / 10 it becomes 10097.8. since it long type, it becomes 10097.
        // Remove Last Digit and Repeat
        Card_Number /= 10;
    }
    // Add Odd and Even Digits Together

    Total_Digit_Sum = Even_Digits + Odd_Digits;

// Loop to Check if Card Number is Valid

    if (Total_Digit_Sum % 10 == 0)
     {
        // Check Mastercard

        if (Digit_Number == 16)
        {
            if (Digits_MstrCrd <= 55 && Digits_MstrCrd >= 51)
            {
                printf("MASTERCARD\n");
            }

            // Check Visa 16

            else if (Digits_Visa_16 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // Check American Express

        else if (Digit_Number == 15)
        {
            if (Digits_AmEx == 34 || Digits_AmEx == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // Check Visa 13

        else if (Digit_Number == 13)
        {
            if (Digits_Visa_13 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}