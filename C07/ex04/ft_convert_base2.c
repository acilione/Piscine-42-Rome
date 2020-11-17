/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:13:22 by acilione          #+#    #+#             */
/*   Updated: 2020/11/05 10:49:12 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
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
	return (-1);
}

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
				base[i] <= 32 || base[i] == 127)
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
