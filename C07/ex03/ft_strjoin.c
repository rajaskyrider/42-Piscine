/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:47:10 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/31 17:58:35 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ptrlen(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	count;
	int	count1;

	i = -1;
	count = 0;
	count1 = 0;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != 0)
			count++;
	}
	i = -1;
	while (sep[++i] != 0)
		count1++;
	count = count + (count1 * size - 1);
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		count;
	char	*ans;
	int		i;
	int		z;
	int		j;

	i = -1;
	z = 0;
	count = ft_ptrlen(size, strs, sep);
	ans = (char *)malloc(sizeof(char) * (count +1));
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != 0)
		{
			ans[z++] = strs[i][j];
			j++;
		}
		j = -1;
		if (i != size - 1)
			while (sep[++j] != 0)
				ans[z++] = sep[j];
	}
	ans[z] = '\0';
	return (ans);
}
