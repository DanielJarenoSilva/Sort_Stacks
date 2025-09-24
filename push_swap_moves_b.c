/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:05:08 by djareno           #+#    #+#             */
/*   Updated: 2025/09/24 09:51:59 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list *stackB)
{
	int		*temp;
	int		*temp2;
	t_list	*t_temp;

	temp = stackB->content;
	t_temp = stackB;
	stackB = stackB->next;
	temp2 = stackB->content;
	stackB->content = temp;
	stackB = t_temp;
	stackB->content = temp2;
	ft_printf("%s\n", "sb");
}

void	pb(t_list **stackA, t_list **stackB)
{
	t_list	*t_temp;

	if (!stackA || !*stackA)
		return ;
	t_temp = *stackA;
	*stackA = (*stackA)->next;
	ft_lstadd_front(stackB, t_temp);
	ft_printf("%s\n", "pb");
}

void	rb(t_list **stackB)
{
	t_list	*t_temp;

	t_temp = *stackB;
	*stackB = (*stackB)->next;
	t_temp->next = NULL;
	ft_lstadd_back(stackB, t_temp);
	ft_printf("%s\n", "rb");
}

void	rrb(t_list **stackB)
{
	t_list	*prev;
	t_list	*last;

	prev = NULL;
	last = *stackB;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	ft_lstadd_front(stackB, last);
	ft_printf("%s\n", "rrb");
}
