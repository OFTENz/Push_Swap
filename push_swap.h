/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:24:36 by sel-mir           #+#    #+#             */
/*   Updated: 2024/12/31 01:34:27 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct t_unitt
{
	struct t_unitt	*next;
	int				*numb;

}	t_unitt;

t_unitt	*ft_lstnew(void *content);
int	**put_to_heap(char **stack_a, int ac);
int	*ft_sidek(char *str);
int	*ft_atoi(char *str, int	*p);
void	sa(t_unitt **hd);
#define sb sa
void	pa(t_unitt **headd, t_unitt **headdb);



#endif