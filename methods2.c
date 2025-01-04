/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:34:01 by sel-mir           #+#    #+#             */
/*   Updated: 2025/01/04 06:56:40 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_unitt **headd, t_unitt **lasta, t_unitt **headdb, t_unitt **lastb)
{
	ra(headd, lasta);
	ra(headdb, lastb);
}

// i handled if the *headd was NULL !

// also if the stack contained only one struct  no action !

// i checked after adding the before variable !

void	rra(t_unitt **headd, t_unitt **last, t_unitt	**aalast)
{
	t_unitt	*alast;

	if (!(*headd) || !((*(*headd)).next))
		return ;
	alast = *aalast;
	(*alast).next = NULL;
	(*(*last)).next = (*headd);
	(*(*last)).before = NULL;
	(*(*headd)).before = (*last);
	(*headd) = (*last);
	(*last) = alast;
	(*aalast) = (*(*last)).before;
	
	
}

void	rrr(t_unitt **headd, t_unitt **lasta, t_unitt	**alasta, t_unitt **headdb, t_unitt **lastb, t_unitt	**alastb)
{
	rra(headd, lasta, alasta);
	rra(headdb, lastb, alastb);
}


// this function freez the integers in the heap and their pointers ! 

void	free_all(int **nums, int num, t_unitt *headd, t_unitt *headdb)
{
	int	a;
	t_unitt	*hold;

	a = 0;
	while (nums[a])
		free(nums[a++]);
	a = 0;
	while (a < num - 1)
		free(nums++);
	
	if (headd)
	{
		while (headd)
		{
			hold = (*headd).next;
			free(headd);
			headd = hold;
		}
	}
	if (headdb)
	{
		while (headdb)
		{
			hold = (*headdb).next;
			free(headdb);
			headdb = hold;
		}
	}
		
}
