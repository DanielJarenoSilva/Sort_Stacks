/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:29:40 by djareno           #+#    #+#             */
/*   Updated: 2025/09/11 12:36:44 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_arr(int *nums, int size)
{
	int	temp;
	int	sort;
	int	x;

	x = 0;
	sort = 1;
	while (sort == 1)
	{
		sort = 0;
		x = 0;
		while (x + 1 < size)
		{
			if (nums[x] > nums[x + 1])
			{
				temp = nums[x];
				nums[x] = nums[x + 1];
				nums[x + 1] = temp;
				sort = 1;
			}
			x++;
		}
	}
}

int	ft_checkarrnbr(char **arr, int size)
{
	int	x;
	int	y;
	int	n;
	int	n2;

	x = 1;
	while(x < size - 1)
	{
		if (ft_strisnum(arr[x]) == -1)
			return (-1);
		n = ft_atoi(arr[x]);
		y = x + 1;
		while (y <= size)
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

int	countBuff(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	*copy_arr(char	**arr1)
{
	int		i;
	int	*arr2;
	
	i = 0;
	arr2 = (int *)malloc(sizeof(int) * countBuff(arr1));
	while (arr1[i])
	{
		arr2[i] = ft_atoi(arr1[i]);
		i++;
	}
	return (arr2);
}

int	arr_to_stack(t_list **stackA, char **arr, int argc)
{	
	int		x;
	int		*num;
	int	*ordenados;
	t_list	*new;

	if(ft_checkarrnbr(arr, argc) == -1)
		return (-1);
	x = countBuff(arr); 
	ordenados = copy_arr(arr);
	sort_arr(ordenados, x);
	x = 0;
	while (arr[x] != NULL)
	{
		num = malloc(sizeof(int));
		if (!num)
			return (0);
		*num = ft_atoi(arr[x]);
		new = ft_lstnew(num);
		new->index = find_index(arr[x], ordenados);
		ft_lstadd_back(stackA, new);
		x++;
	}
	return (free(arr), 0);
}

int str_to_stack(t_list **stackA, char *str)
{
	char	**valores;
	int		x;
	int		*num;
	int		*ordenados;
	t_list	*new;


	valores = ft_split(str, ' ');
	if(ft_checkarrnbr(valores, 0) == -1)
		return (-1);
	x = countBuff(valores); 
	ordenados = copy_arr(valores);
	sort_arr(ordenados, x);
	x = 0;
	while (valores[x] != NULL)
	{
		num = malloc(sizeof(int));
		if (!num)
			return (0);
		*num = ft_atoi(valores[x]);
		new = ft_lstnew(num);
		new->index = find_index(valores[x], ordenados);
		ft_lstadd_back(stackA, new);
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
		{
			ft_putstr_fd("Error1\n", 2);
			return (0);
		}
	}
	else if (argc > 2)
	{
		if (arr_to_stack(&stackA, argv, argc) == -1)
			return (ft_putstr_fd("Error2\n", 2), 0);
	}
	/*ft_printf("%s\n", "StackA");
	ft_lstprintd(stackA);
	ft_printf("%s\n", "StackB");
	ft_lstprintd(stackB);*/
	ksort(&stackA, &stackB);
	/*ft_printf("%s\n", "StackA");
	ft_lstprintd(stackA);
	ft_printf("%s\n", "StackB");
	ft_lstprintd(stackB);*/
	return (0);
}