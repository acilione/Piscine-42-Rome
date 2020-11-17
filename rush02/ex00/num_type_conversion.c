/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_type_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:37:53 by acilione          #+#    #+#             */
/*   Updated: 2020/11/08 18:07:41 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

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

int		ft_num_dig(int num)
{
	int				count;
	int				num_cp;

	count = 1;
	num_cp = num;
	if (num_cp < 0)
		num_cp *= -1;
	while (num_cp / 10 > 0)
	{
		num_cp /= 10;
		count++;
	}
	return ((num < 0) ? (count + 1) : count);
}

void	ft_rev_int_tab(char *tab, int size)
{
	int i;
	int temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

char	*ft_itoa(int num)
{
	int		num_len;
	char	*res;
	int		i;
	int		num_cp;

	i = 0;
	num_len = ft_num_dig(num);
	num_cp = num;
	if (!(res = (char *)malloc((num_len + 3) * sizeof(char))))
		return (0);
	while (i < num_len)
	{
		res[i] = (num_cp % 10) + '0';
		num_cp /= 10;
		i++;
	}
	res[i] = '\n';
	ft_rev_int_tab(res, ft_strlen(res));
	return (res);
}
