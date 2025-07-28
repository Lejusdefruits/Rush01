/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_numbers_as_strings.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:29:33 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/27 20:22:13 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
int	ft_strlen(char *str);

int	compare_numbers_as_strings(char *a, char *b)
{
	int	length_a;
	int	length_b;

	length_a = ft_strlen(a);
	length_b = ft_strlen(b);
	if (length_a != length_b)
		return length_a - length_b;
	while (*a && *b)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}
