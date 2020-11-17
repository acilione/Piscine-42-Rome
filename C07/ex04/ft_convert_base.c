/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:31:28 by acilione          #+#    #+#             */
/*   Updated: 2020/11/05 10:48:57 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strlen(char *str);
int				check_char_pos(char c, char *arr);
int				base_is_valid(char *base);

long long int	ft_atoi_base(char *str, char *base)
{
	int				b_len;
	long long int	num;
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

int				num_dig(int num, int b_len)
{
	int				count;
	long long int	num_cp;

	count = 0;
	num_cp = (long long int)num;
	if (num_cp < 0)
		num_cp *= -1;
	while (num_cp / b_len > 0)
	{
		num_cp /= b_len;
		count++;
	}
	return ((num < 0) ? (count + 1) : count);
}

void			ft_rev_int_tab(char *tab, int size)
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

char			*ft_itoa_base(int num, char *base)
{
	int		b_len;
	int		num_len;
	char	*res;
	int		i;
	int		num_cp;

	i = 0;
	num_cp = num;
	if ((b_len = base_is_valid(base)) > 1)
	{
		num_len = num_dig(num, b_len);
		if (!(res = (char *)malloc((num_len + 1) * sizeof(char))))
			return (0);
		while (i <= num_len)
		{
			res[i] = num_cp < 0 ? base[num % b_len * -1] : base[num % b_len];
			num /= b_len;
			if (num_cp < 0 && i == num_len)
				res[i] = '-';
			i++;
		}
		ft_rev_int_tab(res, ft_strlen(res));
		return (res);
	}
	return (0);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long int	i;
	char			*arr;
	int				j;

	j = 0;
	if (!(base_is_valid(base_from)) || !(base_is_valid(base_to)))
		return (0);
	i = ft_atoi_base(nbr, base_from);
	arr = ft_itoa_base(i, base_to);
	return (arr);
}
