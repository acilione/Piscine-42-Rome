/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nummanagement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 13:29:31 by acilione          #+#    #+#             */
/*   Updated: 2020/11/11 18:23:33 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_atoi(char *str)
{
	int		sign;
	int		num;
	char	*charptr;

	sign = 1;
	charptr = str;
	num = 0;
	while (*charptr == ' ' || (*charptr >= 9 && *charptr <= 13))
		charptr++;
	while (*charptr == '-' || *charptr == '+')
	{
		if (*charptr == '-')
			sign *= -1;
		charptr++;
	}
	while (*charptr >= '0' && *charptr <= '9')
	{
		num *= 10;
		num += (int)(*charptr - '0');
		charptr++;
	}
	return (num * sign);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
		}
		else
		{
			ft_putnbr(nb * -1);
		}
	}
	else if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}
