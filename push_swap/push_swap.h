/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:29:43 by djareno           #+#    #+#             */
/*   Updated: 2025/08/27 13:38:03 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>

void    sa(t_list *stackA);
void    sb(t_list *stackB);
void	ss(t_list *stackA, t_list *stackB);
void	pa(t_list **stackA, t_list **stackB);
void	pb(t_list **stackA, t_list **stackB);
void	ra(t_list **stackA);
void	rb(t_list **stackB);
void	rr(t_list **stackA, t_list **stackB);
void    rra(t_list **stackA);
void    rrb(t_list **stackB);
void    rrr(t_list **stackA, t_list **stackB);
void    divide_stacks(t_list **stackA, t_list **stackB);
#endif