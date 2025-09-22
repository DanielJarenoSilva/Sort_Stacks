/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:29:40 by djareno           #+#    #+#             */
/*   Updated: 2025/09/22 16:24:48 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*to_stack(t_list *stack, int *nums, int size)
{
	int		*sortedarr;
	int		i;
	t_list	*new;
	int		*num;

	i = 0;
	sortedarr = copy_arr(nums, size);
	sort_arr(sortedarr, size);
	while (i < size)
	{
		num = malloc(sizeof(int));
		if (!num)
			return (NULL);
		*num = nums[i];
		new = ft_lstnew(num);
		new->index = find_index(nums[i], sortedarr);
		ft_lstadd_back(&stack, new);
		i++;
	}
	free(sortedarr);
	return (stack);
}

int	strsize(char *str)
{
	char	**strs;

	strs = ft_split(str, ' ');
	return (arrlen(strs));
}

int	checkargs(t_list *stacka, t_list *stackb, int argc, char *argv[])
{
	int		size;
	int		*stackint;

	stackint = NULL;
	size = 0;
	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		size = strsize(argv[1]);
		stackint = str_to_int(argv[1], size);
		if (stackint == NULL)
			return (ft_putstr_fd("Error\n", 2), 0);
	}
	else if (argc > 2)
	{
		size = argc - 1;
		stackint = arr_to_int(argv, size, 1);
		if (stackint == NULL)
			return (ft_putstr_fd("Error\n", 2), 0);
	}
	stacka = to_stack(stacka, stackint, size);
	sort(&stacka, &stackb);
	free(stackint);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	checkargs(stacka, stackb, argc, argv);
	free_stacks(&stacka);
	free_stacks(&stackb);
}
