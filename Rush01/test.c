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

int main(void)
{
	solved_case(plateau, pos, entry_tab, test_val)
}
