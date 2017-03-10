#include <stdio.h>
#include <cs50.h>

int get_pos_int(void);
int fib(int x);

int main(void)
{
    int x = get_pos_int();
    for (int i = 0; i < x; i ++)
    {
        printf("%d\n", fib(i));
    }
    return 0;
}

int get_pos_int(void)
{
    printf("Type a Postive Integer:\n");
    int number = GetInt();
    
    if (number > 0)
        return number;
        
    else
    {
        printf("Not a positive integer\n");
         number = get_pos_int();
    }
    return 0;
}

int fib(int x)
{
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;
    else
        return (fib(x - 1) + fib(x - 2));
}