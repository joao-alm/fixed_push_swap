/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdian <yaabdian@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:49:16 by yaabdian          #+#    #+#             */
/*   Updated: 2025/05/08 20:59:03 by yaabdian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdlib.h>

void	quicksort_three_pile_a_and_b(t_piles *pile, int len)
{
	if (len == 3)
	{
		if (pile->a[0] > pile->a[1] && pile->a[0] > pile->a[2])
		{
			swap_a(pile, 0);
			rotate_a(pile, 0);
			swap_a(pile, 0);
			reverse_rotate_a(pile, 0);
		}
		else if (pile->a[1] > pile->a[0] && pile->a[1] > pile->a[2])
		{
			rotate_a(pile, 0);
			swap_a(pile, 0);
			reverse_rotate_a(pile, 0);
		}
		len--;
	}
	if (len == 2)
		if (pile->a[0] > pile->a[1])
			swap_a(pile, 0);
}

int	mediane_of_numbers(int *pivot, int *pile, int size)
{
	int	*temp_pile;
	int	i;

	temp_pile = (int *)malloc(size * sizeof(int));
	if (!temp_pile)
		return (0);
	i = 0;
	while (i < size)
	{
		temp_pile[i] = pile[i];
		i++;
	}
	temporary_sort(temp_pile, size);
	*pivot = temp_pile[size / 2];
	free(temp_pile);
	return (1);
}

static int	process_pile_a(t_piles *pile, int *len, int *count_r, int pivot)
{
	if (pile->a[0] < pivot)
	{
		push_b(pile, 0);
		(*len)--;
	}
	else
	{
		rotate_a(pile, 0);
		(*count_r)++;
	}
	return (1);
}

int	quicksort_pile_a(t_piles *pile, int len, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted(pile->a, len, 0))
		return (1);
	numbers = len;
	if (len <= 3)
	{
		quicksort_three_pile_a_and_b(pile, len);
		return (1);
	}
	if (!mediane_of_numbers(&pivot, pile->a, len))
		return (0);
	while (len > numbers / 2 + numbers % 2)
		process_pile_a(pile, &len, &count_r, pivot);
	while (count_r > 0)
	{
		reverse_rotate_a(pile, 0);
		count_r--;
	}
	return (quicksort_pile_a(pile, numbers / 2 + numbers % 2, 0)
		&& quicksort_pile_b(pile, numbers / 2, 0));
}
