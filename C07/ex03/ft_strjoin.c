/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 09:28:25 by acilione          #+#    #+#             */
/*   Updated: 2020/11/04 17:09:02 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		total_len(int size, char **strs, char *sep)
{
	int total_len;
	int i;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += ((ft_strlen(sep) * (size - 1)));
	return (total_len);
}

char	*ft_strcat(char *dest, char *src, char *sep)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	j = 0;
	while (sep[j])
	{
		dest[i] = sep[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		fin_str_len;
	char	*fin_str;
	int		i;

	if (size == 0)
	{
		if (!(fin_str = (char *)malloc(sizeof(char))))
			return (0);
		*fin_str = 0;
		return (fin_str);
	}
	fin_str_len = total_len(size, strs, sep);
	if (!(fin_str = (char *)malloc((fin_str_len + 1) * sizeof(char))))
		return (0);
	*fin_str = 0;
	i = 0;
	while (i < size - 1)
	{
		ft_strcat(fin_str, strs[i], sep);
		i++;
	}
	ft_strcat(fin_str, strs[i], "\0");
	return (fin_str);
}
