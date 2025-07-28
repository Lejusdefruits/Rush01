/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:48:24 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/20 22:10:50 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_tab(char **plateau);
int		verify_views(int *ligne_plateau, int *nb_tours_ref);

int	solved_case(char **plateau, int *pos, char *entry_tab, int test_val)
{
	int	i;
	int	ligne_plateau[4];
	int	colonne_plateau[4];
	int	views[2][2];

	i = 0;
	while (i < 4)
	{
		if (plateau[pos[0]][i] == test_val + '0'
			|| plateau[i][pos[1]] == test_val + '0')
			return (0);
		ligne_plateau[i] = plateau[pos[0]][i] - '0';
		colonne_plateau[i] = plateau[i][pos[1]] - '0';
		views[i > 1][i % 2 == 1] = entry_tab[i * 4 + pos[i < 2]] - '0';
		i++;
	}
	ligne_plateau[pos[1]] = test_val;
	colonne_plateau[pos[0]] = test_val;
	return (verify_views(ligne_plateau, views[1])
		&& verify_views(colonne_plateau, views[0]));
}

int	placer_case(char **plateau, int row, int col, char *entry_tab)
{
	int	val;
	int	pos[2];

	if (row == 4)
		print_tab(plateau);
	if (row == 4)
		return (1);
	pos[0] = row;
	pos[1] = col;
	val = 0;
	while (++val <= 4)
	{
		if (solved_case(plateau, pos, entry_tab, val))
		{
			plateau[row][col] = val + '0';
			if (col == 3 && placer_case(plateau, row + 1, col - 3, entry_tab))
				return (1);
			else
				if (placer_case(plateau, row, col + 1, entry_tab))
					return (1);
			plateau[row][col] = '0';
		}
	}
	return (0);
}
