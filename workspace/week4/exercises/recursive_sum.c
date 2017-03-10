#include <stdio.h>
#include <cs50.h>

int get_pos_int(void);
int sum(int n);

int main(void)
{
    int number = get_pos_int();
    printf("Sum(%d) = %d\n", number, sum(number));
    return 0;
}

int get_pos_int(void)
{
    int number = 0;
    while (number <= 0)
    {
        printf("Type a Postive Integer:\n");
        number = GetInt();
    }
    
    return number;
}

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return (n + sum(n - 1));
}