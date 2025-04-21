/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mir <sel-mir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:19:41 by sel-mir           #+#    #+#             */
/*   Updated: 2025/03/15 06:01:12 by sel-mir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Helpers/pushswap.h"

t_unit	*pushswap(int ac, char **av)
{
	if (ac == 1)
		exit(1);
	if (sanitize_it(ac, av) == -1)
		flussh();
	build_it(ac, av);
	return (NULL);
}

int	main(int ac, char **av)
{
	pushswap(ac, av);
	free_alloc(NULL, 1);
}
