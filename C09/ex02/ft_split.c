/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:12:47 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/31 19:44:33 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	check_same(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_strings(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && check_same(*str, charset))
			str++;
		if (*str)
			count++;
		while (*str && !check_same(*str, charset))
			str++;
	}
	return (count);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !check_same(str[i], charset))
		i++;
	return (i);
}

char	*word(char *str, char *charset)
{
	int		i;
	int		len;
	char	*word;

	i = 0;
	len = ft_strlen(str, charset);
	word = (char *)malloc((len + 1) * sizeof(char));
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc((count_strings(str, charset) + 1) * sizeof(char *));
	while (*str)
	{
		while (*str && check_same(*str, charset))
			str++;
		if (*str)
		{
			arr[i] = word(str, charset);
			i++;
		}
		while (*str && !check_same(*str, charset))
			str++;
	}
	arr[i] = 0;
	return (arr);
}
