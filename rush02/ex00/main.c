/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:49:51 by acilione          #+#    #+#             */
/*   Updated: 2020/11/07 09:50:19 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush.h"

int		main(int argc, char **argv)
{
	char *dictionary;

	if (argc == 2)
	{
		if (!ft_check_input(argv[1]))
			ft_print_error("Error\n");
		if (!ft_check_input(argv[1]))
			return (0);
		dictionary = ft_file_to_str("numbers.dict");
		convert_num(argv[1], dictionary);
		free(dictionary);
	}
	else if (argc == 3)
	{
		if (!ft_check_input(argv[2]))
		{
			ft_print_error("Error\n");
			return (0);
		}
		if (!(dictionary = ft_file_to_str(argv[1])))
			return (1);
		convert_num(argv[2], dictionary);
		free(dictionary);
	}
	return (0);
}
