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

void	reverse_rotate_a(t_piles *pile, int bonus)
{
	int	tmp;
	int	i;

	if (pile->size_a < 2)
		return ;
	i = pile->size_a - 1;
	tmp = pile->a[i];
	while (i > 0)
	{
		pile->a[i] = pile->a[i - 1];
		i--;
	}
	pile->a[0] = tmp;
	if (!bonus)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_piles *pile, int bonus)
{
	int	tmp;
	int	i;

	if (pile->size_b < 2)
		return ;
	i = pile->size_b - 1;
	tmp = pile->b[i];
	while (i > 0)
	{
		pile->b[i] = pile->b[i - 1];
		i--;
	}
	pile->b[0] = tmp;
	if (!bonus)
		ft_printf("rrb\n");
}

void	reverse_rotate_r(t_piles *pile, int bonus)
{
	reverse_rotate_a(pile, 1);
	reverse_rotate_b(pile, 1);
	if (!bonus)
		ft_printf("rrr\n");
}
