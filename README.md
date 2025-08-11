Credit
This is the third project of the CS50x course.
The goal is to validate credit card numbers and identify their type (American Express, MasterCard, or Visa) using Luhn’s algorithm.

This version has been adapted to run without the CS50 library, so anyone can compile and run it using only a standard C compiler.

What it does

Prompts the user to enter a credit card number
Checks if the number is valid according to Luhn’s algorithm
Identifies the card type based on number length and prefix
Prints exactly one of the following: AMEX, MASTERCARD, VISA, or INVALID

How to use

Compile the code with:
gcc credit.c -o credit

Run the program with:
./credit

Enter the credit card number (digits only, no spaces or dashes) when prompted

About
This project helps practice working with strings, loops, conditionals, and algorithms in C.

CS50x — Introduction to Computer Science by Harvard University
Project by Davi Teodoro

