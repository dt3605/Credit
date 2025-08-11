#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    int sum1 = 0, sum2 = 0, total = 0;
    int count = 0;
    long temp = number;

    // Luhn's algorithm
    while (temp > 0)
    {
        int digit = temp % 10;
        if (count % 2 == 0)
        {
            sum1 += digit;
        }
        else
        {
            int doubled = digit * 2;
            sum2 += (doubled / 10) + (doubled % 10);
        }
        temp /= 10;
        count++;
    }

    total = sum1 + sum2;

    // Check Luhn
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Identify card type
    long start_digits = number;
    while (start_digits >= 100)
    {
        start_digits /= 10;
    }

    if ((start_digits == 34 || start_digits == 37) && count == 15)
    {
        printf("AMEX\n");
    }
    else if (start_digits >= 51 && start_digits <= 55 && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((start_digits / 10) == 4 && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
