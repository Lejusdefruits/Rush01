/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudocul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejusdefruits <lejusdefruits@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 00:33:57 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/20 15:41:12 by lejusdefrui      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	verify_views(int *ligne_plateau, int *nb_tours_ref)
{
	int	i;
	int	count[2];
	int	val_max;
	int	val_max_rev;

	count[0] = 0;
	count[1] = 0;
	i = 0;
	val_max = 0;
	val_max_rev = 0;
	while (i < 4)
	{
		if (ligne_plateau[i] > val_max)
		{
			val_max = ligne_plateau[i];
			count[0]++;
		}
		if (ligne_plateau[3 - i] > val_max_rev)
		{
			val_max_rev = ligne_plateau[3 - i];
			count[1]++;
		}
		i++;
	}
	if (count[0] <= nb_tours_ref[0] && count[1] <= nb_tours_ref[1])
		return (1);
	return (0);
}


int solved_case(char **plateau, int *pos, char *entry_tab, int test_val)
{
	int i;
	int ligne_plateau[4];
	int colonne_plateau[4];
	int views[2][2];

	i = 0;
	while (i < 4)
	{
		if (plateau[pos[0]][i] == test_val + '0' || plateau[i][pos[1]] == test_val + '0')
			return 0;
		ligne_plateau[i] = plateau[pos[0]][i] - '0';
		colonne_plateau[i] = plateau[i][pos[1]] - '0';
		views[i > 1][i % 2 == 1] = entry_tab[i * 4 + pos[i < 2]] - '0';
		i++;
	}
	ligne_plateau[pos[1]] = test_val;
	colonne_plateau[pos[0]] = test_val;
	if (pos[1] == 3 && !verify_views(ligne_plateau, views[0]))
		return 0;
	if (pos[0] == 3 && !verify_views(colonne_plateau, views[1]))
		return 0;
	return 1;
}

void	print_tab(char **plateau)
{
	int	i;
	int	j;

	i = 0;
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
				placer_case(plateau, (pos[0]+ 1, pos[1] - 3), entry_tab);
			}
			else
				placer_case(plateau, (pos[0], pos[1] + 1), entry_tab);

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
