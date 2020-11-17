/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_digits_converter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:07:51 by acilione          #+#    #+#             */
/*   Updated: 2020/11/08 18:18:37 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

char	last_c(int num_scale)
{
	char c;

	c = (num_scale > 1 ? ' ' : '\n');
	return (c);
}

void	ft_print_int_num_in_words(int num, char *dic, int num_s)
{
	if (num / 100 > 0)
	{
		ft_pr_w_dic(ft_itoa(num / 100), dic, ' ');
		ft_pr_w_dic("100", dic, ' ');
		num -= (100 * (num / 100));
	}
	if (num >= 20)
	{
		if ((num % 10) == 0)
			ft_pr_w_dic(ft_itoa(num), dic, last_c(num_s));
		else
		{
			ft_pr_w_dic(ft_itoa(num - (num % 10)), dic, ' ');
			ft_pr_w_dic(ft_itoa(num % 10), dic, last_c(num_s));
		}
	}
	if (num <= 19 && num > 0)
		ft_pr_w_dic(ft_itoa(num), dic, last_c(num_s));
}

void	ft_convert_three_dig_to_words(char *str, char *dic, int num_sc)
{
	int num;

	num = ft_atoi(str);
	if (num_sc > 1 && num == 0)
		return ;
	ft_print_int_num_in_words(num, dic, num_sc);
}
