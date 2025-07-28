/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_for_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:23:20 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/27 20:24:16 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2);
# include <stdlib.h>

typedef struct s_dict
{
	char	*nbr;
	char	*str;
}	t_dict;

char	*get_word_for_number(t_dict *dictionary, int dict_size, char *number)
{
	int	index;

	index = 0;
	while (index < dict_size)
	{
		if (ft_strcmp(dictionary[index].nbr, number) == 0)
			return (dictionary[index].str);
		index++;
	}
	return (NULL);
}
