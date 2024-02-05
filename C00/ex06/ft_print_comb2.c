/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:48:42 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/29 20:28:24 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_results(int i, int j, int k, int l)
{
	ft_putchar(i + '0');
	ft_putchar(j + '0');
	write(1, &" ", 1);
	ft_putchar(k + '0');
	ft_putchar(l + '0');
	if (!(i == 9 && j == 8 && k == 9 && l == 9))
	{
		write(1, &", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 10)
		{
			k = -1;
			while (++k < 10)
			{
				l = -1;
				while (++l < 10)
					if (i * 10 + j < k * 10 + l)
						print_results(i, j, k, l);
			}
		}
	}
}
