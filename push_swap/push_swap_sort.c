/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:53:05 by djareno           #+#    #+#             */
/*   Updated: 2025/09/10 10:49:59 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ksort(t_list **stackA, t_list **stackB)
{
	int	max;
	/*int	k;
	int	x;
	int	midC;

	
	k = 10;
	midC = 0;
	x = 1;*/
	ft_lstprintd(*stackB);
	max = get_max(stackA);
	ft_printf("%d", max);
}