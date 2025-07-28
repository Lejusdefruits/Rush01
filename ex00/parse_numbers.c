#include "./includes/ft.h"

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

char	*get_word_for_number(t_dict *dictionary, int dict_size, char *number)
{
	int	index;

	index = 0;
	while (index < dict_size)
	{
		if (ft_strcmp(dictionary[index].nbr, number) == 0)
			return (dictionary[index].str);
		index++;
	}
	return (NULL);
}

int	is_all_zeros(char *text)
{
	while (*text)
	{
		if (*text != '0')
			return (0);
		text++;
	}
	return (1);
}

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
