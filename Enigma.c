/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enigma.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:46:43 by            #+#    #+#             */
/*   Updated: 2025/03/14 10:08:59 by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Helpers/pushswap.h"

// This is the function that handles the complextity of the swaping !

void	enigma(t_unit *head, int h)
{
	int			a;
	t_unit		*headb;
	int			*ptr;
	int			p;

	headb = NULL;
	a = 1;
	if (h > 3)
		leave_three_process(&head, &headb, h);
	sort_three(&head, &headb, h);
	while (headb)
	{
		target_position_handling(head, headb, h);
		local_cost_handling(head, headb);
		ptr = propabilities(headb, ft_lstsize(headb));
		p = 0;
		a = 1;
		normfix_alpha(headb, ptr, &a, &p);
		norm_fix(p, &head, &headb, h);
	}
	fix_stacka(&head, &headb);
}

// This is just a fix for the norm !
// the followign code was in the upper function !
// This function finds the cheapest in array of 
// propabilites !

void	normfix_alpha(t_unit *headb, int *ptr, int *a, int *p)
{
	int	hold;

	hold = ptr[0];
	while (*a < ft_lstsize(headb))
	{
		if (ft_lstsize(headb) == 1)
			break ;
		if (ptr[*a] < hold)
		{
			*p = *a;
			hold = ptr[*a];
		}
		(*a)++;
	}
}

// This is just a norm fix these function were up !
// after finding the cheapest we get it's address
// using the sniff_if function and we execute 
// the cost_a and cost_b !

void	norm_fix(int p, t_unit **head, t_unit **headb, int h)
{
	t_unit	*s;

	s = sniff_it(p, *headb);
	execution(head, headb, s, 0);
	target_position_handling(*head, *headb, h);
	local_cost_handling(*head, *headb);
}
