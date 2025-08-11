#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char number[20];

    printf("Number: ");
    if (fgets(number, sizeof(number), stdin) == NULL)
    {
        printf("INVALID\n");
        return 1;
    }

    size_t len = strlen(number);
    if (number[len - 1] == '\n')
    {
        number[len - 1] = '\0';
        len--;
    }

    for (size_t i = 0; i < len; i++)
    {
        if (!isdigit(number[i]))
        {
            printf("INVALID\n");
            return 1;
        }
    }

    int sum1 = 0, sum2 = 0;

    for (int i = (int)len - 1, pos = 1; i >= 0; i--, pos++)
    {
        int digit = number[i] - '0';

        if (pos % 2 == 0)
        {
            int product = digit * 2;
            sum1 += product / 10 + product % 10;
        }
        else
        {
            sum2 += digit;
        }
    }

    int total = sum1 + sum2;

    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    int first_digit = number[0] - '0';
    int first_two_digits = (number[0] - '0') * 10 + (number[1] - '0');

    if (len == 15 && (first_two_digits == 34 || first_two_digits == 37))
        printf("AMEX\n");
    else if (len == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
        printf("MASTERCARD\n");
    else if ((len == 13 || len == 16) && first_digit == 4)
        printf("VISA\n");
    else
        printf("INVALID\n");

    return 0;
}
