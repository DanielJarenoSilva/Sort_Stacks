/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:48:02 by djareno           #+#    #+#             */
/*   Updated: 2025/08/28 15:07:31 by djareno          ###   ########.fr       */
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
	//ft_printf("min: %d\nmax %d\nmid: %d\n", min, max, mid);
	while (1)
	{
		if (minF == 2)
			break;
		if (*(int *)(*stackA)->content == min)
		{
			minF++;
			ra(stackA);
		}
		else if (*(int *)(*stackA)->content <= mid)
			ra(stackA);
		else if (*(int *)(*stackA)->content >= mid)
		{
			if (*(int *)(*stackA)->content == max)
			{
				pb(stackA, stackB);
				rb(stackB);
			}
			else
				pb(stackA, stackB);
		}
	}
	while (1)
	{
		if (*(int *)(*stackA)->content == min)
		{
			if (sortedStack(stackA) == 0)
				break;
			ra(stackA);
		}
		else if (*(int *)(*stackA)->content > *(int *)(*stackA)->next->content)
		{
			if(*(int *)(*stackA)->next->content == min)
				ra(stackA);
			else
				sa(*stackA);
		}
		else if (*(int *)(*stackA)->content < *(int *)(*stackA)->next->content)
			ra(stackA);
	}
	ft_printf("B%d\n", *(int *)(*stackB)->content);
	while (1)
	{
		if (*(int *)(*stackB)->content == max)
		{
			rb(stackB);
			if (sortedStack(stackB) == 0)
				break;
		}
		else if (*(int *)(*stackB)->content < *(int *)(*stackB)->next->content)
		{
			rb(stackB);
		}
		else if (*(int *)(*stackB)->content > *(int *)(*stackB)->next->content)
			sb(*stackB);
	}
	while (*stackB)
	{
		pa(stackA,stackB);
		ra(stackA);
	}
}
/*while (1)
	{
		if (*(int *)(*stackA)->content == min)
		{
			if (rempty == 1)
			{
				pa(stackA,stackB);
				ra(stackA);
			}
			rempty = 0;
			if (sortedStack(stackA) == 0)
				break;
			ra(stackA);
		}
		else if (*(int *)(*stackA)->content > *(int *)(*stackA)->next->content)
		{
			if (rempty == 0)
			{
				pb(stackA, stackB);
				rempty = 1;
			}
			else if (*(int *)(*stackA)->content > *(int *)(*stackB)->content)
			{
				pa(stackA, stackB);
				sa(*stackA);
				pb(stackA, stackB);	
			} else
				ra(stackA);
		}
		else if (*(int *)(*stackA)->content < *(int *)(*stackA)->next->content)
				ra(stackA);
	}

	while (1)
	{
		if (*(int *)(*stackB)->content == max)
		{
			if (rempty == 1)
			{
				pb(stackA,stackB);
				rb(stackB);
			}
			rempty = 0;
			rb(stackB);
			if (sortedStack(stackB) == 0)
				break;
		}
		else if (*(int *)(*stackB)->content > *(int *)(*stackB)->next->content)
		{
			if (rempty == 0)
			{
				pa(stackA, stackB);
				rempty = 1;
			}
			else if (*(int *)(*stackB)->content > *(int *)(*stackA)->content)
			{
				pb(stackA, stackB);
				sb(*stackB);
				pa(stackA, stackB);	
			} else
				rb(stackB);
		}
		else if (*(int *)(*stackB)->content < *(int *)(*stackB)->next->content)
				rb(stackB);
	}
	t_tmp = *stackB;
	while (*stackB)
	{
		pa(stackA,stackB);
		ra(stackA);
	}
	*/
