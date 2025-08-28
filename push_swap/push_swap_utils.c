/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 12:55:55 by djareno           #+#    #+#             */
/*   Updated: 2025/08/28 14:56:57 by djareno          ###   ########.fr       */
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