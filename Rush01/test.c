#include <unistd.h>
#include <stdlib.h>

int verify_views(int *ligne_plateau, int *nb_tours_ref)
{
	int i;
	int count[2] = {0, 0};
	int val_max = 0, val_max_rev = 0;
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
	for (i = 0; i < 4; i++)
		if (ligne_plateau[i] == 0)
			return (count[0] <= nb_tours_ref[0] && count[1] <= nb_tours_ref[1]);
	return (count[0] == nb_tours_ref[0] && count[1] == nb_tours_ref[1]);
}

int solved_case(char **plateau, int row, int col, char *entry_tab, int test_val)
{
	int i;
	int ligne_plateau[4];
	int colonne_plateau[4];
	int views[2][2];

	i = 0;
	while (i < 4)
	{
		if (plateau[row][i] == test_val + '0' || plateau[i][col] == test_val + '0')
			return 0;
		ligne_plateau[i] = plateau[row][i] - '0';
		colonne_plateau[i] = plateau[i][col] - '0';
		views[i > 1][i % 2 == 1] = entry_tab[i * 4 + pos[i < 2]] - '0';
		i++;
	}
	ligne_plateau[col] = test_val;
	colonne_plateau[row] = test_val;
	if (verify_views(ligne_plateau, views[0]))
		return 0;
	if (verify_views(colonne_plateau, views[1]))
		return 0;
	return 1;
}

void print_tab(char **plateau)
{
	int i = 0, j;
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

int placer_case(char **plateau, int row, int col, char *entry_tab)
{
	int val;

	if (row == 4)
	{
		print_tab(plateau);
		return (1);
	}
	print_tab(plateau);
	val = 1;
	while (val <= 4)
	{
		if (solved_case(plateau, row, col, entry_tab, val))
		{
			plateau[row][col] = val + '0';
			if (col == 3)
			{
				if (placer_case(plateau, row + 1, 0, entry_tab))
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

int main(int argc, char **argv)
{
	char **plateau;
	char entry_tab[17];
	int i, j, idx, k;

	if (argc != 2)
		return (1);

	//retirer les espaces
	idx = 0;
	k = 0;
	while (argv[1][k] && idx < 16)
	{
		if (argv[1][k] >= '1' && argv[1][k] <= '4')
			entry_tab[idx++] = argv[1][k];
		else if (argv[1][k] != ' ')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		k++;
	}
	entry_tab[16] = '\0';
	if (idx != 16)
	{
		write(1, "Error\n", 6);
		return (1);
	}

	//initialiser le plateau
	plateau = malloc(4 * sizeof(char *));
	i = 0;
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

	//précondition
	if (!placer_case(plateau, 0, 0, entry_tab))
		write(1, "Error\n", 6);

	//libération mémoire
	i = 0;
	while (i < 4)
		free(plateau[i++]);
	free(plateau);

	return (0);
}
