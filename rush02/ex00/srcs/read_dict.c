/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cponce-q <cponce-q@student.42luxembou      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:02:49 by cponce-q          #+#    #+#             */
/*   Updated: 2024/01/28 23:36:03 by cponce-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

struct s_dict	*addline(struct s_dict *s_olddict, char *line, int linenumber)
{
	struct s_dict	*s_nd;
	int				number;
	int				i;
	int				j;

	i = -1;
	j = -1;
	s_nd = (struct s_dict *) malloc(sizeof (struct s_dict) * (linenumber + 1));
	while (++i < linenumber)
	{
		s_nd[i].number = s_olddict[i].number;
		s_nd[i].digits = s_olddict[i].digits;
		s_nd[i].word = ft_dup(s_olddict[i].word);
	}
	free(s_olddict);
	while (line[++j] >= '0' && line[j] <= '9')
		;
	number = ft_atoi(line);
	s_nd[linenumber].number = number;
	s_nd[linenumber].digits = j;
	s_nd[linenumber].word = ft_strrdup(line);
	return (s_nd);
}

int	open_file(char *name)
{
	int	file_descriptor;

	file_descriptor = open(name, O_RDONLY);
	if (file_descriptor == -1)
	{
		return (-1);
	}
	return (file_descriptor);
}

struct s_dict	*prsfile(struct s_dict *s_nd, int *maxline, int f_d, char *str)
{
	int		line[2];
	char	*buffer;

	line[0] = 0;
	line[1] = 0;
	buffer = (char *)malloc(sizeof(char));
	while ((read(f_d, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n' && str[0] != 0)
		{
			s_nd = addline(s_nd, str, line[1]);
			line[1]++;
			free(str);
			str = (char *)malloc(sizeof(char));
			str[0] = '\0';
			line[0] = 0;
		}
		else
			str = ft_strrcat(str, buffer[0], ++line[0]);
	}
	*maxline = line[1];
	free(buffer);
	free(str);
	return (s_nd);
}

struct s_dict	*readfile(char *name, int *maxline)
{
	int				file_descriptor;
	char			*str;
	int				ml;
	struct s_dict	*s_numdict;

	file_descriptor = open_file(name);
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	s_numdict = (struct s_dict *)malloc(sizeof(struct s_dict));
	s_numdict = prsfile(s_numdict, &ml, file_descriptor, str);
	close(file_descriptor);
	*maxline = ml;
	free(str);
	return (s_numdict);
}

int	find_index(struct s_dict *s_numdict, int maxline, int value)
{
	int	i;

	i = 0;
	while (i < maxline)
	{
		if ((int)s_numdict[i].number == value)
			return (i);
		i++;
	}
	return (-1);
}
