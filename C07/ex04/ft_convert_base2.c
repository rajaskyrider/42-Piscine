/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:29:19 by rpandipe          #+#    #+#             */
/*   Updated: 2024/02/01 15:53:48 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if (base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_checkbase(char *str, char *base, int i)
{
	int	j;
	int	cnt;
	int	flag;

	cnt = 0;
	while (str[i] != 0)
	{
		j = 0;
		flag = 0;
		while (base[j] != 0)
		{
			if (base[j] == str[i])
			{
				cnt++;
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag != 1)
			break ;
		i++;
	}
	return (cnt);
}

int	ft_digits_b(char *str, char *base, int start, int cnt)
{
	int	ans;
	int	size;
	int	i;
	int	j;
	int	val;

	size = 0;
	ans = 0;
	while (base[size] != '\0')
		size++;
	if (size <= 0)
		return (ans);
	while (cnt-- > 0)
	{
		i = 0;
		val = 1;
		while (base[i] != 0 && str[start] != base[i])
			i++;
		j = cnt;
		while (j-- > 0)
			val = val * size;
		ans = ans + (i * val);
		start++;
	}
	return (ans);
}

int	ft_atoi_base(char *str, char *base)
{
	int	end;
	int	sign;
	int	ans;
	int	cnt;

	end = 0;
	sign = 0;
	ans = -1;
	while ((str[end] > 8 && str[end] < 14) || (str[end] == 32))
		end++;
	while (str[end] == '-' || str[end] == '+')
	{
		if (str[end] == '-')
			sign++;
		end++;
	}
	if (sign % 2 == 0)
		ans = 1;
	cnt = ft_checkbase(str, base, end);
	if ((cnt > 0) && (check_base(base) != 0))
		ans = ans * ft_digits_b(str, base, end, cnt);
	else
		ans = 0;
	return (ans);
}
