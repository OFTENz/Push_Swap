/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplicity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:27:48 by sel-mir           #+#    #+#             */
/*   Updated: 2024/12/28 23:13:14 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// mallocation of the array of integer  pointers ! and filling with integer addresses 

int	**put_to_heap(char **stack_a, int ac)
{
	int	**nums;
	int	i;
	int	a;

	i = 0;
	a = 1;

	nums = malloc(sizeof(int *) * ac);
	nums[(ac - 1)] = NULL;
 
		if (!nums)
			return (NULL);
		while (a < ac)
		{
			nums[i] = ft_sidek(stack_a[a++]);
			if (!nums[i++])
				return (printf("One of the integer addresses is NULL "), NULL);
		}
	return (nums);
}

// mallocation of an integer space  and filtering array of characters from alphabet !

int	*ft_sidek(char *str)
{
	int	a;
	int	*p;

	p = malloc(sizeof(int));
	if (!p)
		return (NULL);
	a = 0;
	while (str[a])
	{
		if (!(str[a] <= '9' && str[a++] >= '0'))
			return (printf(" there's an alphabet !"), NULL);
	}
	return (ft_atoi(str, p));
}

// traiement and creating of the integer inside of the int pointer space !

int	*ft_atoi(char *str, int	*p)
{
	int			a;
	long long	res;
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
			return (printf(" there's an overflow !"),NULL);
	}
	return (*p = (res * sign), p);
}
