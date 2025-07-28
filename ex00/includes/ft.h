/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:53:31 by dedavid           #+#    #+#             */
/*   Updated: 2025/07/27 20:13:20 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUF_SIZE 1024
#define MAX_PIECES 1024

typedef struct s_dict
{
	char	*nbr;
	char	*str;
}	t_dict;

void	ft_free_tab(char **tab);
void	ft_free_dict(t_dict *dict, int size);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_swap(int *a, int *b);
void	ft_putnbr_base(int nbr, char *base);
void	convert_number_to_words(char *input, t_dict *dictionary, int dict_size);
char	*ft_strdup(char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcpy(char *dest, char *src);
char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_tablen(char **tab);
int		ft_dictlen(t_dict *dict);
t_dict	*parse_readed_file(char *filename);
char	*find_word(t_dict *dict, int size, char *nbr);
char	*get_word_for_number(t_dict *dictionary, int dict_size, char *number);
char	*create_power_string(int group_position);
int		compare_numbers_as_strings(char *a, char *b);
char	*format_to_three_digits(char *digits);
int		is_all_zeros(char *text);

#endif
