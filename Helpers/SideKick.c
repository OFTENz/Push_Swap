/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SideKick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:47:27 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/14 09:13:25 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// This Function go Through all of the av and
// checks if it contains anything other then digits : Success !

int	sanitize_it(int ac, char **av)
{
	int	a;
	int	i;

	a = 1;
	i = 0;
	if (emptyness(av, ac))
		return (-1);
	while (a < ac)
	{
		while (av[a][i])
		{
			if (!(av[a][i] <= '9' && av[a][i] >= '0') && av[a][i] != ' ')
			{
				if (!((av[a][i] == '+' || av[a][i] == '-')
						&& (av[a][i + 1] <= '9' && av[a][i + 1] >= '0')))
					return (-1);
			}
			i++;
		}
		i = 0;
		a++;
	}
	return (0);
}

// This function Counts How many array of character aka Future Integers

int	howmany(char ***big)
{
	int	a;
	int	i;
	int	h;

	a = 0;
	i = 0;
	h = 0;
	if (!big[a])
		return (h = 0, h);
	while (big[a])
	{
		while (big[a][i])
			i++;
		h += i;
		i = 0;
		a++;
	}
	return (h);
}

// This function calculates the Integer Like the normal atoi
// but it checks for 

int	*ft_atoi(char *str, int	*p)
{
	int			a;
	int			res;
	int			sign;
	long long	d;

	sign = 1;
	res = 0;
	a = 0;
	while (str[a] == ' ' || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign *= -1;
		a++;
	}
	while (str[a] <= '9' && str[a] >= '0')
	{
		d = res;
		res = res * 10 + str[a++] - 48;
		if (res / 10 != d)
			return (NULL);
	}
	return (*p = (res * sign), p);
}

// This Function checks if a integer is duplicated in the array of integers ! 

int	duplicate_check(int *nums, int h)
{
	int	a;
	int	i;

	a = 0;
	i = 1;
	while (a < h - 1)
	{
		while (i < h)
		{
			if (nums[a] == nums[i] && a != i)
				return (-1);
			i++;
		}
		i = 0;
		a++;
	}
	return (0);
}

//This function creates a node and fill it's integer with the give one !

t_unit	*ft_lstnew(int number, int index, int locat)
{
	t_unit	*p;

	p = ft_malloc(sizeof(t_unit));
	if (!p)
		return (NULL);
	(*p).number = number;
	(*p).index = index;
	(*p).locat = locat;
	(*p).next = NULL;
	return (p);
}
