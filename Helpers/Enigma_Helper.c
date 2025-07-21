/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enigma_Helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 08:52:57 by            #+#    #+#             */
/*   Updated: 2025/03/08 23:27:52 by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// this function Successfully find the the target_location of
// a given node in the stack [A] ! Using the rules uk !

void	tartget_position(t_unit *head, int h, t_unit *mutan)
{
	t_unit	*headd;
	t_unit	*hold;

	hold = NULL;
	headd = head;
	if (!head || !mutan || h < 3)
		return ;
	while (headd)
	{
		if ((*headd).index > (*mutan).index)
			hold = headd;
		headd = (*headd).next;
	}
	if (!hold)
	{
		assigning_smallest(head, mutan);
		return ;
	}
	while (head)
	{
		if ((*head).index > (*mutan).index && (*head).index < (*hold).index)
			hold = head;
		head = (*head).next;
	}
	(*mutan).targ_locat = (*hold).locat;
}

// This function is just the rest of the upper fuction
// int the case of no higher integer is present then 
// we take the smalles integer in the list !

void	assigning_smallest(t_unit *head, t_unit *mutan)
{
	t_unit	*hold;

	if (!head || !mutan)
		return ;
	hold = head;
	head = (*head).next;
	while (head)
	{
		if ((*head).index < (*hold).index)
			hold = head;
		head = (*head).next;
	}
	(*mutan).targ_locat = (*hold).locat;
}

// This function calculates the cost for the mutan
// to get on the top o his stack ! also another function 
// for it's target ! 

void	local_cost_much_b(t_unit *head, t_unit *headb, t_unit *mutan, int h)
{
	t_unit	*real;
	int		a;

	a = 0;
	real = mutan;
	if (h / 2 < (*mutan).locat || (!(ft_lstsize(headb) % 2)
			&& (h / 2) == (*mutan).locat))
	{
		while (mutan)
		{
			a++;
			mutan = (*mutan).next;
		}
		(*real).cost_b = a * -1;
		if (h == 1)
			(*real).cost_b = 0;
		(*real).cost_a = local_cost_much_a(head,
				sniff_it((*real).targ_locat, head), ft_lstsize(head), 0);
		return ;
	}
	else
	{
		norm_local_cost(head, headb, mutan);
	}
}

// This function is just a norm fix !
// the following code was on the Upper function !

void	norm_local_cost(t_unit *head, t_unit *headb, t_unit *mutan)
{
	int	a;

	a = 0;
	while (headb)
	{
		if (headb == mutan)
			break ;
		a++;
		headb = (*headb).next;
	}
	(*mutan).cost_b = a;
	(*mutan).cost_a = local_cost_much_a(head,
			sniff_it((*mutan).targ_locat, head), ft_lstsize(head), 0);
}
