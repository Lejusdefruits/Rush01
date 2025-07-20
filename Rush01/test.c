#include <unistd.h>
#include <stdlib.h>

int	verify_views(int *ligne_plateau, int *nb_tours_ref)
{
	int	i;
	int	count[2];
	int	val_max;
	int	val_max_rev;

	val_max = 0;
	val_max_rev = 0;
	count[0] = 0;
	count[1] = 0;
	i = 0;
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
	i = 0;
	while (i < 4)
	{
		if (ligne_plateau[i] == 0)
			return (count[0] <= nb_tours_ref[0] && count[1] <= nb_tours_ref[1]);
		i++;
	}
	return (count[0] == nb_tours_ref[0] && count[1] == nb_tours_ref[1]);
}

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
	return (!(verify_views(ligne_plateau, views[0])
			|| verify_views(colonne_plateau, views[1])));
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
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	placer_case(char **plateau, int row, int col, char *entry_tab)
{
	int	val;
	int	pos[2];

	if (row == 4)
	{
		print_tab(plateau);
		return (1);
	}
	pos[0] = row;
	pos[1] = col;
	print_tab(plateau);
	val = 1;
	while (val <= 4)
	{
		if (solved_case(plateau, pos, entry_tab, val))
		{
			plateau[row][col] = val + '0';
			if (col == 3)
			{
				if (placer_case(plateau, row + 1, col - 3, entry_tab))
					return (1);
			}
			else
			{
				if (placer_case(plateau, row, col + 1, entry_tab))
					return (1);
			}
			plateau[row][col] = '0';
		}
		val++;
	}
	return (0);
}
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
int	parse_entry(char *arg, char *entry_tab)
{
	int	idx;
	int	k;

	idx = 0;
	k = 0;
	while (arg[k] && idx < 16)
	{
		if (arg[k] >= '1' && arg[k] <= '4')
			entry_tab[idx++] = arg[k];
		else if (arg[k] != ' ')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		k++;
	}
	entry_tab[16] = '\0';
	if (idx != 16)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char	**plateau;
	char	entry_tab[17];
	int i;
	int j;

	if (argc != 2)
		return (1);
	if (!parse_entry(argv[1], entry_tab));
		return (1);
	plateau = init_plateau();
	if (!plateau)
		return (1);
	if (!placer_case(plateau, 0, 0, entry_tab))
		write(1, "Error\n", 6);
	free_plateau(plateau);
	return (0);
}
