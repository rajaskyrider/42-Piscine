/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:40:23 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/19 19:33:41 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				j;
	unsigned int	i;
	int				rt;
	int				srclen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	i = ft_strlen(dest);
	if (size <= i)
		rt = srclen + size;
	else
		rt = srclen + i;
	if (size == 0)
		return (rt);
	while (i < size - 1 && src[j] != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (rt);
}
