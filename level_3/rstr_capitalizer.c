/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 17:23:12 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/16 18:49:52 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		iscapital(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

void	capitalizer(char *str)
{
	int index;
	int len;

	index = 0;
	len = ft_strlen(str) - 1;
	while (str[index] != '\0')
	{
		if (str[len] == 32 || str[len] == 9)
			ft_putchar(str[len]);
		else if ((str[len - 1] == 32 && str[len] != 32) ||
				(str[len - 1] == 9 && str[len] != 9))
		{
			ft_putchar(str[len] - 33);
		}
		else
			ft_putchar(str[len]);
		index++;
		len--;
	}
	ft_putchar('\n');
}

int		main(int c, char **v)
{
	int param;

	param = 1;
	if (c == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		while (v[param] != '\0')
		{
			capitalizer(v[param]);
			param++;
		}
	}
	return (0);
}
