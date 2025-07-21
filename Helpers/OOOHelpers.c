/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OOOHelpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:57:41 by            #+#    #+#             */
/*   Updated: 2025/03/12 01:18:22 by           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// This function get you the element from the stack using the index !
// Stack [A] Usually !

t_unit	*sniff_it(int locat, t_unit *head)
{
	while (head)
	{
		if ((*head).locat == locat)
			return (head);
		head = (*head).next;
	}
	return (NULL);
}
// This is just a flush function for the sake
// of the norm !

void	flussh(void)
{
	write (2, "Error\n", 6);
	exit(-1);
}

// This functions splits the stack a in two 
// and then looks for 

void	leave_three_process(t_unit **head, t_unit **headb, int h)
{
	int	a;

	a = 0;
	while (a < (h / 2))
	{
		if ((**head).index <= (h / 2))
		{
			pa(headb, head, 1);
			a++;
		}
		else
		{
			ra(head, headb, 0);
			a++;
		}
	}
	if (ft_lstsize(*head) > 3)
		leave_three(head, headb, ft_lstsize(*head));
}

t_unit	*get_index(t_unit *head)
{
	int		hold;
	t_unit	*first;

	hold = (*head).index;
	first = head;
	while (head)
	{
		if ((*head).index < hold)
		{
			hold = (*head).index;
			first = head;
		}
		head = (*head).next;
	}
	return (first);
}

// This Function Checks if The AVz contains Only Spaces ! 

int	emptyness(char **av, int ac)
{
	int	a;

	a = 1;
	while (a < ac)
	{
		if (empty_check(av[a]))
			return (1);
		a++;
	}
	return (0);
}
