/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:29:43 by djareno           #+#    #+#             */
/*   Updated: 2025/09/24 10:16:03 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>

void	sa(t_list *stackA);
void	sb(t_list *stackB);
void	ss(t_list *stackA, t_list *stackB);
void	pa(t_list **stackA, t_list **stackB);
void	pb(t_list **stackA, t_list **stackB);
void	ra(t_list **stackA);
void	rb(t_list **stackB);
void	rr(t_list **stackA, t_list **stackB);
void	rra(t_list **stackA);
void	rrb(t_list **stackB);
void	rrr(t_list **stackA, t_list **stackB);
void	free_stacks(t_list **stack);
int		get_max(t_list **stack);
void	ksort(t_list **stackA, t_list **stackB);
int		sortedstack(t_list **stack);
int		find_index(int num, int *nums);
void	sort(t_list **stackA, t_list **stackB);
int		ft_atoi_ps(const char *n);
int		*str_to_int(char *str, int size);
int		arrlen(char	**str);
int		*arr_to_int(char **str, int size, int type);
int		*copy_arr(int *arr, int size);
void	sort_arr(int *nums, int size);
void	ksort(t_list **a, t_list **b);
int		find_num_stack(t_list **stack, int num);
int		check_num_repeated(int *nums, int size);
int		check_sorted_stack(t_list *stack);
#endif