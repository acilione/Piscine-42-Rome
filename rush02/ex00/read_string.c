/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:07:58 by acilione          #+#    #+#             */
/*   Updated: 2020/11/08 18:15:11 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

int		ft_count_three_digits_groups(char *num_str)
{
	int len_num;
	int three_digits_groups_count;

	len_num = ft_strlen(num_str);
	if (len_num % 3 == 0)
		three_digits_groups_count = len_num / 3;
	else
		three_digits_groups_count = (len_num / 3) + 1;
	return (three_digits_groups_count);
}

char	only_zeroes(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (num[i] != '0')
			return (' ');
		i++;
	}
	return ('\n');
}
