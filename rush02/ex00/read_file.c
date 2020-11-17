/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:20:02 by acilione          #+#    #+#             */
/*   Updated: 2020/11/08 18:12:07 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "rush.h"

int		ft_count_byte_file(char *filename)
{
	long long int	bytes_count;
	int				fd;
	char			c;

	bytes_count = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_print_error("Cannot read file.\n");
		return (0);
	}
	while (read(fd, &c, 1))
		bytes_count++;
	close(fd);
	return (bytes_count);
}

char	*ft_file_to_str(char *filename)
{
	int				fd;
	char			c;
	long long int	bytes_count;
	char			*file_content;
	int				i;

	if (!(bytes_count = ft_count_byte_file(filename)))
		return (0);
	if (!(file_content = (char *)malloc(sizeof(char) * (bytes_count + 1))))
		return (0);
	i = 1;
	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_print_error("Cannot read file.\n");
		return (0);
	}
	file_content[0] = '\n';
	while (read(fd, &c, 1))
	{
		file_content[i] = c;
		i++;
	}
	close(fd);
	return (file_content);
}

void	ft_print_value(char *str, int i)
{
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		{
			while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
				i++;
			if (str[i] != '\0' && str[i] != '\n')
				ft_putchar(' ');
		}
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_pr_w_dic(char *input, char *dic, char suffix_char)
{
	int		i;
	char	*match;

	match = ft_strstr(dic, input);
	if (!match)
	{
		ft_print_error("Dict Error\n");
		return ;
	}
	i = ft_strlen(input) + 1;
	while ((match[i] >= 9 && match[i] <= 13) || match[i] == 32
		|| match[i] == ':')
		i++;
	if (!ft_check_format_error(dic))
		return ;
	while ((match[i] >= 9 && match[i] <= 13) || match[i] == 32)
		i++;
	ft_print_value(match, i);
	ft_putchar(suffix_char);
}
