/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:40:12 by sel-mir           #+#    #+#             */
/*   Updated: 2025/01/03 22:08:51 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// mallocation of the struct and the fill of it's variable with the 

t_unitt	*push_swap(int ac, char **stack_a, t_unitt **last, t_unitt	**alast)
{
	t_unitt	*rn;
	t_unitt	*headd;
	t_unitt	*before;
	t_unitt	*headdb;
	int		**nums;
	int		i;

	i = 0;
	headdb = NULL;
	nums = put_to_heap(stack_a, ac);
	if (!nums)
		return (NULL);
	rn = ft_lstnew(nums[i++]);
	*alast = rn;
	(*rn).before = NULL;

	headd = rn;
	while (i < (ac - 1))
	{
		(*rn).next = ft_lstnew(nums[i++]);
		before = rn;
		rn = (*rn).next;
		(*rn).before = before;
	}
	*last = rn;
	*alast = (*rn).before;
	return (headd);
}

int	main(int ac, char *av[])
{
	t_unitt	*alpha;
	t_unitt	*last;
	t_unitt	*alast;
	
// 	t_unitt	*stackb;
// 	t_unitt	*lastb;
// 	t_unitt	*alastb;
// 	t_unitt	*alphab;
// 	int	*ntt;
// 	int	*nt;
// //////////////////////////////////////////////////////////////

// 	nt = malloc(sizeof(int));
// 	ntt = malloc(sizeof(int));
// 	*nt = 1;
// 	*ntt = 2;
// 	stackb = ft_lstnew(nt);
// 	alphab = stackb;
// 	alastb = stackb;
// 	(*stackb).next = ft_lstnew(ntt);
// 	lastb = (*stackb).next;
	
	
// //////////////////////////////////////////////////////////////
	int	a;

	a = 0;
	if (ac >= 2 && av[0])
	{
		alpha = push_swap(ac, av, &last, &alast);
		if (!alpha)
			(printf("Alpha is NULL  ! \n"));

		sa(&alpha);
		printf("\n ----------------\nNormal ->\n");
		
		while (alpha)
		{
			printf("\n%d", *((*alpha).numb));
			alpha = (*alpha).next;
			if(!alpha)
				(printf("\n Stack a Ended !\n"));
		}

	}
}
