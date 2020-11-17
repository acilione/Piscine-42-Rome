/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acilione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:36:01 by acilione          #+#    #+#             */
/*   Updated: 2020/10/29 19:21:04 by acilione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;

	i = nb;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	else
		while (i > 1)
		{
			nb *= i - 1;
			i--;
		}
	return (nb);
}
