/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:07:34 by rpandipe          #+#    #+#             */
/*   Updated: 2024/01/28 21:51:41 by cponce-q         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

struct s_dict{
	unsigned long long int	number;
	int						digits;
	char					*word;
};

int				ft_strlen(char *str);
int				ft_atoi(char *str);
int				start_values(char *value, struct s_dict *s_numdict, int maxl);
int				checkvalue(char *value);
int				checkdict(char *name);
int				countdigits(int number);
char			*ft_dup(char *src);
char			*ft_strrdup(char *src);
char			*ft_strrcat(char *dest, char src, int linesize);
struct s_dict	*addline(struct s_dict *s_olddict, char *line, int linenumber);
int				open_file(char *name);
struct s_dict	*readfile(char *name, int *maxline);
int				find_index(struct s_dict *s_numdict, int maxline, int value);
void			p_h(struct s_dict *s_numdict, int maxline, char *rem, int num);
void			print_ltw(struct s_dict *s_numdict, int maxline, int value);
void			print_htw(struct s_dict *s_numdict, int maxline, int value);
void			p_hds(struct s_dict *s_numdict, int maxline, int value);
void			print_digits(int digits, struct s_dict *s_numdict, int maxline);
void			p_threem(int *tt, char *value, struct s_dict *s_nd, int ml);
void			p_hnums(struct s_dict *s_nd, int ml, char *value, int digits);
void			p_utw(struct s_dict *s_nd, int maxline, int value, int digits);
void			print_numbers(struct s_dict *s_numdict, int maxline, int value);
#endif
