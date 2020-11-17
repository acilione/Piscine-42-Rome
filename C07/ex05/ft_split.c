/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:05:40 by acilione          #+#    #+#             */
/*   Updated: 2020/11/05 11:13:34 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_delimiter(char c, char *delimiters)
{
	int i;

	i = 0;
	while (delimiters[i])
	{
		if (c == delimiters[i])
			return (1);
		i++;
	}
	return (0);
}

int		count_strings(char *str, char *delimiters)
{
	int		str_count;
	char	*s;

	s = str;
	str_count = 0;
	if (!*s)
		return (0);
	while (*s != '\0')
	{
		while (*s != '\0' && is_delimiter(*s, delimiters))
			s++;
		if (!is_delimiter(*s, delimiters) && *s)
			str_count++;
		while (*s != '\0' && !is_delimiter(*s, delimiters))
			s++;
	}
	return (str_count);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

int		scan_str(char *str, char *delimiters)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[i] != '\0' && !is_delimiter(str[i], delimiters))
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_arr;
	char	*s;
	int		str_num;
	int		i;
	int		n;

	str_num = count_strings(str, charset);
	if (!(str_arr = (char **)malloc(sizeof(char *) * (str_num + 1))))
		return (0);
	s = str;
	i = -1;
	while (is_delimiter(*s, charset))
		s++;
	while (++i < str_num)
	{
		n = scan_str(s, charset);
		if (!(str_arr[i] = (char *)malloc(n)))
			return (0);
		ft_strncpy(str_arr[i], s, n);
		s += n + 1;
		while (*s != '\0' && is_delimiter(*s, charset))
			s++;
	}
	str_arr[i] = 0;
	return (str_arr);
}
