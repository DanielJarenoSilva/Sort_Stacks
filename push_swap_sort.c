/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:53:05 by djareno           #+#    #+#             */
/*   Updated: 2025/09/23 11:22:38 by djareno          ###   ########.fr       */
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

void	sort3(t_list **stacka)
{
	if ((*stacka)->index == 2)
	{
		ra(stacka);
	}
	else if ((*stacka)->next->index == 2)
	{
		rra(stacka);
	}
	if ((*stacka)->index > (*stacka)->next->index)
	{
		sa(*stacka);
	}
}

void	sort4(t_list **stacka, t_list **stackb)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if ((*stacka)->index == 0)
		{
			pb(stacka, stackb);
			i++;
		}
		else
			ra(stacka);
	}
	sort3(stacka);
	pa(stacka, stackb);
}

void	sort5(t_list **stacka, t_list **stackb)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((*stacka)->index == 0 || (*stacka)->index == 1)
		{
			pb(stacka, stackb);
			i++;
		}
		else
			ra(stacka);
	}
	sort3(stacka);
	pa(stacka, stackb);
	pa(stacka, stackb);
	if ((*stacka)->index > (*stacka)->next->index)
		sa(*stacka);
}

void	sort(t_list **stacka, t_list **stackb)
{
	int	max;

	max = get_max(stacka);
	if (max == 1)
	{
		if ((*stacka)->index > (*stacka)->next->index)
			sa(*stacka);
	}
	else if (max == 2)
		sort3(stacka);
	else if (max == 0)
		return ;
	else if (max == 4)
		sort5(stacka, stackb);
	else if (max == 3)
		sort4(stacka, stackb);
	else
		ksort(stacka, stackb);
}
