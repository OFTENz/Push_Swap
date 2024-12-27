#include "push_swap.h"

void push_swap(int  ac, int **stack_a)
{
    int *nums;
    int i;
    unitt   *old;

    i = 0;
    old = NULL;
    nums = malloc(sizeof(int) * ac);
    if (!nums)
        return ;
    while (i < ac)    
        nums[i] = ft_atoi(stack_a[i++]);
    i = 0;
    while (i < ac)
        old = mv_to_struct(old, &nums[i++]);
    
    
}

int main(int ac, char *av[])
{

}