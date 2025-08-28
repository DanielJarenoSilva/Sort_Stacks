/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:29:40 by djareno           #+#    #+#             */
/*   Updated: 2025/08/28 15:08:07 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkarrnbr(char **arr)
{
	int	x;
	int	y;
	int	n;
	int	n2;

	x = 0;
	while(arr[x] != NULL)
	{
		if (ft_strisnum(arr[x]) == -1)
			return (-1);
		y = x + 1;
		n = ft_atoi(arr[x]);
		while (arr[y] != NULL)
		{
			if (ft_strisnum(arr[y]) == -1)
				return (-1);
			n2 = ft_atoi(arr[y]);
			if (n == n2)
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}

int	arr_to_stack(t_list **stackA, char **arr)
{
	int		x;
	int		*num;

	x = 1;
	if(ft_checkarrnbr(arr) == -1)
		return (-1);
	while (arr[x] != NULL)
	{
		num = malloc(sizeof(int));
		if (!num)
			return (-1);
		*num = ft_atoi(arr[x]);
		ft_lstadd_back(stackA, ft_lstnew(num));
		x++;
	}
	return (0);
}

int str_to_stack(t_list **stackA, char *str)
{
	char **valores;
	int		x;
	int		*num;

	x = 0;
	valores = ft_split(str, ' ');
	if(ft_checkarrnbr(valores) == -1)
		return (-1);
	while (valores[x] != NULL)
	{
		num = malloc(sizeof(int));
		if (!num)
			return (0);
		*num = ft_atoi(valores[x]);
		ft_lstadd_back(stackA, ft_lstnew(num));
		free(valores[x]);
		x++;
	}
	free(valores);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*stackA = NULL;
	t_list	*stackB = NULL;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		if (str_to_stack(&stackA, argv[1]) == -1)
			return (ft_putstr_fd("Error\n", 2), 0);
	}
	else if (argc > 2)
	{
		if (arr_to_stack(&stackA, argv) == -1)
			return (ft_putstr_fd("Error\n", 2), 0);
	}
	/*ft_printf("%s\n", "StackA");
	ft_lstprintd(stackA);
	ft_printf("%s\n", "StackB");
	ft_lstprintd(stackB);*/
	divide_stacks(&stackA, &stackB);
	/*ft_printf("%s\n", "StackA");
	ft_lstprintd(stackA);
	ft_printf("%s\n", "StackB");
	ft_lstprintd(stackB);*/
	return (0);
}