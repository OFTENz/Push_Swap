/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OOEnigmaHelper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:21:55 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/09 00:22:38 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// This function just  make the number positive
// if it was negative !

int	minus(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

// This function calculate the cost_a && cost_b
// for all of the stack [B] !

void	local_cost_handling(t_unit *head, t_unit *headb)
{
	t_unit	*hold;

	hold = headb;
	while (hold)
	{
		local_cost_much_b(head, headb, hold, ft_lstsize(headb));
		hold = (*hold).next;
	}
}

// This function fixes the stack[A] cause it's not fully 
// sorted !

void	fix_stacka(t_unit **head, t_unit **headb)
{
	t_unit	*first;

	first = get_index(*head);
	(*first).cost_b = 0;
	(*first).cost_a = local_cost_much_a(*head, first, ft_lstsize(*head), 0);
	execution(head, headb, first, 1);
}

t_unit	*get_three_biggest(t_unit *real)
{
	t_unit	*hold;

	hold = real;
	while (real)
	{
		if ((*real).number > (*hold).number)
			hold = real;
		real = (*real).next;
	}
	return (hold);
}

//This function just a norm fix it count how many nodes until
// it meats the mutan node !
int	nrmfx(t_unit *mutan, t_unit *head)
{
	int	a;

	a = 0;
	while (head)
	{
		if (head == mutan)
			break ;
		a++;
		head = (*head).next;
	}
	return (a);
}
