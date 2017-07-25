/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:05:03 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/24 14:52:42 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	epur_str(char *str)
{
	int		index;
	int		len;

	index = 0;
	len = ft_strlen(str) - 1;
	while (str[index] == 32 || str[index] == 9)
		index++;
	while (str[len] == 32 || str[len] == 9)
		len--;
	while (str[index])
	{
		if (str[index] != 32 && str[index] != 9)
		{
			if (str[index - 1] == 32 || str[index] == 9)
			{
				ft_putchar(str[index]);
			}
			else if ((str[index + 1] == 32 || str[index + 1] == 9) &&
					index != len)
			{
				ft_putchar(str[index]);
				ft_putchar(32);
			}
			else
				ft_putchar(str[index]);
		}
		index++;
	}
	ft_putchar('\n');
}

int		main(int c, char **v)
{
	int params;

	params = 1;
	if (c != 2)
		ft_putchar('\n');
	else
	{
		while (v[params])
		{
			epur_str(v[params]);
			params++;
		}
	}
	return (0);
}
