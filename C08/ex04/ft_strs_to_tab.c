/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:00:45 by acilione          #+#    #+#             */
/*   Updated: 2020/11/03 19:06:09 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

char				*ft_strcpy(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	while (j < i)
	{
		dest[j] = '\0';
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*result;
	int				i;

	i = 0;
	if (!(result = (t_stock_str *)malloc((ac + 2) * sizeof(t_stock_str))))
		return (0);
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		if (!(result[i].copy = (char *)malloc(result[i].size + 1)))
			return (0);
		ft_strcpy(result[i].copy, av[i]);
		++i;
	}
	result[i].str = 0;
	return (result);
}
