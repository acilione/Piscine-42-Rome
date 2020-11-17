/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:30:14 by acilione          #+#    #+#             */
/*   Updated: 2020/10/21 19:14:09 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_digits(int i, int j)
{
	if (i == 98 && j == 99)
	{
		ft_putchar(i / 10 + '0');
		ft_putchar(i % 10 + '0');
		ft_putchar(' ');
		ft_putchar(j / 10 + '0');
		ft_putchar(j % 10 + '0');
	}
	else if (i != j)
	{
		ft_putchar(i / 10 + '0');
		ft_putchar(i % 10 + '0');
		ft_putchar(' ');
		ft_putchar(j / 10 + '0');
		ft_putchar(j % 10 + '0');
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 99)
	{
		while (j <= 99)
		{
			ft_print_digits(i, j);
			j++;
		}
		j = i + 1;
		i++;
	}
}
