/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:28:36 by acilione          #+#    #+#             */
/*   Updated: 2020/11/12 18:28:47 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		sort_asc(int *tab, int len, int (*f)(int, int))
{
	int index;

	index = 0;
	while (index < len - 1)
	{
		if (f(tab[index], tab[index + 1]) < 0)
			return (0);
		index++;
	}
	return (1);
}

int		sort_desc(int *tab, int len, int (*f)(int, int))
{
	int index;

	index = 0;
	while (index < len - 1)
	{
		if (f(tab[index], tab[index + 1]) > 0)
			return (0);
		index++;
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (sort_desc(tab, length, f) || (sort_asc(tab, length, f)))
		return (1);
	return (0);
}
