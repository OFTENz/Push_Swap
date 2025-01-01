/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:40:12 by sel-mir           #+#    #+#             */
/*   Updated: 2024/12/31 02:11:57 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// mallocation of the struct and the fill of it's variable with the 

t_unitt	*push_swap(int ac, char **stack_a)   
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
		rn = (*rn).next;
	}
	return (headd);
}

int	main(int ac, char *av[])
{
	t_unitt	*alpha;
	int	a;
	t_unitt	*bb;
	int	*n;

	n = malloc(sizeof(int));
	*n = 0;
	bb = ft_lstnew(n);
	a = 0;
	if (ac >= 2 && av[0])
	{
		alpha = push_swap(ac, av);
		
		if (!alpha)
			return (printf("Naaahhh Hell Naahh ! "));
		alpha = NULL;
		pa(&alpha, &bb);

	while (alpha)
	{
		printf("%d\n", *((*alpha).numb));
		alpha = (*alpha).next;
		if(!alpha)
			return(printf("End is reached !"));
	}
	}
}
