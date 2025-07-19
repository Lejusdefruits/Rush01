/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudocul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 00:33:57 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/19 17:53:18 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	*verify_views(int *ligne_plateau, int *nb_tours_ref)
{
	int	i;
	int	count[2];
	int	val_max;
	int	val_max_rev;

	i = 0;
	val_max = 0;
	val_max_rev = 0;
	while (i < 4)
	{
		if ((ligne_plateau[i] + '0') > val_max)
		{
			val_max = ligne_plateau[i] + '0';
			count[0]++;
		}
		if ((ligne_plateau[3 - i] + '0') > val_max_rev)
		{
			val_max_rev = ligne_plateau[3 - i] + '0';
			count[1]++;
		}
		i++;
	}
	if (count[0] <= nb_tours_ref[0] && count[1] <= nb_tours_ref[1])
		return (1);
	return (0);
}

int	solved_case(char **plateau, int *pos, char *entry_tab, int test_val)
{
	int	i;
	int	ligne_plateau[3];

	i = 0;
	while (i < 4)
	{
		ligne_plateau[i] = plateau[pos[0]][i] + '0';
		if (plateau[pos[0]][i] == test_val
				|| plateau[i][pos[1]] == test_val)
			return (0);
		i++;
	}
}

void	print_tab(char **plateau)
{
	int	i;
	int	j;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &plateau[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	placer_case(char **plateau, int *pos, char *entry_tab)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (solved_case(plateau, pos, entry_tab, i))
		{
			if (pos[0] == 3 && pos[1] == 3)
			{
				plateau[pos[0]][pos[1]] = i + '0';
				print_tab(plateau);
				free(plateau);
				return (0);
			}
			else if (pos[1] == 3)
			{
				pos[0]++;
				pos[1] = 0;
			}
			else
				pos[1]++;
			placer_case(plateau, pos, entry_tab);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*entry_tab;
	char	**plateau;
	int		i;
	int		j;

	i = 0;
	if (argc != 2)
		return (1);
	i = 0;
	plateau = (char **)malloc(sizeof(char) * 4);
	while (i < 4)
	{
		plateau[i] = malloc(4 * sizeof(char));
		j = 0;
		while (j < 4)
		{
			plateau[i][j] = '0';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < argc)
	{
		entry_tab[i] = argv[i];
		i++;
	}
}
