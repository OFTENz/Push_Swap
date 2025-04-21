/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 07:51:33 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/08 23:27:28 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	*sa(t_unit **head)
{
	t_unit	*holder;
	int		hold;

	if (!(*head) || !((**head).next))
		return (NULL);
	holder = (**head).next;
	(**head).next = (*holder).next;
	hold = (**head).locat;
	(**head).locat = (*holder).locat;
	(*holder).locat = hold;
	(*holder).next = *head;
	*head = holder;
	write (1, "sa\n", 3);
	return (*head);
}

void	*pa(t_unit **head, t_unit **headb, int a)
{
	t_unit	*hold;

	(void)a;
	if (!(*headb))
		return (NULL);
	hold = (**headb).next;
	(**headb).next = (*head);
	*head = *headb;
	*headb = hold;
	fix_positions(*head, *headb);
	if (!a)
		write(1, "pa\n", 3);
	else if (a == 1)
		write(1, "pb\n", 3);
	return (*headb);
}

void	rra(t_unit **head, t_unit **headb, int a)
{
	t_unit	*blast;
	t_unit	*last;

	(void)a;
	blast = end_loop(*head);
	last = (*blast).next;
	(*last).next = *head;
	(*blast).next = NULL;
	(*head) = last;
	if (!a)
		write(1, "rra\n", 4);
	else if (a == 1)
		write(1, "rrb\n", 4);
	fix_positions(*head, *headb);
}

void	ra(t_unit **head, t_unit **headb, int a)
{
	t_unit	*hold;

	(void)a;
	if (!head || !((**head).next))
		return ;
	hold = (*(end_loop(*head))).next;
	(*hold).next = *head;
	*head = (**head).next;
	(*((*hold).next)).next = NULL;
	if (!a)
		write(1, "ra\n", 3);
	else if (a == 1)
		write(1, "rb\n", 3);
	fix_positions(*head, *headb);
}

void	rrr(t_unit **head, t_unit **headb)
{
	rra(head, headb, -1);
	rra(headb, head, -1);
	write (1, "rrr\n", 4);
}
