/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:07:20 by djareno           #+#    #+#             */
/*   Updated: 2025/09/24 09:52:53 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stackA)
{
	int		*temp;
	int		*temp2;
	t_list	*t_temp;

	temp = stackA->content;
	t_temp = stackA;
	stackA = stackA->next;
	temp2 = stackA->content;
	stackA->content = temp;
	stackA = t_temp;
	stackA->content = temp2;
	ft_printf("%s\n", "sa");
}

void	pa(t_list **stackA, t_list **stackB)
{
	t_list	*t_temp;

	if (!stackB || !*stackB)
		return ;
	t_temp = *stackB;
	*stackB = (*stackB)->next;
	ft_lstadd_front(stackA, t_temp);
	ft_printf("%s\n", "pa");
}

void	ra(t_list **stackA)
{
	t_list	*t_temp;

	t_temp = *stackA;
	*stackA = (*stackA)->next;
	t_temp->next = NULL;
	ft_lstadd_back(stackA, t_temp);
	ft_printf("%s\n", "ra");
}

void	rra(t_list **stackA)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	last = *stackA;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	ft_lstadd_front(stackA, last);
	ft_printf("%s\n", "rra");
}
