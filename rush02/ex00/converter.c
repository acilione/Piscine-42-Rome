/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:50:11 by acilione          #+#    #+#             */
/*   Updated: 2020/11/08 10:50:23 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

char	*generate_dimension_num(int num_len, char prefix_char)
{
	char	*num;
	int		i;

	i = 2;
	num_len = (num_len % 3 == 0 ? num_len - 2 : num_len - num_len % 3 + 1);
	if (!(num = (char *)malloc(sizeof(char) * (num_len + 2))))
		return (0);
	num[0] = prefix_char;
	num[1] = '1';
	while (i < num_len + 1)
	{
		num[i] = '0';
		i++;
	}
	num[i] = '\0';
	return (num);
}

void	complex_converter(char *num, char *dictionary, int num_scale)
{
	int		skip;
	int		num_len;
	char	*num_to_convert;
	char	*dimension_num;
	char	*ptr;

	while (num_scale > 0)
	{
		num_len = ft_strlen(num);
		dimension_num = generate_dimension_num(num_len, '\n');
		skip = (num_len % 3 == 0 ? 3 : num_len % 3);
		num_to_convert = ft_strndup(num, skip);
		ft_convert_three_dig_to_words(num_to_convert, dictionary, num_scale);
		ptr = num;
		ptr += skip;
		if (num_scale > 1 && ft_atoi(num_to_convert) != 0)
			ft_pr_w_dic(dimension_num, dictionary, only_zeroes(ptr));
		num += skip;
		free(num_to_convert);
		num_scale--;
	}
}

void	convert_num(char *num, char *dictionary)
{
	int num_scale;

	num_scale = ft_count_three_digits_groups(num);
	while (*num == '0')
		num++;
	if (num_scale <= 1)
		ft_convert_three_dig_to_words(num, dictionary, num_scale);
	else
		complex_converter(num, dictionary, num_scale);
}
