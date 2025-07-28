/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 06:44:44 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/27 18:07:34 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

int	ft_dictlen(t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].nbr && dict[i].str)
		i++;
	return (i);
}

void	ft_free_dict(t_dict *dict, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(dict[i].nbr);
		free(dict[i].str);
		i++;
	}
	free(dict);
}

int	main(int ac, char **av)
{
	t_dict	*dico;
	int		size;

	if (ac != 2)
		return (ft_putstr("entry: ./main <number>\n"), 1);
	dico = parse_readed_file("numbers.dict");
	if (!dico)
		return (1);
	size = ft_dictlen(dico);
	convert_number_to_words(av[1], dico, size);
	ft_free_dict(dico, size);
	return (0);
}
