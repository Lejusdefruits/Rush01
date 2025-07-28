/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:11:34 by lejusdefrui       #+#    #+#             */
/*   Updated: 2025/07/24 22:15:38 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_sep(str[i], charset) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(str[i], charset))
			in_word = 0;
		i++;
	}
	return (count);
}

char	*dup_word(char *str, char *charset, int start)
{
	int		i;
	int		k;
	int		len;
	char	*word;

	len = 0;
	i = start;
	while (str[i] && !is_sep(str[i], charset))
	{
		len++;
		i++;
	}
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = start;
	k = 0;
	while (str[i] && !is_sep(str[i], charset))
		word[k++] = str[i++];
	word[k] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		n_words;
	char	**result;

	n_words = count_words(str, charset);
	i = 0;
	j = 0;
	result = malloc(sizeof(char *) * (n_words + 1));
	if (!result)
		return (NULL);
	while (str[j])
	{
		while (str[j] && is_sep(str[j], charset))
			j++;
		if (str[j])
		{
			result[i++] = dup_word(str, charset, j);
			while (str[j] && !is_sep(str[j], charset))
				j++;
		}
	}
	result[i] = 0;
	return (result);
}

//int main(void)
//{
//	char **tab = ft_split("a, z, e, r, t, y, u, i, o, p", ", ");
//	int i = 0;
//	while (tab[i])
//	{
//		printf("%s\n", tab[i]);
//		free(tab[i]);
//		i++;
//	}
//	free(tab);
//	return 0;
//}
