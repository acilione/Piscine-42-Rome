/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:13:06 by acilione          #+#    #+#             */
/*   Updated: 2020/11/12 15:21:30 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_arrlen(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != 0)
		i++;
	return (i);
}

void	ft_swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;
	int j;
	int arrlen;

	arrlen = ft_arrlen(tab);
	i = 0;
	j = 0;
	while (i < arrlen - 1)
	{
		while (j < arrlen - 1)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		j = 0;
		i++;
	}
}
