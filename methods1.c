/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:46:48 by sel-mir           #+#    #+#             */
/*   Updated: 2024/12/31 02:11:13 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_unitt	*ft_lstnew(void *content)
{
	t_unitt	*p;

	p = malloc(sizeof(t_unitt));
	if (!p)
		return (NULL);
	(*p).numb = content;
	(*p).next = NULL;
	return (p);
}

// we took it as double pointer cause it will only change it in the variable of this function 
// while it can change the value of the real pointer when    *hd = sec;    !

void	sa(t_unitt **hd)
{
	t_unitt	*sec;
	t_unitt	*head;
	t_unitt	*sec_next;

	head = *hd;
	if (!head || !((*head).next))
		return;
	sec = (*head).next;
	sec_next = (*sec).next;

	(*head).next = sec_next;
	(*sec).next = head;
	*hd = sec;
}

void	ss(t_unitt **headd, t_unitt **headdb)
{
	sa(headd);
	sb(headdb);
}

// i handled if the b was empty 	&&		  also if the a was empty for some reason in swap !

void	pa(t_unitt **headd, t_unitt **headdb)
{
	t_unitt	*b_next;

	if (!headdb || !(*headdb))
		return;
	if (!(*headd))
	{
		(*headd) = (*headdb);
		return;		
	}
	b_next = (*(*headdb)).next;
	(*(*headdb)).next = (*headd);
	(*headd) = (*headdb);
	(*headdb) = b_next;
	
}