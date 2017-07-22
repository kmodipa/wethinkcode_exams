/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:29:01 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/22 17:53:30 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		word_count(char *str)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] != 32 && str[index] != 9)
		{
			if ((str[index - 1] == 32 || str[index -1] == 9) || 
					(index == 0 && str[index] != 32 && str[index] != 9))
				count++;
		}
		index++;
	}
	return (count);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char 	*ft_strsub(char *str, int start, int end)
{
	int		index;
	char	*sub;

	index = 0;
	if (!str)
		return (NULL);
	sub = (char *)malloc(sizeof(char *) * ft_strlen(str));
	while ((str[index] != '\0') && (start <= end))
	{
		sub[index] = str[start];
		start++;
		index++;
	}
	return (sub);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
	}
}

char	**ft_split(char *str)
{
	int		index;
	int		array_index;
	int		jump;
	char	**array;

	index = 0;
	array_index = 0;
	if (!str || !(array = (char **)malloc(sizeof(char *) * word_count(str))))
		return (NULL);
	while (str[index] == 32 || str[index] == 9)
		index++;
	while (str[index] != '\0')
	{
		if (str[index] != 32 && str[index] != 9)
		{
			if ((str[index - 1] == 32 || str[index - 1] == 9 ) || (index == 0 &&
							str[index] != 32 && str[index] != 9))
			{
				jump = 0;
				while (str[index + jump] != 32 && str[index + jump] != 9 && 
						str[index + jump] != '\0')
					jump++;
				array[array_index++] = ft_strsub(str, index, jump);
			}
		}
		index++;
		array[array_index] = 0;
	}
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
			ft_putstr(array[param]);
			param++;
		}
	}
	return (0);
}
