/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:40:12 by sel-mir           #+#    #+#             */
/*   Updated: 2024/12/28 23:35:50 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// mallocation of the struct and the fill of it's variable with the 

t_unitt	*push_swap(int ac, char **stack_a)   
{
	t_unitt	*rn;
	t_unitt	*headd;
	int		**nums;
	int		i;

	i = 0;
	nums = put_to_heap(stack_a, ac);
	if (!nums)
		return (NULL);
	rn = malloc(sizeof(t_unitt));
	(*rn).numb = nums[i++];
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

	a = 0;
	if (ac >= 2)
	{
		alpha = push_swap(ac, av);
		
		if (!alpha)
			return (printf("Naaahhh Hell Naahh ! "));
			

		while (alpha)
		{
			printf("%d\n", *((*alpha).numb));
			alpha = (*alpha).next;
		}
	}
}
