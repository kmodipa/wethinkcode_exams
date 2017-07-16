/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 10:44:42 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/11 16:20:35 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int chars;

	chars = 0;
	if (argc < 2)
	{
		ft_putchar('z');
		ft_putchar('\n');
	}
	else
	{
		while (argv[1][chars] != '\0')
		{
			if (argv[1][chars] == 'z')
			{
				ft_putchar(argv[1][chars]);
				return (0);
			}
			else
			{
				ft_putchar('z');
				return (0);
			}
			chars++
		}
		ft_putchar('\n');
	}
	return (0);
}
