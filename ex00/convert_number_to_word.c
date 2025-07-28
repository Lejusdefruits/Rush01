#include "./includes/ft.h"

static void	print_power(int pos, t_dict *dict, int size)
{
	char	*pow;
	char	*label;

	pow = create_power_string(pos);
	if (!pow)
		return ;
	label = get_word_for_number(dict, size, pow);
	if (label)
		ft_putstr(ft_strcat(label, " "));
	else
		break_down_large_power(pow, dict, size);
	free(pow);
}

void	convert_number_to_words(char *input, t_dict *dict, int size)
{
	char	chunk[4];
	int		len;
	int		total;
	int		group;
	int		i;
	int		j;

	if ((len = ft_strlen(input)) == 0)
		return ;
	if (get_word_for_number(dict, size, input))
		return (ft_putstr(ft_strcat(get_word_for_number(dict, size, input), "\n")));
	total = (len + 2) / 3;
	group = total - 1;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (i == 0 && len % 3 ? len % 3 : 3))
		{
			chunk[j] = input[i + j];
			j++;
		}
		chunk[j] = '\0';
		if (!is_all_zeros(chunk))
		{
			print_group_in_words(chunk, dict, size);
			if (group > 0)
				print_power(group, dict, size);
		}
		i += j;
		group--;
	}
	ft_putstr("\n");
}