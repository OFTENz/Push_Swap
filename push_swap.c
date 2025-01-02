/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:40:12 by sel-mir           #+#    #+#             */
/*   Updated: 2025/01/02 20:45:39 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// mallocation of the struct and the fill of it's variable with the 

t_unitt	*push_swap(int ac, char **stack_a, t_unitt **last, 	t_unitt	**alast)
{
	t_unitt	*rn;
	t_unitt	*headd;
	t_unitt	*headdb;
	int		**nums;
	int		i;

	i = 0;
	headdb = NULL;
	nums = put_to_heap(stack_a, ac);
	if (!nums)
		return (NULL);
	rn = ft_lstnew(nums[i++]);
	headd = rn;

	while (i < (ac - 1))
	{
		(*rn).next = ft_lstnew(nums[i++]);
		if (i == ac - 2)
			*alast = (*rn).next;
		rn = (*rn).next;
	}
	*last = rn;
	return (headd);
}

int	main(int ac, char *av[])
{
	t_unitt	*alpha;
	t_unitt	**last;
	t_unitt	**alast;
	t_unitt	*l;
	t_unitt	*ll;
	int	a;

	last = &l;
	alast = &ll;
	a = 0;
	if (ac >= 2 && av[0])
	{
		alpha = push_swap(ac, av, last, alast);
		
		rra(&alpha, last, *alast);

		if (!alpha)
			(printf("Alpha is NULL  ! \n"));

	while (alpha)
	{
		printf("%d\n", *((*alpha).numb));
		alpha = (*alpha).next;
		if(!alpha)
			(printf("End is reached !"));
	}


	}
}
