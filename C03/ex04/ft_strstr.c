/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 11:06:43 by acilione          #+#    #+#             */
/*   Updated: 2020/10/26 12:33:58 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (!(*str) && !(*to_find))
		return ("");
	if (str[i] == '\0')
		return (0);
	while (str[i] && to_find[k])
	{
		if (str[i + k] != to_find[k])
		{
			i++;
			k = 0;
		}
		else
			k++;
	}
	if (k == 0 && *to_find)
		return (0);
	else
		return (str + i);
}
