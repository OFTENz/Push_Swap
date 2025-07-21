/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Free_Helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 07:52:20 by            #+#    #+#             */
/*   Updated: 2025/03/14 10:43:00 by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// This function checks if the array of pointers 
// used for indexing handling is all NULL !

int	check_null(int h, int **ptr)
{
	int	a;

	a = 0;
	while (a < h)
	{
		if (ptr[a])
			return (1);
		a++;
	}
	return (0);
}

//	Check if string does contain a Number !

int	empty_check(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] <= '9' && str[a] >= '0')
			return (0);
		a++;
	}
	return (1);
}
