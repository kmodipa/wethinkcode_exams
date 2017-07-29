/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 09:24:i52 by exam              #+#    #+#             */
/*   Updated: 2017/07/26 12:22:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

int		word_count(char *str)
{
	int		count;
	int		index;

	count = 0;
	index = 0;
	while (str[index] == 32 || str[index] == 9)
		index++;
	while (str[index])
	{
		if (str[index] != 32 || str[index] != 9)
		{
			if (index == 0 && str[index] != 32 && str[index] != 9)
				count++;
			else if (str[index - 1] == 32 || str[index - 1] == 9)
				count++;
		}
		index++;
	}
	return (count);
}

char	*ft_strsub(char *str, int start, int end)
{
	char	*new;
	int		index;

	index = 0;
	new = (char *)malloc(sizeof(char *) * 255);
	while (index < end && str[start])
	{
		new[index] = str[start];
		start++;
		index++;
	}
	return (new);
}

char	**ft_split(char *str)
{
	int		index;
	int		jump;
	char	**array;
	int		array_index;

	index = 0;
	array_index = 0;
	if (!(array = (char **)malloc(sizeof(char **) * 110)))
		return (NULL);
	while (str[index] == 32 || str[index] == 9)
		index++;
	while (str[index])
	{
		if (str[index] != 32 && str[index] != 9)
		{
			if ((str[index - 1] == 32 || str[index - 1] == 9) || 
					(index == 0 && str[index] != 32 && str[index] != 9))
			{
				jump = 0;
				while (str[index + jump] != 32 && str[index + jump] != 9 &&
						str[index + jump] != 0)
					jump++;
				array[array_index++] = ft_strsub(str, index, jump);
			}
		}
		index++;
	}
	array[array_index] = 0;
	free(array);
	return (array);
}

int		main(int c, char **v)
{
	char	**array;
	int		index;
	int		index2;
	int		count;

	index = 0;
	if (c != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		index2 = word_count(v[1]) - 1;
		count = word_count(v[1]);
		array = ft_split(v[1]);
		while (array[index])
		{
			if (count > 1)
			{
				if (index2 == count - 1)
				{
					ft_putstr(array[index2]);
					ft_putchar(32);
				}
				else if (index2 < count - 1 && index2 != 0)
				{
					ft_putstr(array[index2]);
					ft_putchar(32);
				}
				else if (index2 == 0)
					ft_putstr(array[index2]);
			}
			else if (count == 1)
				ft_putstr(array[index2]);
			index++;
			index2--;
		}
		ft_putchar('\n');
	}
	return (0);
}
