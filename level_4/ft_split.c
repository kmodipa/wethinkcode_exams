/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 10:55:58 by kmodipa           #+#    #+#             */
/*   Updated: 2017/08/08 12:22:08 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strsub(char *str, int start, int end)
{
	int		index;
	char	*sub;

	index = 0;
	if (!(sub = (char *)malloc(sizeof(char *) * 255)))
		return (NULL);
	while (index <= end && str[start] != 10)
		sub[index++] = str[start++];
	sub[index] = '\0';
	return (sub);
}

int		word_count(char *str)
{
	int		index;
	int		count;

	count = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] != 32 && str[index] != 9 && str[index] != 10)
		{
			if (index == 0 && str[index] != 32 && str[index] != 9 && 
					str[index] != 10)
				count++;
			else if (str[index - 1] == 32 || str[index - 1] == 9)
				count++;
		}
		index++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int		index;
	char	**array;
	int		array_index;
	int		jump;

	index = 0;
	array_index = 0;
	if (!(array = (char **)malloc(sizeof(char **) * (word_count(str) + 1))))
		return (NULL);
	while (str[index])
	{
		if (str[index] != 32 && str[index] != 9 && str[index] != 10)
		{
			jump = 0;
			if ((str[index - 1] == 32 || str[index - 1] == 9) || 
					str[index - 1] == '\n' || 
					(index == 0 && str[index] != 32 && str[index] != 9))
			{
				while (str[index + jump] != 32 && str[index + jump] != 9 &&
						str[index + jump] != 10 && str[index + jump])
					jump++;
				array[array_index++] = ft_strsub(str, index, jump - 1);
			}
		}
		index++;
	}
	array[array_index] = 0;
	return (array);
}

int		main(int c, char **v)
{
	int		chars;
	int		param;
	char	**array;

	chars = 0;
	param = 0;
	if (c < 2)
		return (0);
	else
	{
		printf("%i words\n", word_count(v[1]));
		array = ft_split(v[1]);
		while (array[param] != 0)
		{
			printf("%s\n", array[param]);
			param++;
		}
	}
	return (0);
}
