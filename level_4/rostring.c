/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:14:41 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/24 16:02:17 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

int        count_chars(char *str)
{
	int    index;
	int count;

	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] != 32 && str[index] != 9)
		{
			count++;
			if (str[index + 1] == 32 || str[index + 1] == 9)
				break ;
		}
		index++;
	}
	return (count);
}

char    *grab_word(char *str)
{
	int        len;
	char    	*word;
	int        index;
	int        insert;

	insert = 0;
	index = 0;
	len = count_chars(str);
	word = (char *)malloc(sizeof(word) * (len + 1));
	while (str[index] != '\0')
	{
		if (str[index] != 32 && str[index] != 9)
		{
			word[insert] = str[index];
			insert++;
			if (str[index + 1] == 32 || str[index + 1] == 9)
				break ;
		}
		index++;
	}
	word[insert] = '\0';
	free(word);
	return (word);
}

int        check_index(char *str)
{
	int index;

	index = 0;
	while (str[index] == 32)
	{
		index++;
	}
	return (index + count_chars(str));
}

void    ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

int     ft_strlen(char *str)
{
	int        len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int     end_of_str(char *str)
{
	int        end;

	end = ft_strlen(str) - 1;
	while (str[end] == 32)
		end--;
	return (end);
}

void    rostring(char *str)
{
	int		index;
	char	*word;
	int		len;

	len = ft_strlen(str) - 1;
	word = grab_word(str);
	index = check_index(str);
	while (str[index] != '\0')
	{
		if (str[index] != 32 && str[index] != 9)
		{
			if (str[index] != 32 && str[index] != 9)
				ft_putchar(str[index]);
			if ((str[index + 1] == 32 || str[index + 1] == 9) &&
					(str[index] != 32 || str[index] != 9))
			{
				if (index != end_of_str(str))
					ft_putstr(" ");
				else
					break;
			}
			else if (index == end_of_str(str))
				ft_putchar(32);
		}
		index++;
	}
}

int        main(int c, char **v)
{
	char *word;

	if (c < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		word = grab_word(v[1]);
		rostring(v[1]);
		ft_putstr(word);
	}
	ft_putchar('\n');
	return (0);
}
