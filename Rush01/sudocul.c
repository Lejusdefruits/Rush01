#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
			count[0] = count[0] + 1;
		}
		if (ligne_plateau[3 - i] > val_max_rev)
		{
			val_max_rev = ligne_plateau[3 - i];
			count[1] = count[1] + 1;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (ligne_plateau[i] == 0)
			printf("%d", nb_tours_ref[1]);
1			return (count[0] <= nb_tours_ref[0] && count[1] <= nb_tours_ref[1]);
		i++;
	}
	return (count[0] == nb_tours_ref[0] && count[1] == nb_tours_ref[1]);
}

int main(void)
{
	int ligne_plateau[4] = {1, 2, 3, 0};
	int nb_tours_ref = {4, 1};
	printf("%d", verify_views(ligne_plateau, nb_tours_ref));
}
