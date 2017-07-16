/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 09:45:27 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/11 16:12:20 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int	chars;

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
			ft_putchar(argv[1][chars]);
			chars++;
		}
		ft_putchar('\n');
	}
	return (0);
}
