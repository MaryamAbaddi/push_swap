/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaddi <mabaddi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:45:00 by mabaddi           #+#    #+#             */
/*   Updated: 2026/02/01 19:07:17 by mabaddi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_case1(t_list **stacka, int min, int next_min)
{
	t_list	*start;

	start = *stacka;
	if (start->index == min && start->next->index != next_min)
	{
		ra(stacka);
		sa(stacka);
		rra(stacka);
	}
	else if (start->index == next_min)
	{
		if (start->next->index == min)
			sa(stacka);
		else
			rra(stacka);
	}
}

static void	sort_3_case2(t_list **stacka, int min)
{
	t_list	*start;

	start = *stacka;
	if (start->next->index == min)
		ra(stacka);
	else
	{
		sa(stacka);
		rra(stacka);
	}
}

void	sort_3(t_list **stacka)
{
	int	start_min;
	int	next_min;

	if (is_sorted(stacka))
		return ;
	start_min = get_min(stacka, -1);
	next_min = get_min(stacka, start_min);
	if ((*stacka)->index == start_min || (*stacka)->index == next_min)
		sort_3_case1(stacka, start_min, next_min);
	else
		sort_3_case2(stacka, start_min);
}
