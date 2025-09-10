/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:53:05 by djareno           #+#    #+#             */
/*   Updated: 2025/09/10 16:11:35 by djareno          ###   ########.fr       */
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

void	ksort(t_list **stackA, t_list **stackB)
{
	int	max;
	int	chunk;
	int	chunks;
	int p_chunk;
	int	i;
	int	y;

	i = 1;
	y = 0;
	p_chunk = 0;
	max = get_max(stackA);
	chunks = ft_sqrt(max + 1);
	while (*stackA)
	{
		chunk = (max + 1) * i / chunks;
		if ((*stackA)->index <= chunk)
		{
			y++;
			if ((*stackA)->index < ((chunk + p_chunk) / 2))
				pb(stackA, stackB);
			else
			{
				pb(stackA,stackB);
				rb(stackB);
			}			
		}
		else
			ra(stackA);
		if (y == chunk)
		{
			p_chunk = chunk;
			i++;
		}

	}
	i = max;
	while (*stackB)
	{
		y = find_num_stack(stackB, i);
		if (y < get_max(stackB) / 2)
		{
			while ((*stackB)->index != i)
				rb(stackB);
			pa(stackA, stackB);
			i--;
		}
		else if (y >= get_max(stackB) / 2)
		{
			while ((*stackB)->index != i)
				rrb(stackB);
			pa(stackA, stackB);
			i--;
		}
		
	}
}
