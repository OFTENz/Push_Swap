/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:04:11 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/15 04:52:32 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_unit
{
	struct s_unit	*next;
	int				number;
	int				index;
	int				locat;
	int				targ_locat;
	int				cost_a;
	int				cost_b;

}	t_unit;

char	**split(char *s, char c);
char	***split_work(char ***big, char **av, int ac);

int		sanitize_it(int ac, char **av);
int		howmany(char ***big);
int		duplicate_check(int *nums, int h);
int		refresh(int	**nums, int	*big, int *index, int h);
int		*ft_atoi(char *str, int	*p);
int		*build_int(char ***big, int h);
int		**link_address(int *nums, int h);
int		ft_lstsize(t_unit *lst);
int		*propabilities(t_unit *headb, int h);
int		minus(int a);
int		local_cost_much_a(t_unit *head, t_unit *mutan, int h, int a);
int		check_null(int h, int **ptr);
int		norm_fx(int **nums, int *o, int *a, int h);
int		nrmfx(t_unit *mutan, t_unit *head);
int		emptyness(char **av, int ac);
int		empty_check(char *str);

t_unit	*ft_lstnew(int number, int index, int locat);
t_unit	*build_it(int ac, char **av);
t_unit	*create_strcut(int *nums, int *index, int h);
t_unit	*end_loop(t_unit *head);
t_unit	*sniff_it(int locat, t_unit *head);
t_unit	*get_three_biggest(t_unit *real);

void	bubble_sort(int *nums, int h);
void	complete(int *ndx, int **ptr, int h, int hh);
void	enigma(t_unit *head, int h);
void	free_struct(t_unit *head);
void	free_split(char ***big);
void	fix_positions(t_unit *head, t_unit *headb);
void	*index_job(int *nums, int h);
void	leave_three(t_unit **head, t_unit **headb, int h);
void	flussh(void);
void	*free_alloc(void *p, int flag);

void	*sa(t_unit **head);
void	*pa(t_unit **head, t_unit **headb, int a);
void	ra(t_unit **head, t_unit **headb, int a);
void	rr(t_unit **head, t_unit **headb);
void	*ft_malloc(size_t a);
void	rra(t_unit **head, t_unit **headb, int a);
void	rrr(t_unit **head, t_unit **headb);
void	sort_three(t_unit **head, t_unit **headb, int h);
void	tartget_position(t_unit *head, int h, t_unit *mutan);
void	assigning_smallest(t_unit *head, t_unit *mutan);
void	local_cost_much_b(t_unit *head, t_unit *headb, t_unit *mutan, int h);
void	target_position_handling(t_unit *head, t_unit *headb, int h);
void	execution(t_unit **head, t_unit **headb, t_unit *mutan, int flag);
void	local_cost_handling(t_unit *head, t_unit *headb);
void	fix_stacka(t_unit **head, t_unit **headb);
void	norm_fix(int p, t_unit **head, t_unit **headb, int h);
void	norm_execution(t_unit *mutan, t_unit **head, t_unit **headb);
void	norm_local_cost(t_unit *head, t_unit *headb, t_unit *mutan);
void	fix_norm(t_unit **head, t_unit **headb, int h);
void	normfix_alpha(t_unit *headb, int *ptr, int *a, int *p);
void	leave_three_process(t_unit **head, t_unit **headb, int h);

t_unit	*get_index(t_unit *head);

#endif