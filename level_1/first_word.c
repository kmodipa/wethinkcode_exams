/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 11:30:42 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/11 16:35:43 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		main(int argc, char **argv)
{
	int chars;

	chars = 0;
	if (argc != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	else
	{
		if (ft_strlen(argv[1]) == 1)
		{
			ft_putchar('\n');
			return (0);
		}
		while (argv[1][chars] != '\0')
		{
			if (argv[1][chars] == 32 || argv[1][chars] == 9)
				chars++;
			else if ((argv[1][chars] != 32 && argv[1][chars + 1] == 32) || 
					(argv[1][chars] != 9 && argv[1][chars + 1] == 9))
			{
				ft_putchar(argv[1][chars]);
				break ;
			}
			else if (argv[1][chars] != 32 && argv[1][chars] != 9)
			{
				ft_putchar(argv[1][chars]);
				chars++;
			}
		}
		ft_putchar('\n');
	}
	return (0);
}
