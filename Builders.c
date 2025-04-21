/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builders.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:28:51 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/14 10:43:19 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Helpers/pushswap.h"

// This function Allocates an  Array of Double Pointers to hold the &Pointer
// returned by split wich is only the first element !
// I give the link_all function h variable twice 
// for the sake of the norminette see the use of hh 
// in the function !

t_unit	*build_it(int ac, char **av)
{
	int		*nums;
	char	***big;
	int		*ndx;
	int		h;
	t_unit	*head;

	big = ft_malloc(sizeof(char **) * ac);
	if (!big)
		return (write(2, "Error\n", 6), NULL);
	big[ac - 1] = NULL;
	if (!split_work(big, av, ac))
		return (write (2, "Error\n", 6), NULL);
	h = howmany(big);
	nums = build_int(big, h);
	if (duplicate_check(nums, h))
		return (write(2, "Error\n", 6), NULL);
	ndx = index_job(nums, h);
	if (!ndx)
		return (write(2, "Error\n", 6), NULL);
	head = create_strcut(nums, ndx, h);
	if (!head)
		return (write(2, "Error\n", 6), NULL);
	enigma(head, h);
	return (NULL);
}

// This Function Allocates an array of integers that gets filled 
// using modified atoi where u give the address of the integer 
// fills it for u with the calculated integer and returns NULL 
// if Overfow Occured !

int	*build_int(char ***big, int h)
{
	int	*nums;
	int	a;
	int	i;
	int	o;

	a = 0;
	i = 0;
	o = 0;
	nums = ft_malloc(sizeof(int) * h);
	if (!nums)
		return (exit(-1), NULL);
	while (big[a])
	{
		while (big[a][i])
		{
			if (!ft_atoi(big[a][i++], &nums[o++]))
				return (write (2, "Error\n", 6),
					exit(-1), NULL);
		}
		i = 0;
		a++;
	}
	return (nums);
}

// for the sake of getting the indexes for each number  
// i have to look for the biggest number and
// then   index for it the size-- of the stack  and 
// settign for it's pointer NULL
// and looping through the integers 
// I did  *ptr[a] >= big so that in the last number it get it's index !

// THIS FUNCTION SUCCESSFULLY DO IT'S JOB
// INCLUDING IN TH CASE IF THERE WAS ONE NUMBER !
// also i did the ndx[0] in case it was one number other it will be 
// overwrited !

void	*index_job(int *nums, int h)
{
	int	**ptr;
	int	*ndx;

	ptr = link_address(nums, h);
	if (!ptr)
		return (NULL);
	ndx = ft_malloc(sizeof(int) * (h + 1));
	if (!ndx)
		return (NULL);
	ndx[0] = 0;
	complete(ndx, ptr, h, (h - 1));
	return (ndx);
}

// The function create the structs fills the index and locat
// and the number variables then links them !

t_unit	*create_strcut(int *nums, int *index, int h)
{
	int		a;
	t_unit	*rn;
	t_unit	*head;

	a = 1;
	rn = ft_lstnew(nums[0], index[0], 0);
	if (!rn)
		return (NULL);
	head = rn;
	while (a < h)
	{
		(*rn).next = ft_lstnew(nums[a], index[a], a);
		if (!((*rn).next))
			return (NULL);
		rn = (*rn).next;
		a++;
	}
	return (head);
}
