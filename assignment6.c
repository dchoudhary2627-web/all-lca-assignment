#include <stdio.h>

long long factorial_recursive(int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        return number * factorial_recursive(number - 1);
    }
}

long long factorial_iterative(int number)
{
    long long fact = 1;
    int i = 1;

    while (i <= number)
    {
        fact = fact * i;
        i++;
    }

    return fact;
}

int main()
{
    int num;

    printf("Enter the number you want the factorial of: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }

    printf("Factorial of %d (using recursion)  = %lld\n", num, factorial_recursive(num));
    printf("Factorial of %d (using while loop) = %lld\n", num, factorial_iterative(num));

    return 0;
}