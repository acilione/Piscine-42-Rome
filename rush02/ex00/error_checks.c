/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:02:20 by acilione          #+#    #+#             */
/*   Updated: 2020/11/08 16:02:22 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

void	ft_print_error(char *err)
{
	int i;

	i = 0;
	while (err[i])
	{
		write(2, &err[i], 1);
		i++;
	}
}

int		ft_check_format_error(char *dic)
{
	int i;

	i = 0;
	if (dic[i] == 32 || (dic[i] >= 9 && dic[i] <= 13))
		return (1);
	ft_print_error("Dict Error\n");
	return (0);
}

int		ft_check_input(char *inp)
{
	int i;

	i = 0;
	while (inp[i])
	{
		if (!(inp[i] >= '0' && inp[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
