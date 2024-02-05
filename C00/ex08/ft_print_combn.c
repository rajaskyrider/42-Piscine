/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:20:11 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/31 18:42:03 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int nb, int *tab, int pos)
{
	int	i;

	if (pos == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	i = 0;
	while (i < nb)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

void	ft_add_digits(int nb, int *comb)
{
	int	i;
	int	max;

	i = nb - 1;
	max = 9;
	while (comb[i] == max)
	{
		i -= 1;
		max -= 1;
	}
	comb[i] += 1;
	while (i < nb)
	{
		comb[i + 1] = comb[i] + 1;
		i += 1;
	}
}

void	ft_print_combn(int nb)
{
	int	comb[10];
	int	i;

	i = 0;
	while (i < nb)
	{
		comb[i] = i;
		i++;
	}
	ft_print(nb, comb, 0);
	while (comb[0] != 10 - nb || comb[nb - 1] != 9)
	{
		if (comb[nb - 1] != 9)
		{
			comb[nb - 1] += 1;
		}
		else
		{
			ft_add_digits(nb, comb);
		}
		ft_print(nb, comb, 1);
	}
}
