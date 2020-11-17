/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:50:23 by acilione          #+#    #+#             */
/*   Updated: 2020/10/21 16:36:13 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_digits(char i, char j, char k)
{
	if (i == '7' && j == '8' && k == '9')
	{
		ft_putchar(i);
		ft_putchar(j);
		ft_putchar(k);
	}
	else
	{
		ft_putchar(i);
		ft_putchar(j);
		ft_putchar(k);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char i;
	char j;
	char k;

	i = '0';
	j = '0';
	k = '0';
	while (i <= '9')
	{
		while (j <= '9')
		{
			while (k <= '9')
			{
				if (i != j && j != k && i != k)
				{
					print_digits(i, j, k);
				}
				++k;
			}
			k = j + 1;
			++j;
		}
		j = i + 1;
		++i;
	}
}
