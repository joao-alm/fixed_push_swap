/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdian <yaabdian@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:49:16 by yaabdian          #+#    #+#             */
/*   Updated: 2025/05/08 20:54:31 by yaabdian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"
#include "../printf/ft_printf.h"
#include <stdlib.h>

void	push_swap(char **av)
{
	t_piles	pile;
	int		size;
	int		i;

	i = -1;
	size = push_swap_strlen(av);
	pile.a = malloc(size * sizeof(int));
	if (!pile.a)
		return ;
	pile.size_a = size;
	pile.b = malloc(size * sizeof(int));
	if (!pile.b)
	{
		free(pile.a);
		return ;
	}
	pile.size_b = 0;
	while (++i < size)
		pile.a[i] = push_swap_atoi(av[i], pile.a);
	check_doubles(pile.a, size);
	sort(&pile, size);
	free(pile.a);
	free(pile.b);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		push_swap(av);
		if (ac == 2)
		{
			i = 0;
			while (av[i])
				free(av[i++]);
			free(av);
		}
		return (0);
	}
	return (0);
}
