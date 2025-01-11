/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:34:01 by sel-mir           #+#    #+#             */
/*   Updated: 2025/01/11 15:32:11 by sel-mir          ###   ########.fr       */
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
