/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 10:45:31 by exam              #+#    #+#             */
/*   Updated: 2017/07/12 12:20:12 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		isupper(int c)
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

void	ft_capital(char *str)
{
	int index;

	index = 0;
	if (!str)
		return ;
	while (str[index] != '\0')
	{
		if (isalpha(str[index]) == 1)
		{
			if (str[index - 1] == 32 || str[index - 1] == 9)
			{
				if (isupper(str[index]) == 1)
					ft_putchar(str[index]);
				else
					ft_putchar(str[index] - 32);
			}
			else if (isupper(str[index]) == 1)
			{
				if (index == 0)
					ft_putchar(str[index]);
				else
					ft_putchar(str[index] + 32);
			}
			else if (isupper(str[index]) != 1)
			{
				if (index == 0)
					ft_putchar(str[index] - 32);
				else
					ft_putchar(str[index]);
			}
			else
				ft_putchar(str[index]);
		}
		else
			ft_putchar(str[index]);
		index++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int params;

	params = 1;
	if (argc == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		while (argv[params] != NULL)
		{
			ft_capital(argv[params]);
			params++;
		}
	}
	return (0);
}
