#include "push_swap.h"


// this function allocates an arrya of double pointer and fills every double pointer with the first pointer in the array of pointers
// returned by the split function !


// so the split function takes the arrya and splitt it to one or more and then returns an array of addresses that points to the 
// seperated strings ! cause the split returns the address of the pointer not the address of the array it self !


int **DO_it(char **av, int ac) 
{
    int    a;
    int    i;
    char ***big;


    a = 1;
    i = 0;
    big = malloc(sizeof(char **) *ac);
    big[ac - 1] = NULL;

    while (big[i])
    {
        big[i] = ft_split (av[a++], ' ');
		if (!big[i++])
            return (printf("Split returned a NULL !"), NULL);
    }

    if (CheckforAlpha(big))
        printf("\n One of the array contain an Alphabet !");
	
    return (Assemblee(big));
}

// after the full mallocation of the seperated strings we go through every string and check if it contains an alphabet !

int    CheckforAlpha(char ***big)
{
    int    a;
    int    i;
    int    o;
    char *str;

    a = 0;
    o = 0;
    i = 0;
    while (big[o])
    {
        while (big[o][i])
        {
            str = big[o][i];

            while (str[a])
            {
                if (!(str[a] <= '9' && str[a] >= '0'))
                    return (-1);
                a++;
            }
            a = 0;
            i++;
        }
        o++;
        i = 0;
    }

    return (0);
}

// so that we know how many int pointers to allocate we need to know how many integers aka strings pointed to by the array of pointers
// returned by the split function !

int HowMany(char ***big)
{
	int a;
	int i;
	int h;

	a = 0;
	i = 0;
	h = 0;
	if (!big[a])
		return (h = 0, h);
	while (big[a])
	{
		while(big[a][i])
			i++;
		h += i;
		i = 0;
		a++;
    }
    return (h);
}
int **Assemblee(char ***big)
{
	int a;
	int i;
	int **nums;
	int h;
	int	*dig;
	int	o;

	a = 0;
	i = 0;
	o = 0;
	h = HowMany(big);
	printf("\nthe number of integer is : %d", h);
	nums = malloc(sizeof(int *) * ++h);
	dig = malloc(sizeof(int) * h);
    nums[h - 1] = NULL;
	while (big[a])
	{
		while (big[a][i])
		{
			nums[o] = ft_atoi(big[a][i++], &dig[o]);
			o++;
		}
		i = 0;
		a++;
	}
	
	return (nums);
}