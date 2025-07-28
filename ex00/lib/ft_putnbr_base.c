/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedavid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:26:30 by dedavid           #+#    #+#             */
/*   Updated: 2025/07/14 18:08:26 by dedavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	strhas(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int	base_is_valid(char *base)
{
	int	i;
	int	j;

	if (strhas(base, '-') || strhas(base, '+') || ft_strlen(base) <= 1)
		return (0);
	i = -1;
	while (base[++i] != '\0')
	{
		j = i;
		while (base[++j] != '\0')
		{
			if (base[j] == base[i])
				return (0);
		}
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len;
	long	l;

	if (!base_is_valid(base))
		return ;
	len = ft_strlen(base);
	l = nbr;
	if (l < 0)
	{
		ft_putchar('-');
		l *= -1;
	}
	if (l >= len)
	{
		ft_putnbr_base(l / len, base);
		ft_putnbr_base(l % len, base);
		return ;
	}
	ft_putchar(base[l]);
}
