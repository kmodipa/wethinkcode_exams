/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 15:14:41 by kmodipa           #+#    #+#             */
/*   Updated: 2017/08/02 16:22:16 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
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

char	*ft_strsub(char *str, int start, int end)
{
	char	*sub;
	int		index;

	index = 0;
	if (!(sub = (char *)malloc(sizeof(sub) * 255)))
		return (NULL);
	while (start <= end && str[index])
		sub[index++] = str[start++];
	sub[index] = '\0';
	free(sub);
	return (sub);
}

char    *grab_word(char *str)
{
	char	*word;
	int		start;
	int		end;
	int		len;

	len = ft_strlen(str) - 1;
	start = 0;
	while (str[start] == 32 || str[start] == 9)
		start++;
	end = start;
	while (str[end] != 32 && str[end] != 9 && end <= len)
		end++;
	word = ft_strsub(str, start, end - 1);
	return (word);
}

int     word_end(char *str)
{
	int     start;
	int     end;
	int		len;

	len = ft_strlen(str) - 1;
	start = 0;
	while (str[start] == 32 || str[start] == 9)
		start++;
	end = start;
	while (str[end] != 32 && str[end] != 9 && end <= len)
		end++;
	return (end);
}
void    rostring(char *str)
{
	int		index;
	int		end;

	end	= ft_strlen(str) - 1;
	index = word_end(str);
	while (str[end] == 32 || str[end] == 9)
		end--;
	while (str[index] == 32 || str[index] == 9)
		index++;
	while (str[index] != '\0')
	{
		if (str[index] != 32 && str[index] != 9)
		{
			if (str[index] != 32 && str[index] != 9)
				ft_putchar(str[index]);
			if (str[index + 1] == 32 || str[index + 1] == 9 || index == end)
				ft_putchar(32);
		}
		index++;
	}
}

int        main(int c, char **v)
{
	if (c < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		rostring(v[1]);
		ft_putstr(grab_word(v[1]));
	}
	ft_putchar('\n');
	return (0);
}
