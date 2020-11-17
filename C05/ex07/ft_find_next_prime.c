/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:05:19 by acilione          #+#    #+#             */
/*   Updated: 2020/11/02 08:24:47 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_is_prime(int nb)
{
	int i;

	i = 5;
	if (nb <= 1)
		return (0);
	else if (nb <= 3)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	while (check_is_prime(nb) == 0)
		nb++;
	return (nb);
}
