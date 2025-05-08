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
#include "../printf/ft_printf.h"

void	push_b(t_piles *pile, int bonus)
{
	int	i;

	if (pile->size_a == 0)
		return ;
	i = pile->size_b;
	while (i > 0)
	{
		pile->b[i] = pile->b[i - 1];
		i--;
	}
	pile->b[0] = pile->a[0];
	pile->size_b++;
	i = 0;
	while (i < pile->size_a - 1)
	{
		pile->a[i] = pile->a[i + 1];
		i++;
	}
	pile->size_a--;
	if (!bonus)
		ft_printf("pb\n");
}

void	push_a(t_piles *pile, int bonus)
{
	int	i;

	if (pile->size_b == 0)
		return ;
	i = pile->size_a;
	while (i > 0)
	{
		pile->a[i] = pile->a[i - 1];
		i--;
	}
	pile->a[0] = pile->b[0];
	pile->size_a++;
	i = 0;
	while (i < pile->size_b - 1)
	{
		pile->b[i] = pile->b[i + 1];
		i++;
	}
	pile->size_b--;
	if (!bonus)
		ft_printf("pa\n");
}
