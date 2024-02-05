/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:49:27 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/16 09:59:58 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printhex(char h)
{
	char	fc;
	char	sc;

	ft_putchar('\\');
	fc = "0123456798abcdef"[h / 16];
	sc = "0123456789abcdef"[h % 16];
	ft_putchar(fc);
	ft_putchar(sc);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			ft_printhex(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
