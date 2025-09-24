/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:55:55 by djareno           #+#    #+#             */
/*   Updated: 2025/09/24 10:15:32 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortedstack(t_list **stack)
{
	t_list	*t_temp;

	t_temp = *stack;
	while (t_temp)
	{
		if (t_temp->next != NULL)
		{
			if (*(int *)t_temp->content > *(int *)t_temp->next->content)
			{
				return (1);
			}
			t_temp = t_temp->next;
		}
		else
			break ;
	}
	return (0);
}

int	get_max(t_list **stack)
{
	int		max;
	t_list	*t_temp;

	max = 0;
	t_temp = *stack;
	while (t_temp)
	{
		if (t_temp->index > max)
			max = t_temp->index;
		t_temp = t_temp->next;
	}
	return (max);
}

int	find_index(int num, int *nums)
{
	int	x;

	x = 0;
	while (nums[x] != num)
		x++;
	return (x);
}

int	ft_atoi_ps(const char *n)
{
	int	x;
	int	signo;
	int	num;

	num = 0;
	x = 0;
	signo = 1;
	while (*n == 32 || (*n >= 9 && *n <= 13))
		n++;
	if (*n == '-')
		signo *= -1;
	if (*n == '+' || *n == '-')
		n++;
	while (*n >= '0' && *n <= '9')
	{
		num = num * 10 + (n[x] - '0');
		n++;
	}
	num *= signo;
	if (num >= 2147483647 || num <= -2147483648)
		ft_putstr_fd("Error\n", 2);
	return (num * signo);
}

int	check_sorted_stack(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp->next->next)
	{
		if (temp->index > temp->next->index)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}
