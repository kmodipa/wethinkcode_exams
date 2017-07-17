/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 09:20:23 by exam              #+#    #+#             */
/*   Updated: 2017/07/12 09:32:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	char alph;

	alph = 'a';
	while (alph <= 'z')
	{
		if (alph % 2 != 0)
			ft_putchar(alph);
		else
			ft_putchar(alph - 32);
		alph++;
	}
	ft_putchar('\n');
	return (0);
}
