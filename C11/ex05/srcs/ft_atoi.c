/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:04:33 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/01 19:33:56 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checksign(char *str, int i)
{
	int	cnt;

	cnt = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			cnt++;
		i++;
	}
	if (cnt % 2 == 0)
		return (1);
	return (-1);
}

int	ft_power(int d)
{
	int	pow;

	pow = 1;
	while (d > 1)
	{
		pow *= 10;
		d--;
	}
	return (pow);
}

int	ft_digits(char *str, int start)
{
	int	end;
	int	digit;
	int	ans;
	int	ti;

	digit = 0;
	end = start;
	while (str[end] >= '0' && str[end] <= '9')
	{
		end++;
		digit++;
	}
	ans = 0;
	while (start < end)
	{
		ti = (int) str[start] - 48;
		ans = ans + (ti * ft_power(digit));
		start++;
		digit--;
	}
	return (ans);
}

int	ft_atoi(char *str)
{
	int	end;
	int	sign;
	int	ans;

	end = 0;
	sign = 1;
	ans = 0;
	while ((str[end] > 8 && str[end] < 14) || (str[end] == 32))
		end++;
	if (str[end] == '-' || str[end] == '+')
		sign = ft_checksign(str, end);
	while (str[end] == '-' || str[end] == '+')
	{
		end++;
	}
	if (str[end] >= '0' && str[end] <= '9')
		ans = ft_digits(str, end);
	return (ans * sign);
}
