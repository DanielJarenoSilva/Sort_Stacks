/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:55:55 by djareno           #+#    #+#             */
/*   Updated: 2025/09/10 13:34:03 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sortedStack(t_list **stack)
{
    t_list  *t_temp;

    t_temp = *stack;
    while (t_temp)
    {
        if(t_temp->next != NULL)
        {
            if (*(int *)t_temp->content > *(int *)t_temp->next->content)
			{
        		return (1);
			}
        	t_temp = t_temp->next;
        }
		else
			break;
    }
    return (0);
}

int get_max(t_list **stack)
{
	int		max;
	t_list	*t_temp;

	max = 0;
	t_temp = *stack;
	while (t_temp)
	{
		if (*(int *)t_temp->content > max)
			max = t_temp->index;
		t_temp = t_temp->next;
	}
	return (max);
}
int	find_index(char *num, int *nums)
{
	int	x;

	x = 0;
	while (nums[x] != ft_atoi(num))
		x++;
	return (x);
}