/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:21:58 by acilione          #+#    #+#             */
/*   Updated: 2020/10/28 18:40:04 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		base_is_valid(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' ||
				base[i] <= 31 || base[i] == 127)
			return (0);
		while (base[j] != '\0')
		{
			if ((base[j] == base[i]) && i != j)
				return (0);
			j++;
		}
		i++;
		j = i;
	}
	return (i);
}

int		check_char_pos(char c, char *arr)
{
	int i;

	i = 0;
	while (arr[i] != '\0')
	{
		if (c == arr[i])
			return (i);
		i++;
	}
	return (i * -1);
}

int		ft_atoi_base(char *str, char *base)
{
	int				b_len;
	unsigned int	num;
	int				sign;
	int				i;
	int				digit;

	sign = 1;
	num = 0;
	i = 0;
	if ((b_len = base_is_valid(base)) > 1)
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		while (str[i] == '-' || str[i] == '+')
		{
			sign *= (str[i] == '-') ? -1 : 1;
			i++;
		}
		while (str[i] != '\0' && ((digit = check_char_pos(str[i], base)) >= 0))
		{
			num = num * b_len + digit;
			i++;
		}
	}
	return (num * sign);
}
