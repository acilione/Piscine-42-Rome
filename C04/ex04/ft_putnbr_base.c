/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 18:16:20 by acilione          #+#    #+#             */
/*   Updated: 2020/10/28 16:18:32 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int		valid_characters(char *arr)
{
	unsigned int i;

	i = 0;
	if (!(*arr))
		return (0);
	while (arr[i])
	{
		if (arr[i] == '+' || arr[i] == '-' ||
				arr[i] <= 31 || arr[i] == 127)
			return (0);
		i++;
	}
	return (i);
}

unsigned int		char_not_repeated(char *arr)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (arr[0] == '\0' || arr[1] == '\0')
		return (0);
	while (arr[i] != '\0')
	{
		while (arr[j] != '\0')
		{
			if (arr[j] == arr[i] && j != i)
				return (0);
			j++;
		}
		i++;
		j = i;
	}
	return (1);
}

void				conv_base(unsigned int b, unsigned int n, char *base)
{
	if (n >= 0 && n < b)
		ft_putchar(base[n]);
	else
	{
		conv_base(b, n / b, base);
		ft_putchar(base[n % b]);
	}
}

void				ft_putnbr_base(int nbr, char *base)
{
	unsigned int b;
	unsigned int n;

	b = valid_characters(base);
	if (b > 0 && char_not_repeated(base))
	{
		if (nbr < 0)
		{
			n = -nbr;
			ft_putchar('-');
			conv_base(b, n, base);
		}
		else
		{
			n = nbr;
			conv_base(b, n, base);
		}
	}
}
