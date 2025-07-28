#include "./includes/ft.h"

static char	*find_best_match(char *remain, t_dict *dict, int size)
{
	char	*best;
	int		i;

	best = NULL;
	i = 0;
	while (i < size)
	{
		if (dict[i].nbr[0] == '1'
			&& compare_numbers_as_strings(dict[i].nbr, remain) <= 0
			&& (!best || compare_numbers_as_strings(dict[i].nbr, best) > 0))
			best = dict[i].nbr;
		i++;
	}
	return (best);
}

void	break_down_large_power(char *pow, t_dict *dict, int size)
{
	char	*label;
	char	*remain;
	char	*seg[MAX_PIECES];
	int		count;
	int		i;

	label = get_word_for_number(dict, size, pow);
	if (label)
		return (ft_putstr(ft_strcat(label, " ")));
	remain = ft_strdup(pow);
	if (!remain)
		return ;
	count = 0;
	while (compare_numbers_as_strings(remain, "1000") >= 0)
	{
		label = find_best_match(remain, dict, size);
		if (!label)
			break ;
		seg[count++] = get_word_for_number(dict, size, label);
		remain[ft_strlen(remain) - ft_strlen(label)] = '\0';
	}
	free(remain);
	i = count;
	while (--i >= 0)
		ft_putstr(ft_strcat(seg[i], " "));
}
