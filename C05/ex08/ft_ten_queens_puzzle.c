/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:20:04 by acilione          #+#    #+#             */
/*   Updated: 2020/11/03 11:51:12 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(int *queens)
{
	int i;

	i = 0;
	while (i < 10)
		ft_putchar(queens[i++] + '0');
	ft_putchar('\n');
}

int		right_position(int row, int col, int *queens)
{
	int i_row;
	int abs_row;
	int abs_col;

	i_row = 0;
	while (i_row < row)
	{
		if (queens[i_row] == col)
			return (0);
		if (i_row - row < 0)
			abs_row = row - i_row;
		else
			abs_row = i_row - row;
		if (col - queens[i_row] < 0)
			abs_col = queens[i_row] - col;
		else
			abs_col = col - queens[i_row];
		if (abs_col == abs_row)
			return (0);
		i_row++;
	}
	return (1);
}

void	solve_queens(int *queens, int row, int *count)
{
	int col;

	col = 0;
	if (row > 9)
	{
		print(queens);
		*count = *count + 1;
		return ;
	}
	while (col < 10)
	{
		if (right_position(row, col, queens))
		{
			queens[row] = col;
			solve_queens(queens, row + 1, count);
		}
		col++;
	}
	return ;
}

int		ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int count;
	int i;

	i = 0;
	count = 0;
	while (i < 10)
		queens[i++] = 0;
	solve_queens(queens, 0, &count);
	return (count);
}
