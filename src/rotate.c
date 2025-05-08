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

void	rotate_a(t_piles *pile, int bonus)
{
	int	tmp;
	int	i;

	if (pile->size_a < 2)
		return ;
	tmp = pile->a[0];
	i = 0;
	while (i < pile->size_a - 1)
	{
		pile->a[i] = pile->a[i + 1];
		i++;
	}
	pile->a[i] = tmp;
	if (!bonus)
		ft_printf("ra\n");
}

void	rotate_b(t_piles *pile, int bonus)
{
	int	tmp;
	int	i;

	if (pile->size_b < 2)
		return ;
	tmp = pile->b[0];
	i = 0;
	while (i < pile->size_b - 1)
	{
		pile->b[i] = pile->b[i + 1];
		i++;
	}
	pile->b[i] = tmp;
	if (!bonus)
		ft_printf("rb\n");
}

void	rotate_r(t_piles *pile, int bonus)
{
	rotate_a(pile, 1);
	rotate_b(pile, 1);
	if (!bonus)
		ft_printf("rr\n");
}
