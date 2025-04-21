/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 08:21:26 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/15 05:41:23 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	*ft_malloc(size_t a)
{
	void	*p;

	p = malloc(a);
	if (!p)
		free_alloc(p, 1);
	else
		free_alloc(p, 0);
	return (p);
}

void	*free_alloc(void *p, int flag)
{
	static void	**alpha;
	static int	a;
	int			j;

	if (!alpha)
	{
		alpha = malloc(sizeof(void *) * INT_MAX);
		if (!alpha)
			return (NULL);
	}
	if (flag && alpha)
	{
		j = 0;
		while (j < a)
		{
			free(alpha[j]);
			j++;
		}
		free(alpha);
		a = 0;
		return (NULL);
	}
	else if (!flag && alpha)
		alpha[a++] = p;
	return (NULL);
}
