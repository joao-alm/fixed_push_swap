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

void	swap_a(t_piles *pile, int bonus)
{
	int	tmp;

	if (pile->size_a < 2)
		return ;
	tmp = pile->a[0];
	pile->a[0] = pile->a[1];
	pile->a[1] = tmp;
	if (!bonus)
		ft_printf("sa\n");
}

void	swap_b(t_piles *pile, int bonus)
{
	int	tmp;

	if (pile->size_b < 2)
		return ;
	tmp = pile->b[0];
	pile->b[0] = pile->b[1];
	pile->b[1] = tmp;
	if (!bonus)
		ft_printf("sb\n");
}

void	swap_s(t_piles *pile, int bonus)
{
	int	tmp;

	if (pile->size_a < 2 && pile->size_b < 2)
		return ;
	if (pile->size_a > 1)
	{
		tmp = pile->a[0];
		pile->a[0] = pile->a[1];
		pile->a[1] = tmp;
	}
	if (pile->size_b > 1)
	{
		tmp = pile->b[0];
		pile->b[0] = pile->b[1];
		pile->b[1] = tmp;
	}
	if (!bonus)
		ft_printf("ss\n");
}
