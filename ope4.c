/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryouum <maryouum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:42:26 by mabaddi           #+#    #+#             */
/*   Updated: 2026/02/02 09:36:28 by maryouum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverserotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!*stack || !(*stack)->next)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head->next != tail)
		head = head->next;
	head->next = NULL;
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_list **stacka)
{
	if (reverserotate(stacka) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stackb)
{
	if (reverserotate(stackb) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **stacka, t_list **stackb)
{
	if ((ft_lstsize(*stacka) < 2) || (ft_lstsize(*stackb) < 2))
		return (-1);
	reverserotate(stacka);
	reverserotate(stackb);
	ft_putendl_fd("rrr", 1);
	return (0);
}
