/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:24:36 by sel-mir           #+#    #+#             */
/*   Updated: 2025/01/02 20:20:58 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#define sb sa


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
void	pa(t_unitt **headd, t_unitt **headdb);
void	ra(t_unitt **headd, t_unitt **lst);
void	rra(t_unitt **headd, t_unitt **last, t_unitt	*alast);
void	rr(t_unitt **headd, t_unitt **lasta, t_unitt **headdb, t_unitt **lastb);





#endif