/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:41:25 by acilione          #+#    #+#             */
/*   Updated: 2020/10/28 18:35:07 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
