/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 17:06:21 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/08 10:28:35 by kmodipa          ###   ########.fr       */
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
	if (argc < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		while (argv[1][chars] != '\0')
		{
			if (ft_isalpha(argv[1][chars]) == 1)
			{
				if (argv[1][chars] >= 'A' && argv[1][chars] <= 'Z')
					ft_putchar('M' - (argv[1][chars] - 'N'));
				else if (argv[1][chars] >= 'a' && argv[1][chars] <= 'z')
						ft_putchar('m' - (argv[1][chars] - 'n'));
				else
					ft_putchar(argv[1][chars]);
			}
			else
				ft_putchar(argv[1][chars]);
			chars++;
		}
		ft_putchar('\n');
	}
	return (0);
}
