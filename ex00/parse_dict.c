/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:11:34 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/27 20:09:50 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

static char	*append_buffer(char *result, char *buffer, int total_size, int read_size)
{
	char	*new_result;
	int		i;

	new_result = malloc(total_size + read_size + 1);
	if (!new_result)
		return (NULL);
	i = -1;
	while (++i < total_size)
		new_result[i] = result[i];
	i = -1;
	while (++i < read_size)
		new_result[total_size + i] = buffer[i];
	new_result[total_size + read_size] = '\0';
	return (free(result), new_result);
}

static char	*read_loop(int fd)
{
	char	buffer[BUF_SIZE];
	char	*result;
	int		read_size;
	int		total_size;

	result = malloc(1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	total_size = 0;
	while ((read_size = read(fd, buffer, BUF_SIZE)) > 0)
	{
		result = append_buffer(result, buffer, total_size, read_size);
		if (!result)
			return (NULL);
		total_size += read_size;
	}
	return (result);
}

char	*read_whole_file(char *filename)
{
	int		fd;
	char	*result;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	result = read_loop(fd);
	close(fd);
	return (result);
}

t_dict	*parse_readed_file(char *file_name)
{
	int		i;
	char	*text;
	char	**tab;
	t_dict	*dico;

	i = 0;
	text = read_whole_file(file_name);
	if (!text)
		return (perror("read"), (NULL));
	tab = ft_split(text, " :\n");
	dico = malloc(sizeof(t_dict) * (ft_tablen(tab) / 2 + 1));
	while (i < ft_tablen(tab))
	{
		if (!tab[i + 1])
			break;
		dico[i / 2].nbr = ft_strdup(tab[i]);
		dico[i / 2].str = ft_strdup(tab[i + 1]);
		i += 2;
	}
	free(text);
	ft_free_tab(tab);
	return (dico);
}

/* void	print_dict(t_dict *dict, int size)Pour le main et les tests
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%s", dict[i].nbr);
		printf(" => ");
		printf("%s", dict[i].str);
		printf("\n");
		i++;
	}
} */

/* void *main(int ac, char **av)
{
	int		i;
	char	*text;
	char	**tab;
	t_dict	*dico;

	i = 0;
	if (ac != 2)
		return (NULL);
	char *file_name = av[1];
	text = read_whole_file(file_name);
	if (!text)
		return (perror("read"), (NULL));
	tab = ft_split(text, " :\n");
	dico = malloc(sizeof(t_dict) * (ft_tablen(tab) / 2 + 1));
	while (i < ft_tablen(tab))
	{
		if (!tab[i + 1])
			break;
		dico[i / 2].nbr = ft_strdup(tab[i]);
		dico[i / 2].str = ft_strdup(tab[i + 1]);
		i += 2;
	}
	free(text);
	ft_free_tab(tab);
	print_dict(dico, i / 2);
	return (NULL);
} */
