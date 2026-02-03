/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaddi <mabaddi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:41:08 by mabaddi           #+#    #+#             */
/*   Updated: 2026/02/02 14:54:56 by mabaddi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_contains(long num, char **argv, int i)
{
	int		overflow;
	long	tmp;

	i++;
	while (argv[i])
	{
		overflow = 0;
		tmp = ft_atol(argv[i], &overflow);
		if (!overflow && tmp == num)
			return (1);
		i++;
	}
	return (0);
}
