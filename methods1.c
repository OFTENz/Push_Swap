/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:46:48 by sel-mir           #+#    #+#             */
/*   Updated: 2025/01/03 22:51:43 by sel-mir          ###   ########.fr       */
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

// we took it as double pointer 
// cause it will only change it in the variable of this function 
// while it can change the value of the real pointer when    *hd = sec;    !
// i handled if the there was only one element so no swapping !
// i checked the cases after adding the before variable  || ONE STRUCT !

t_unitt	*sa(t_unitt **hd)
{
	t_unitt	*sec;
	t_unitt	*head;
	t_unitt	*sec_next;
	t_unitt	*ff;

	head = *hd;
	ff = head;
	if (!(head) || !((*head).next))
		return (NULL);
	sec = (*head).next;
	sec_next = (*sec).next;
	if (sec_next)
		(*sec_next).before = head;
	(*sec).before = NULL;
	(*head).before = sec;
	(*head).next = sec_next;
	(*sec).next = head;
	*hd = sec;
	return (ff);
}

void	ss(t_unitt **headd, t_unitt **headdb)
{
	sa(headd);
	sa(headdb);
}

// i handled if the b was empty

// also if the a was empty for some reason in swap !

// i double checked for all the cases after adding the before variable || ONE STRUCT !

void	pa(t_unitt **headd, t_unitt **headdb)
{
	t_unitt	*b_next;

	if (!headdb || !(*headdb))
		return ;
	if (!(*headd))
	{
		(*headd) = (*headdb);
		(*(*headdb)).next = NULL;
		(*(*headdb)).before = NULL;
		return ;
	}
	b_next = (*(*headdb)).next;
	if (b_next)
		(*b_next).before = NULL;
	(*(*headd)).before = (*headdb);
	(*(*headdb)).before = NULL;
	(*(*headdb)).next = (*headd);
	(*headd) = (*headdb);
	(*headdb) = b_next;
}

// i handled if the *headd was NULL !

// also if the stack contained only one struct  no action !

// i checked for the cases after adding the before variable it's good !

void	ra(t_unitt **headd, t_unitt **lst)
{
	t_unitt	*head_next;

	if (!(*headd) || !((*(*headd)).next))
		return ;
	head_next = (*(*headd)).next;
	(*head_next).before = NULL;
	(*(*headd)).before = (*lst);
	(*(*headd)).next = NULL;
	(*(*lst)).next = (*headd);
	(*lst) = (*headd);
	(*headd) = head_next;
}
