/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryouum <maryouum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:07:46 by maryouum          #+#    #+#             */
/*   Updated: 2026/02/02 10:10:13 by maryouum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stacka, t_list **stackb)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;
	t_list	*head_a;

	i = 0;
	head_a = *stacka;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stacka);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stacka;
			if (((head_a->index >> i) & 1) == 1)
				ra(stacka);
			else
				pb(stacka, stackb);
		}
		while (ft_lstsize(*stackb) != 0)
			pa(stacka, stackb);
		i++;
	}
}
