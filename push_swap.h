/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:24:36 by sel-mir           #+#    #+#             */
/*   Updated: 2025/01/03 05:09:42 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_unitt
{
	struct t_unitt *before;
	struct t_unitt	*next;
	int				*numb;

}	t_unitt;

t_unitt	*ft_lstnew(void *content);

int		*ft_sidek(char *str);
int		*ft_atoi(char *str, int	*p);
int		**put_to_heap(char **stack_a, int ac);

t_unitt	*sa(t_unitt **hd);
void	pa(t_unitt **headd, t_unitt **headdb);
void	ra(t_unitt **headd, t_unitt **lst);
void	rra(t_unitt **headd, t_unitt **last, t_unitt	*alast);
void	rr(t_unitt **headd, t_unitt **lasta, t_unitt **headdb, t_unitt **lastb);
void	rrr(t_unitt **headd, t_unitt **lasta, t_unitt	*alasta, t_unitt **headdb, t_unitt **lastb, t_unitt	*alastb);


#endif