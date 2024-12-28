/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:46:48 by sel-mir           #+#    #+#             */
/*   Updated: 2024/12/27 23:12:23 by sel-mir          ###   ########.fr       */
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
