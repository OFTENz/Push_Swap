/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_Helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:09:55 by            #+#    #+#             */
/*   Updated: 2025/03/15 05:42:11 by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// all what this function do is it takes
// the arguments from the previous function 
// and set them to new value
// so that the function resume it's work with correct values !
// why i did the static variable is cause i cant pass 
// more variables to the function and i just pass the value 
// to big and i take it from it and it's gonna be overwritten 
// anyways !

int	refresh(int	**nums, int	*big, int *index, int h)
{
	int	a;

	a = 0;
	while (a < h)
	{
		if (nums[a])
		{
			*big = *nums[a];
			*index = a;
		}
		a++;
	}
	return (1);
}
// int	refresh(int	**nums, int	*a, int	*big, int *index)
// {
// 	int			o;
// 	static int	h = 0;

// 	o = 0;
// 	*a = 0;
// 	if (!h)
// 		h = *big;
// 	while (o < h)
// 	{
// 		if (nums[o])
// 		{
// 			*big = *nums[o];
// 			*index = o++;
// 			while (o < h)
// 			{
// 				if (nums[o])
// 					return (*a = o, (0));
// 				o++;
// 			}
// 			return (-1);
// 		}
// 		o++;
// 	}
// 	return (-9);
// }

// Allocation of an arrray of pointers that points
// to the addresses of each integer in the array !

int	**link_address(int *nums, int h)
{
	int	a;
	int	**ptr;

	a = 0;
	ptr = ft_malloc(sizeof(int *) * (h + 1));
	if (!ptr)
		return (NULL);
	ptr[h] = NULL;
	while (a < h)
	{
		ptr[a] = &nums[a];
		a++;
	}
	return (ptr);
}

//This Function gives for every integer in the array an index !
// We did the : ndx[0] = h; for the case of one number !

void	complete(int *ndx, int **ptr, int h, int hh)
{
	int	a;
	int	index;
	int	big;

	a = 1;
	big = *ptr[0];
	index = 0;
	while (hh >= 0)
	{
		while (a < h)
		{
			if (ptr[a] && *ptr[a] >= big)
			{
				big = *ptr[a];
				index = a;
			}
			a++;
		}
		ndx[index] = hh;
		ptr[index] = NULL;
		hh--;
		a = 0;
		refresh(ptr, &big, &index, h);
	}
}

// This function  just loop in the av and put addresses in the array
// of double pointers !

char	***split_work(char ***big, char **av, int ac)
{
	int	a;
	int	i;

	i = 1;
	a = 0;
	while (a < (ac - 1))
	{
		big[a] = split(av[i++], ' ');
		if (!big[a++])
			return (NULL);
	}
	return (big);
}

int	ft_lstsize(t_unit *lst)
{
	int		a;
	t_unit	*p;

	p = lst;
	a = 0;
	if (!p)
		return (0);
	while (p)
	{
		p = (*p).next;
		a++;
	}
	return (a);
}
