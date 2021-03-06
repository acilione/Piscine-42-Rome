/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:34:53 by ade-feli          #+#    #+#             */
/*   Updated: 2020/11/12 10:34:56 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_bytes_count(char *filename)
{
	int		bytes_count;
	int		fd;
	char	c;

	bytes_count = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (0);
	while (read(fd, &c, 1))
		bytes_count++;
	close(fd);
	return (bytes_count);
}
