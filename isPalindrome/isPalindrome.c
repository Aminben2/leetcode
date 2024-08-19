#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

char *ft_itoa(int nb)
{
    char *number;
    long nbr = nb;
    int len;

    len = (nb < 0 ? 2 : 1);
    while (nb && ++len)
        nb /= 10;
    number = malloc(len);
    number[--len] = '\0';
    if (nbr <= 0)
    {
        number[0] = (nbr < 0 ? '-' : '0');
        nbr = -nbr;
    }
    while (nbr)
    {
        number[--len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return number;
}

bool isPalindrome(int x)
{
    char *str = ft_itoa(x);
    int i = 0;
    int len = 0;
    while (str[len])
        len++;
    if (x < 0)
        i++;
    printf(" i = %d, len = %d\n", i, len);
    while (str[i])
    {
        if (str[i] != str[x < 0 ? len - i : len - i - 1])
            return false;
        i++;
    }
    return true;
}

int main(int ac, char **av)
{
    printf("%d", isPalindrome(atoi(av[1])));
    return 0;
}