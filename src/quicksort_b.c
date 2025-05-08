/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdian <yaabdian@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:08:49 by yaabdian          #+#    #+#             */
/*   Updated: 2025/05/08 21:08:52 by yaabdian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	handle_small_sort_b(t_piles *pile, int len)
{
	if (len == 1)
	{
		push_a(pile, 0);
		return (0);
	}
	if (len == 2)
	{
		if (pile->b[0] < pile->b[1])
			swap_b(pile, 0);
		while (len--)
			push_a(pile, 0);
		return (0);
	}
	return (1);
}

int	sort_three_b(t_piles *pile, int len)
{
	if (!handle_small_sort_b(pile, len))
		return (0);
	while (len > 0 || !(pile->a[0] < pile->a[1] && pile->a[1] < pile->a[2]))
	{
		if (len == 1 && pile->a[0] > pile->a[1])
			swap_a(pile, 0);
		else if (len == 1 || (len >= 2 && pile->b[0] > pile->b[1])
			|| (len == 3 && pile->b[0] > pile->b[2]))
			len = ft_push(pile, len, 1);
		else
			swap_b(pile, 0);
	}
	return (0);
}

static int	process_pile_b(t_piles *pile, int *len, int *count_r, int pivot)
{
	if (pile->b[0] >= pivot)
	{
		push_a(pile, 0);
		(*len)--;
	}
	else
	{
		rotate_b(pile, 0);
		(*count_r)++;
	}
	return (1);
}

int	quicksort_pile_b(t_piles *pile, int len, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted(pile->b, len, 1))
	{
		while (len--)
			push_a(pile, 0);
		return (1);
	}
	if (len <= 3)
	{
		sort_three_b(pile, len);
		return (1);
	}
	numbers = len;
	if (!mediane_of_numbers(&pivot, pile->b, len))
		return (0);
	while (len > numbers / 2)
		process_pile_b(pile, &len, &count_r, pivot);
	while (count_r--)
		reverse_rotate_b(pile, 0);
	return (quicksort_pile_a(pile, numbers / 2 + numbers % 2, 0)
		&& quicksort_pile_b(pile, numbers / 2, 0));
}
