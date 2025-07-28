/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubrouss <jubrouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:29:24 by jubrouss          #+#    #+#             */
/*   Updated: 2025/07/27 20:44:06 by jubrouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft.h"

void print_group_in_words(char *digits, t_dict *dictionary, int dict_size)
{
	char	*exact_match;
	char	*three_digits;
	char	hundreds[2];
	char	teens[3];
	char	tens[3];
	char	ones[2];

	exact_match = get_word_for_number(dictionary, dict_size, digits);
	if (exact_match)
	{
		if (ft_strcmp(exact_match, "100") == 0)
			ft_putstr("one ");
		return ft_putstr(exact_match), ft_putstr(" ");
	}

	three_digits = format_to_three_digits(digits);
	if (!three_digits || ft_strcmp(three_digits, "000") == 0)
		return free(three_digits);

	if (three_digits[0] != '0')
	{
		hundreds[0] = three_digits[0];
		hundreds[1] = '\0';
		ft_putstr(ft_strcat(get_word_for_number(dictionary, dict_size, hundreds), " "));
		ft_putstr(ft_strcat(get_word_for_number(dictionary, dict_size, "100"), " "));
	}
	if (three_digits[1] == '1' && three_digits[2] != '0')
	{
		teens[0] = three_digits[1];
		teens[1] = three_digits[2];
		teens[1] = '\0';
		ft_putstr(ft_strcat(get_word_for_number(dictionary, dict_size, teens), " "));
	}
	else
	{
		if (three_digits[1] != '0')
		{
			tens[0] = three_digits[1];
			tens[1] = '0';
			tens[2] = '\0';
			ft_putstr(ft_strcat(get_word_for_number(dictionary, dict_size, tens), " "));
		}
		if (three_digits[2] != '0')
		{
			ones[0] = three_digits[2];
			ones[1] = '\0';
			ft_putstr(ft_strcat(get_word_for_number(dictionary, dict_size, ones), " "));
		}
	}
	free(three_digits);
}

void break_down_large_power(char *power, t_dict *dictionary, int dict_size)
{
	char	*direct_label;
	char	*remaining;
	char	*segments[MAX_PIECES];
	int		segment_count;
	char	*best_match_key;
	char	*best_match_word;
	int		index;

	direct_label = get_word_for_number(dictionary, dict_size, power);
	if (direct_label)
		return ft_putstr(ft_strcat(direct_label, " "));

	remaining = ft_strdup(power);
	if (!remaining)
		return;
	segment_count = 0;

	while (compare_numbers_as_strings(remaining, "1000") >= 0)
	{
		best_match_key = NULL;
		best_match_word = NULL;
		index = 0;
		while (index < dict_size)
		{
			if (dictionary[index].nbr[0] == '1' &&
				compare_numbers_as_strings(dictionary[index].nbr, remaining) <= 0 &&
				(!best_match_key || compare_numbers_as_strings(dictionary[index].nbr, best_match_key) > 0))
			{
				best_match_key = dictionary[index].nbr;
				best_match_word = dictionary[index].str;
			}
			index++;
		}
		if (!best_match_word)
			break;
		segments[segment_count++] = best_match_word;
		remaining[ft_strlen(remaining) - ft_strlen(best_match_key)] = '\0';
	}
	free(remaining);

	index = segment_count - 1;
	while (index >= 0)
	{
		ft_putstr(ft_strcat(segments[index], " "));
		index--;
	}
}

void convert_number_to_words(char *input, t_dict *dictionary, int dict_size)
{
	char	*simple_conversion;
	char	chunk[4];
	char	*power_string;
	char	*label;
	int		input_length;
	int		total_parts;
	int		leading_group_size;
	int		index;
	int		group_position;
	int		chunk_size;
	int		i;

	simple_conversion = get_word_for_number(dictionary, dict_size, input);
	if (simple_conversion)
		return ft_putstr(ft_strcat(simple_conversion, "\n"));
	input_length = ft_strlen(input);
	total_parts = (input_length + 2) / 3;
	leading_group_size = input_length % 3;
	if (leading_group_size == 0)
		leading_group_size = 3;

	index = 0;
	group_position = total_parts - 1;
	while (index < input_length)
	{
		if (index == 0)
			chunk_size = leading_group_size;
		else
			chunk_size = 3;
		i = 0;
		while (i < chunk_size)
		{
			chunk[i] = input[index + i];
			i++;
		}
		chunk[i] = '\0';
		if (!is_all_zeros(chunk))
		{
			print_group_in_words(chunk, dictionary, dict_size);
			if (group_position > 0)
			{
				power_string = create_power_string(group_position);
				label = get_word_for_number(dictionary, dict_size, power_string);
				if (label)
					ft_putstr(ft_strcat(label, " "));
				else
					break_down_large_power(power_string, dictionary, dict_size);
				free(power_string);
			}
		}
		index += chunk_size;
		group_position--;
	}
	ft_putstr("\n");
}
