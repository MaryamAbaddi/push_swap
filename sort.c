/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaddi <mabaddi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:41:32 by mabaddi           #+#    #+#             */
/*   Updated: 2026/02/01 19:02:51 by mabaddi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

static void	sort_4(t_list **stacka, t_list **stackb)
{
	int	distance;

	if (is_sorted(stacka))
		return ;
	distance = get_distance(stacka, get_min(stacka, -1));
	if (distance == 1)
		ra(stacka);
	else if (distance == 2)
	{
		ra(stacka);
		ra(stacka);
	}
	else if (distance == 3)
		rra(stacka);
	if (is_sorted(stacka))
		return ;
	pb(stacka, stackb);
	sort_3(stacka);
	pa(stacka, stackb);
}

void	sort_5(t_list **stacka, t_list **stackb)
{
	int	distance;

	distance = get_distance(stacka, get_min(stacka, -1));
	if (distance == 1)
		ra(stacka);
	else if (distance == 2)
	{
		ra(stacka);
		ra(stacka);
	}
	else if (distance == 3)
	{
		rra(stacka);
		rra(stacka);
	}
	else if (distance == 4)
		rra(stacka);
	if (is_sorted(stacka))
		return ;
	pb(stacka, stackb);
	sort_4(stacka, stackb);
	pa(stacka, stackb);
}

void	simple_sort(t_list **stacka, t_list **stackb)
{
	int	size;

	if (is_sorted(stacka) || ft_lstsize(*stacka) == 0
		|| ft_lstsize(*stacka) == 1)
		return ;
	size = ft_lstsize(*stacka);
	if (size == 2)
		sa(stacka);
	else if (size == 3)
		sort_3(stacka);
	else if (size == 4)
		sort_4(stacka, stackb);
	else if (size == 5)
		sort_5(stacka, stackb);
}
