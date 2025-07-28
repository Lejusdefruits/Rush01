/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:48:19 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/20 22:16:31 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		parse_entry(char *arg, char *entry_tab);
char	**init_plateau(void);
void	free_plateau(char **plateau);
int		placer_case(char **plateau, int row, int col, char *entry_tab);

void	free_plateau(char **plateau)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(plateau[i]);
		i++;
	}
	free(plateau);
}

char	**init_plateau(void)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * 4);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		tab[i] = malloc(sizeof(char) * 4);
		j = 0;
		while (j < 4)
		{
			tab[i][j] = '0';
			j++;
		}
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	char	**plateau;
	char	entry_tab[17];

	if (argc != 2)
	{
		write(1, "ERROR :Too many arguments\n", 26);
		return (1);
	}
	if (!parse_entry(argv[1], entry_tab))
		return (1);
	plateau = init_plateau();
	if (!plateau)
		return (1);
	if (!placer_case(plateau, 0, 0, entry_tab))
		write(1, "Error\n", 6);
	free_plateau(plateau);
	return (0);
}
