/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:01:37 by djareno           #+#    #+#             */
/*   Updated: 2025/09/24 09:53:10 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list *stackA, t_list *stackB)
{
	sa(stackA);
	sb(stackB);
	ft_printf("%s\n", "ss");
}

void	rr(t_list **stackA, t_list **stackB)
{
	ra(stackA);
	rb(stackB);
	ft_printf("%s\n", "rr");
}

void	rrr(t_list **stackA, t_list **stackB)
{
	rra(stackA);
	rrb(stackB);
	ft_printf("%s\n", "rrr");
}
