/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:05:13 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/22 16:29:50 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check_base(int size, char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || size == 1)
		return (0);
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if (base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putbase(int size, char *base, long nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= size)
	{
		ft_putbase(size, base, nbr / size);
	}
	write (1, &base[nbr % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		size;

	n = (long)nbr;
	size = 0;
	while (base[size] != '\0')
	{
		size++;
	}
	if (check_base(size, base))
	{
		ft_putbase(size, base, n);
	}
}
