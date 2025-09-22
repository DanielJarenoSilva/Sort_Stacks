/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:22:57 by djareno           #+#    #+#             */
/*   Updated: 2025/09/22 16:06:14 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_arr(int *nums, int size)
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

int	*copy_arr(int *arr, int size)
{
	int		i;
	int		*arr2;

	i = 0;
	arr2 = (int *)malloc(sizeof(int) * size);
	while (i < size)
	{
		arr2[i] = arr[i];
		i++;
	}
	return (arr2);
}

int	*arr_to_int(char **str, int size, int type)
{
	int	*nums;
	int	i;

	nums = malloc(size * sizeof(int));
	if (nums == NULL)
		return (NULL);
	i = 0;
	if (type == 1)
	{
		i = 1;
		size++;
	}
	while (i < size)
	{
		if (ft_strisnum(str[i]) == -1)
			return (free(nums), NULL);
		if (type == 1)
			nums[i - 1] = ft_atoi_ps(str[i]);
		else
			nums[i] = ft_atoi(str[i]);
		i++;
	}
	return (nums);
}

int	arrlen(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	*str_to_int(char *str, int size)
{
	char	**strs;
	int		*nums;

	strs = ft_split(str, ' ');
	nums = arr_to_int(strs, size, 0);
	if (nums == NULL)
		return (NULL);
	return (nums);
}
