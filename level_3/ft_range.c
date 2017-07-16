/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 14:30:30 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/16 16:59:42 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int start, int end)
{
	int		*array;
	int		index;

	index = 0;
	if (start <= end)
	{
		array = (int *)malloc(sizeof(array) * (end - start));
		while (start <= end)
		{
			array[index] = start;
			start++;
			index++;
		}
	}
	else
	{
		array = (int *)malloc(sizeof(array) * (start - end));
		while (start >= end)
		{
			array[index] = start;
			start--;
			index++;
		}
	}
	return (array);
}

int		main(int c, char **v)
{
	int chars;
	int	*array;
	int start;
	int end;

	chars = 0;
	if (c != 3)
		return (0);
	else
	{
		array = ft_range(atoi(v[1]), atoi(v[2]));
		start = atoi(v[1]);
		end = atoi(v[2]);
		if (start <= end)
		{
			while (start <= end)
			{
				printf("%i\n", array[chars]);
				chars++;
				start++;
			}
		}
		else
		{
			while (start >= end)
			{
				printf("%i\n", array[chars]);
				chars++;
				start--;
			}
		}
	}
	return (0);
}
