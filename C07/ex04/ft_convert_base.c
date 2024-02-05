/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:25:01 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/01 16:01:42 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);
int	ft_checkbase(char *str, char *base, int i);
int	ft_digits_b(char *str, char *base, int start, int cnt);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_putbase(int size, char *base, long nbr, char *oldstr)
{
	int		count;
	char	*str;
	int		i;

	i = -1;
	count = 0;
	if (nbr < 0)
	{
		oldstr = (char *)malloc(sizeof(char) * count + 1);
		oldstr[count] = '-';
		nbr = -nbr;
	}	
	if (nbr >= size)
	{
		oldstr = ft_putbase(size, base, nbr / size, oldstr);
	}
	if (oldstr != NULL)
		count = ft_strlen(oldstr);
	str = (char *)malloc(sizeof(char) * count + 1);
	while (++i < count)
		str[i] = oldstr[i];
	str[count] = base[nbr % size];
	str[count + 1] = 0;
	free(oldstr);
	return (str);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		size;
	char	*str;

	n = (long)nbr;
	str = NULL;
	size = 0;
	while (base[size] != '\0')
	{
		size++;
	}
	if (check_base(base))
	{
		str = ft_putbase(size, base, n, str);
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		ans;
	int		end;
	int		cnt;

	end = 0;
	while ((nbr[end] > 8 && nbr[end] < 14) || (nbr[end] == 32))
		end++;
	while (nbr[end] == '-' || nbr[end] == '+')
	{
		end++;
	}
	cnt = ft_checkbase(nbr, base_from, end);
	if (!((cnt > 0) && (check_base(base_from) != 0)))
		return (NULL);
	ans = ft_atoi_base(nbr, base_from);
	str = ft_putnbr_base(ans, base_to);
	return (str);
}
