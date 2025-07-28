/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_to_three_digits.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:30:53 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/27 20:22:24 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
int	ft_strlen(char *str);

char	*format_to_three_digits(char *digits)
{
	char	*formatted;

	formatted = malloc(4);
	if (!formatted)
		return (NULL);
	int length = ft_strlen(digits);
	if (length == 1)
		formatted[0] = '0', formatted[1] = '0', formatted[2] = digits[0];
	else if (length == 2)
		formatted[0] = '0', formatted[1] = digits[0], formatted[2] = digits[1];
	else
		formatted[0] = digits[0], formatted[1] = digits[1], formatted[2] = digits[2];
	formatted[3] = '\0';
	return (formatted);
}
