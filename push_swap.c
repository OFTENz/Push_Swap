#include "push_swap.h"

void push_swap(int  ac, int **stack_a)
{
    int *nums;
    int i;

    i = 0;
    nums = malloc(sizeof(int) * ac);
    if (!nums)
        return ;
    while (i < ac)    
        nums[i] = ft_atoi(stack_a[i++]);
    
}

int main(int ac, char *av[])
{

}