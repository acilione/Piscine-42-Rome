/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 16:00:04 by acilione          #+#    #+#             */
/*   Updated: 2020/10/24 16:12:16 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int col, char first_char, char middle_char, char end_char)
{
	int i;

	i = 1;
	while (i <= col)
	{
		if (i == 1)
			ft_putchar(first_char);
		else if (i > 1 && i < col)
			ft_putchar(middle_char);
		else
			ft_putchar(end_char);
		i++;
	}
}

void	rush(int a, int b)
{
	int row;

	row = 1;
	if (a == 0 || b == 0)
		return ;
	while (row <= b)
	{
		if (row == 1)
		{
			print_line(a, '/', '*', '\\');
		}
		else if (row > 1 && row < b)
		{
			print_line(a, '*', ' ', '*');
		}
		else
		{
			print_line(a, '\\', '*', '/');
		}
		ft_putchar('\n');
		row++;
	}
}
