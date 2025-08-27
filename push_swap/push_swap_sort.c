/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:48:02 by djareno           #+#    #+#             */
/*   Updated: 2025/08/27 13:41:20 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_stacks(t_list **stackA, t_list **stackB)
{
	int		max;
	int		min;
	int		mid;
	int		minF;
	t_list	*t_tmp;

	t_tmp = *stackA;
	max = 0;
	minF = 0;
	min = *(int *)t_tmp->content;
	while (t_tmp)
	{
		if (*(int *)t_tmp->content < min)
			min = *(int *)t_tmp->content;
		if (*(int *)t_tmp->content > max)
			max = *(int *)t_tmp->content;
		t_tmp = t_tmp->next;
	}
	mid = max / 2;
	t_tmp = *stackA;
	ft_printf("min: %d\nmax %d\nmid: %d\n", min, max, mid);
	while (1)
	{
		if (minF == 2)
			break;
		if (*(int *)(*stackA)->content == min)
		{
			minF++;
			printf("%d\n", *(int *)(*stackA)->content);
			ra(stackA);
		}
		else if (*(int *)(*stackA)->content <= mid)
		{
			printf("%d\n", *(int *)(*stackA)->content);
			ra(stackA);
		}
		else if (*(int *)(*stackA)->content >= mid)
		{
			//printf("%d\n", *(int *)(*stackA)->content);
			pb(stackA, stackB);
		}
	}
}