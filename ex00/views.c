/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:48:30 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/20 22:17:37 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
			write(1, "ERROR :Invalid format of argument\n", 34);
			return (0);
		}
		k++;
	}
	entry_tab[16] = '\0';
	if (idx != 16)
	{
		write(1, "ERROR :Invalid length of argument\n", 34);
		return (0);
	}
	return (1);
}

int	verify_views(int *ligne_plateau, int *nb_tours_ref)
{
	int	i;
	int	count[2];
	int	val_max[2];

	val_max[0] = 0;
	val_max[1] = 0;
	count[0] = 0;
	count[1] = 0;
	i = -1;
	while (++i < 4)
	{
		if (ligne_plateau[i] >= val_max[0])
			val_max[0] = ligne_plateau[i];
		if (ligne_plateau[i] >= val_max[0])
			count[0] = count[0] + 1;
		if (ligne_plateau[3 - i] >= val_max[1])
			val_max[1] = ligne_plateau[3 - i];
		if (ligne_plateau[3 - i] >= val_max[1])
			count[1] = count[1] + 1;
	}
	i = -1;
	while (++i < 4)
		if (ligne_plateau[i] == 0)
			return (1);
	return (count[0] == nb_tours_ref[0] && count[1] == nb_tours_ref[1]);
}
