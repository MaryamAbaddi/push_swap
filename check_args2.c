/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaddi <mabaddi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:03:09 by mabaddi           #+#    #+#             */
/*   Updated: 2026/02/02 14:50:32 by mabaddi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	parse_number(const char *str, int *i, int *overflow)
{
	long	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (result > (LONG_MAX - (str[*i] - '0')) / 10)
		{
			*overflow = 1;
			return (0);
		}
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

long	ft_atol(const char *str, int *overflow)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	*overflow = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		*overflow = 1;
	result = parse_number(str, &i, overflow);
	return (result * sign);
}

static int	check_one_arg(char **args, int i)
{
	long	tmp;
	int		overflow;

	if (!ft_isnum(args[i]))
		return (-1);
	overflow = 0;
	tmp = ft_atol(args[i], &overflow);
	if (overflow || tmp < INT_MIN || tmp > INT_MAX)
		return (-1);
	if (ft_contains(tmp, args, i))
		return (-1);
	return (1);
}

static void	check_all_args(char **args, int i)
{
	while (args[i])
	{
		if (check_one_arg(args, i) == -1)
			ft_error("Error");
		i++;
	}
}

void	check_args(int ac, char **av)
{
	int		i;
	char	**args;

	args = av;
	i = 1;
	check_all_args(args, i);
	if (ac == 2)
		ft_free(args);
}
