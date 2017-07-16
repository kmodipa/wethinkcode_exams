/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:40:58 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/11 16:53:11 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int chars;

	chars = 0;
	if (argc != 2)
	{
		ft_putchar('\n');
	}
	else
	{
		while (argv[1][chars] != '\0')
		{
			if (ft_isalpha(argv[1][chars]) == 1)
			{
				if (argv[1][chars] == 'z' || argv[1][chars] == 'Z')
					ft_putchar(argv[1][chars] - 25);
				else
					ft_putchar(argv[1][chars] + 1);
			}
			else
				ft_putchar(argv[1][chars]);
			chars++;
		}
		ft_putchar('\n');
	}
	return (0);
}
