/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_power_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:26:12 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/27 20:21:25 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>

char	*create_power_string(int group_position)
{
	char	*power_string;
	int		i;

	power_string = malloc(group_position * 3 + 2);
	if (!power_string)
		return (NULL);
	power_string[0] = '1';
	i = 1;
	while (i <= group_position * 3)
	{
		power_string[i] = '0';
		i++;
	}
	power_string[group_position * 3 + 1] = '\0';
	return (power_string);
}
