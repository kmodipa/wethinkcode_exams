/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 17:23:12 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/17 17:18:01 by kmodipa          ###   ########.fr       */
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

int		isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

void	capitalizer(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (isalpha(str[index]) == 1)
		{
			if (str[index] == 32 || str[index] == 9)
			{
				ft_putchar(str[index]);
			}
			else if ((str[index - 1] == 32 && str[index] != 32) ||
					(str[index - 1] == 9 && str[index] != 9))
			{
				if (str[index + 1] == 32 || str[index + 1] == 9)
				{
					if (iscapital(str[index]) == 1)
						ft_putchar(str[index]);
					else
						ft_putchar(str[index] - 32);
				}
				else if (index + 1== ft_strlen(str))
				{
					if (iscapital(str[index]) == 1)
						ft_putchar(str[index]);
					else
						ft_putchar(str[index] - 32);
				}
				else if (iscapital(str[index]) == 1)
					ft_putchar(str[index] + 32);
				else
					ft_putchar(str[index]);
			}
			else if ((str[index + 1] == 32 && str[index] != 32) ||
					(str[index + 1] == 9 && str[index] != 9))
			{
				if (iscapital(str[index]) == 1)
					ft_putchar(str[index]);
				else
					ft_putchar(str[index] - 32);
			}
			else if (iscapital(str[index]) == 1)
			{
				if (index + 1 == ft_strlen(str))
				{
					ft_putchar(str[index]);
				}
				else
					ft_putchar(str[index] + 32);
			}
			else
			{
				if (index == 0)
					ft_putchar(str[index] - 32);
				else if (index + 1 == ft_strlen(str))
				{
					if (iscapital(str[index]) == 1)
						ft_putchar(str[index]);
					else
						ft_putchar(str[index] - 32);
				}
				else
					ft_putchar(str[index]);
			}
		}
		else
			ft_putchar(str[index]);
		index++;
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
