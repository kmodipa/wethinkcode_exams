/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 10:19:21 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/04 10:40:57 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	int num;

	num = '0';
	while (num <= '9')
	{
		ft_putchar(num);
		num++;
	}
}

int		main(void)
{
	ft_print_numbers();
	return (0);
}
