/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:53:05 by djareno           #+#    #+#             */
/*   Updated: 2025/09/22 14:45:36 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_num_stack(t_list **stack, int num)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->index != num)
		{
			temp = temp->next;
			i++;
		}
		else
			return (i);
	}
	return (i);
}

void	sort3(t_list **stackA)
{
	if ((*stackA)->index == 2)
	{
		ra(stackA);
	}
	else if ((*stackA)->next->index == 2)
	{
		rra(stackA);
	}
	if ((*stackA)->index > (*stackA)->next->index)
	{
		sa(*stackA);
	}
}

void	sort5(t_list **stackA, t_list **stackB)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*stackA)->index == 0 || (*stackA)->index == 1)
		{
			pb(stackA, stackB);
			i++;
		}
		else
			ra(stackA);
	}
	sort3(stackA);
	pa(stackA, stackB);
	pa(stackA, stackB);
	if ((*stackA)->index > (*stackA)->next->index)
		sa(*stackA);
}

void	sort(t_list **stackA, t_list **stackB)
{
	int	max;

	max = get_max(stackA);
	if (max == 1)
	{
		if ((*stackA)->index > (*stackA)->next->index)
			sa(*stackA);
	}
	else if (max == 2)
	{
		sort3(stackA);
	}
	else if (max == 0)
	{
		return ;
	}
	else if (max == 4)
	{
		sort5(stackA, stackB);
	}
	else
		ksort(stackA, stackB);
}
