/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivesort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdian <yaabdian@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:21:14 by yaabdian          #+#    #+#             */
/*   Updated: 2025/05/08 21:21:14 by yaabdian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../include/push_swap.h"

static void	get_minimums(t_piles *pile, int *min, int *secmin)
{
	int	i;

	*min = INT_MAX;
	*secmin = INT_MAX - 1;
	i = 0;
	while (i < pile->size_a)
	{
		if (pile->a[i] < *min)
		{
			if (*min < *secmin)
				*secmin = *min;
			*min = pile->a[i];
		}
		else if (pile->a[i] < *secmin)
			*secmin = pile->a[i];
		i++;
	}
}

void	five_numbers_case_pile_a(t_piles *pile)
{
	int	size;
	int	min;
	int	secmin;

	get_minimums(pile, &min, &secmin);
	size = pile->size_a;
	while (pile->size_a > 3)
	{
		if (pile->a[0] == min
			|| (size == 5 && pile->a[0] == secmin))
			push_b(pile, 0);
		else
			rotate_a(pile, 0);
	}
	if (pile->size_b == 2 && pile->b[0] < pile->b[1])
		swap_b(pile, 0);
	three_numbers_case_pile_a(pile);
	while (pile->size_b > 0)
		push_a(pile, 0);
}
