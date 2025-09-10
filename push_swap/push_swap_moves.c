/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:01:37 by djareno           #+#    #+#             */
/*   Updated: 2025/09/10 10:45:17 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list *stackA)
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

void    sb(t_list *stackB)
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

void	ss(t_list *stackA, t_list *stackB)
{
	sa(stackA);
	sb(stackB);
	ft_printf("%s\n", "ss");
}

void	pa(t_list **stackA, t_list **stackB)
{
	t_list	*t_temp;

	if(!stackB || !*stackB)
		return ;
	t_temp = *stackB;
	*stackB = (*stackB)->next;
	ft_lstadd_front(stackA, t_temp);
	ft_printf("%s\n", "pa");
}
void	pb(t_list **stackA, t_list **stackB)
{
	t_list	*t_temp;

	if(!stackA || !*stackA)
		return ;
	t_temp = *stackA;
	*stackA = (*stackA)->next;
	ft_lstadd_front(stackB, t_temp);
	ft_printf("%s\n", "pb");
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

void	rb(t_list **stackB)
{
	t_list	*t_temp;

	t_temp = *stackB;
	*stackB = (*stackB)->next;
	t_temp->next = NULL;
	ft_lstadd_back(stackB, t_temp);
	ft_printf("%s\n", "rb");
}

void	rr(t_list **stackA, t_list **stackB)
{
	ra(stackA);
	rb(stackB);
	ft_printf("%s\n", "rr");
}

void rra(t_list **stackA)
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

void	rrr(t_list **stackA, t_list **stackB)
{
	rra(stackA);
	rrb(stackB);
	ft_printf("%s\n", "rrr");
}