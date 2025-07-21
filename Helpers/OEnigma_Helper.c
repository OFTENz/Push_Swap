/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OEnigma_Helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:24:40 by            #+#    #+#             */
/*   Updated: 2025/03/14 09:12:54 by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// Copy of the B version nothing different of course !
// So for the stack[B] we get cost_b for that element to 
// get on it's stack and cost_a for it's target_position element
// to get on the top of it's stack wich is stack[A] !
// Se we can calculate the total of both to get the cheapest !

int	local_cost_much_a(t_unit *head, t_unit *mutan, int h, int a)
{
	t_unit	*real;

	real = mutan;
	if (h == 3 && (*mutan).locat == 1)
		return (1);
	if (h == 1)
		return (0);
	if (h / 2 < (*mutan).locat || (!(ft_lstsize(head) % 2)
			&& (h / 2) == (*mutan).locat))
	{
		while (mutan)
		{
			a++;
			mutan = (*mutan).next;
		}
		return (a * -1);
	}
	else
	{
		return (nrmfx(mutan, head));
	}
}

// Target_Position_handling just the Face 

void	target_position_handling(t_unit *head, t_unit *headb, int h)
{
	while (headb)
	{
		tartget_position(head, h, headb);
		headb = (*headb).next;
	}
}

// This calculates the cost to get the elemet to it's place 
// so we can choose the cheapest later ! 

//		[B]element(cost_b) + [B]element(cost_a);
// 								|^|
//								|^|
//								|_ => using the Sniff it function !

int	*propabilities(t_unit *headb, int h)
{
	int	*prob;
	int	a;

	a = 0;
	prob = ft_malloc(sizeof(int) * h);
	if (!prob)
		return (write(2, "Error\n", 6), NULL);
	while (a < h)
	{
		prob[a++] = minus((*headb).cost_a) + minus((*headb).cost_b);
		headb = (*headb).next;
	}
	return (prob);
}

// This fuction Do the Methods to get stuff in order !

void	execution(t_unit **head, t_unit **headb, t_unit *mutan, int flag)
{
	while ((*mutan).cost_a < 0 && (*mutan).cost_b < 0)
	{
		rrr(head, headb);
		((*mutan).cost_a)++;
		((*mutan).cost_b)++;
	}
	while ((*mutan).cost_a < 0 || (*mutan).cost_b < 0)
	{
		if ((*mutan).cost_a < 0)
		{
			rra(head, headb, 0);
			((*mutan).cost_a)++;
		}
		if ((*mutan).cost_b < 0)
		{
			rra(headb, head, 1);
			((*mutan).cost_b)++;
		}
	}
	norm_execution(mutan, head, headb);
	if (!flag)
		pa(head, headb, 0);
}

// This function is just a norm_fix !
// nothing but the rest of the upper function ! 

void	norm_execution(t_unit *mutan, t_unit **head, t_unit **headb)
{
	while ((*mutan).cost_a > 0 && (*mutan).cost_b > 0)
	{
		rr(head, headb);
		((*mutan).cost_a)--;
		((*mutan).cost_b)--;
	}
	while ((*mutan).cost_a > 0 || (*mutan).cost_b > 0)
	{
		if ((*mutan).cost_a > 0)
		{
			ra(head, headb, 0);
			((*mutan).cost_a)--;
		}
		if ((*mutan).cost_b > 0)
		{
			ra(headb, head, 1);
			((*mutan).cost_b)--;
		}
	}
}
