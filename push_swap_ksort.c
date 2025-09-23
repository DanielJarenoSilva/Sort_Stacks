/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ksort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:44:33 by djareno           #+#    #+#             */
/*   Updated: 2025/09/23 10:23:28 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_or_rotate(t_list **a, t_list **b, int chunk, int prev_chunk)
{
	if ((*a)->index < ((chunk + prev_chunk) / 2))
		pb(a, b);
	else
	{
		pb(a, b);
		rb(b);
	}
}

static void	push_chunks(t_list **a, t_list **b, int max, int chunks)
{
	int	chunk;
	int	prev_chunk;
	int	i;
	int	y;

	i = 1;
	y = 0;
	prev_chunk = 0;
	while (*a)
	{
		chunk = (max + 1) * i / chunks;
		if ((*a)->index <= chunk)
		{
			y++;
			push_or_rotate(a, b, chunk, prev_chunk);
		}
		else
			ra(a);
		if (y == chunk)
		{
			prev_chunk = chunk;
			i++;
		}
	}
}

static void	rebuild_stack(t_list **stackA, t_list **stackB, int max)
{
	int	y;

	while (*stackB)
	{
		y = find_num_stack(stackB, max);
		if (y < get_max(stackB) / 2)
		{
			while ((*stackB)->index != max)
				rb(stackB);
		}
		else
		{
			while ((*stackB)->index != max)
				rrb(stackB);
		}
		pa(stackA, stackB);
		max--;
	}
}

void	ksort(t_list **a, t_list **b)
{
	int	max;

	max = get_max(a);
	push_chunks(a, b, max, ft_sqrt(max + 1));
	rebuild_stack(a, b, max);
}

int	check_num_repeated(int *nums, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j< size)
		{
			if (nums[i] == nums[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}