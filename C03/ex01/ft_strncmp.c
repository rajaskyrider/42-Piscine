/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe@student.42luxembourg.lu>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:11:21 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/17 10:02:08 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				issame;

	i = 0;
	issame = 0;
	if (n == 0)
		return (issame);
	while (i < n && (s1[i] != 0 || s2[i] != 0))
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
			{
				issame = -1;
				break ;
			}
			else
			{
				issame = 1;
				break ;
			}
		}
		i++;
	}
	return (issame);
}
