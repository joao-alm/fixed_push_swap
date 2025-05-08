/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabdian <yaabdian@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:49:16 by yaabdian          #+#    #+#             */
/*   Updated: 2025/05/08 20:52:39 by yaabdian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../printf/ft_printf.h"

void	temporary_sort(int *temp_pile, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (temp_pile[i] > temp_pile[j])
			{
				temp = temp_pile[i];
				temp_pile[i] = temp_pile[j];
				temp_pile[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	three_numbers_case_pile_a(t_piles *pile)
{
	int	a;
	int	b;
	int	c;

	a = pile->a[0];
	b = pile->a[1];
	c = pile->a[2];
	if (a > b && b < c && a < c)
		swap_a(pile, 0);
	else if (a > b && b > c && a > c)
	{
		swap_a(pile, 0);
		reverse_rotate_a(pile, 0);
	}
	else if (a > b && b < c && a > c)
		rotate_a(pile, 0);
	else if (a < b && b > c && a < c)
	{
		swap_a(pile, 0);
		rotate_a(pile, 0);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(pile, 0);
}

int	sort(t_piles *pile, int size)
{
	if (check_sorted(pile->a, pile->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(pile, 0);
		else if (size == 3)
			three_numbers_case_pile_a(pile);
		else if (size == 4 || size == 5)
			five_numbers_case_pile_a(pile);
		else
			quicksort_pile_a(pile, size, 0);
	}
	return (0);
}

int	ft_push(t_piles *pile, int len, int push)
{
	if (push == 0)
		push_b(pile, 0);
	else
		push_a(pile, 0);
	len--;
	return (len);
}
