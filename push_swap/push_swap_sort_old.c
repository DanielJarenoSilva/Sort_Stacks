/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:48:02 by djareno           #+#    #+#             */
/*   Updated: 2025/09/04 13:04:24 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_quarter(t_list **stackA, t_list **stackB, int min, int max, int qt)
{
	int	contQ;
	int	contR;
	int x;

	x = 0;
	contQ = 0;
	contR = 0;
	qt = max * qt / 20;
	while (1)
	{
		if (*(int *)(*stackB)->content < qt)
		{
			pa(stackA, stackB);
			contQ++;
		}
		else
		{
			if ( *(int *)(*stackB)->content == max)
			{
				rb(stackB);
				break ;
			}
			rb(stackB);
		}
	}
	while (1)
	{
		if (sortedStack(stackA) == 0)
			break ;
		if (contR == contQ)
		{
			while (x < contQ)
			{
				rra(stackA);
				x++;
			}
			contR = 0;
		}
		if (*(int *)(*stackA)->next->content != min && *(int *)(*stackA)->content > *(int *)(*stackA)->next->content)
			sa(*stackA);
		else if (*(int *)(*stackA)->next->content != min && *(int *)(*stackA)->content < *(int *)(*stackA)->next->content)
		{
			ra(stackA);
			contR++;
		}
		else if (*(int *)(*stackA)->next->content == min)
		{
			ra(stackA);
			contR++;
		}
	}
}
void	f_sort(t_list **stackA, t_list **stackB, int min, int max)
{
	int	x;
	x = 1;
	while (x < 20)
	{
		sort_quarter(stackA, stackB, min, max, x);
		x++;
	}
}

void	divide_stacks(t_list **stackA, t_list **stackB)
{
	int		max;
	int		min;
	int		quarter;
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
	quarter = max / 20;
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
		else if (*(int *)(*stackA)->content <= quarter)
			ra(stackA);
		else if (*(int *)(*stackA)->content >= quarter)
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
	f_sort(stackA, stackB, min, max);
}