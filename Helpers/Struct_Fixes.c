/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Struct_Fixes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:59:23 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/14 05:05:55 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//This function fixes the locations of the structs !

void	fix_positions(t_unit *head, t_unit *headb)
{
	int	a;

	a = 0;
	while (head)
	{
		(*head).locat = a++;
		head = (*head).next;
	}
	a = 0;
	while (headb)
	{
		(*headb).locat = a++;
		headb = (*headb).next;
	}
}

// This function loops through the list and gives u 
// the before last node i added the "((*head).next)"
// so it doesnt segs when theres only one node !

t_unit	*end_loop(t_unit *head)
{
	t_unit	*one;

	one = head;
	while (head)
	{
		if (head && ((*head).next) && !((*((*head).next)).next))
			return (head);
		head = (*head).next;
	}
	return (one);
}

void	rr(t_unit **head, t_unit **headb)
{
	ra(head, headb, -1);
	ra(headb, head, -1);
	write (1, "rr\n", 3);
}
// This function pushes all and leave only three numbers in the Stack [A]

void	leave_three(t_unit **head, t_unit **headb, int h)
{
	int	i;

	i = 0;
	if (h > 3)
	{
		while (i < h - 3)
		{
			pa(headb, head, 1);
			i++;
		}
	}
}

// this function sort the three number in Stack [A]

void	sort_three(t_unit **head, t_unit **headb, int h)
{
	if (!head || h == 1)
		return ;
	if (h == 2)
	{
		if ((**head).index > (*((**head).next)).index)
		{
			sa(head);
		}
		return ;
	}
	if ((*(get_three_biggest(*head))).locat == 0)
		ra(head, headb, 0);
	else if ((*(get_three_biggest(*head))).locat == 1)
		rra(head, headb, 0);
	if ((**head).index > (*((**head).next)).index)
		return (sa(head), (void)0);
	fix_positions(*head, *headb);
}
