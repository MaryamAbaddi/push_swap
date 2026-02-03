/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaddi <mabaddi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:40:16 by mabaddi           #+#    #+#             */
/*   Updated: 2026/02/02 15:41:34 by mabaddi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_stack(t_list **stack, char **args, int i)
{
	t_list	*new;
	int		overflow;
	long	value;

	while (args[i])
	{
		overflow = 0;
		value = ft_atol(args[i], &overflow);
		if (overflow)
			ft_error("Error");
		new = ft_lstnew((int)value);
		if (!new)
			return (-1);
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	return (1);
}

static int	init(t_list **stack, char **argv)
{
	char	**args;
	int		i;

	args = argv;
	i = 1;
	if (fill_stack(stack, args, i) == -1)
	{
		free_stack(stack);
		return (-1);
	}
	return (1);
}

static void	sort_stack(t_list **stacka, t_list **stackb)
{
	if (ft_lstsize(*stacka) <= 5)
		simple_sort(stacka, stackb);
	else
		radix_sort(stacka, stackb);
}

static int	init_stacks(t_list ***stacka, t_list ***stackb)
{
	*stacka = malloc(sizeof(**stacka));
	if (!*stacka)
		return (1);
	*stackb = malloc(sizeof(**stackb));
	if (!*stackb)
	{
		free(*stacka);
		return (1);
	}
	**stacka = NULL;
	**stackb = NULL;
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	**stacka;
	t_list	**stackb;

	if (argc <= 2)
		return (0);
	check_args(argc, argv);
	if (init_stacks(&stacka, &stackb))
		return (1);
	if (init(stacka, argv) == -1)
	{
		free_stack(stackb);
		return (1);
	}
	if (is_sorted(stacka))
	{
		free_stack(stacka);
		free_stack(stackb);
		return (0);
	}
	sort_stack(stacka, stackb);
	free_stack(stacka);
	free_stack(stackb);
	return (0);
}
