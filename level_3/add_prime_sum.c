/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmodipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:22:43 by kmodipa           #+#    #+#             */
/*   Updated: 2017/07/17 12:48:07 by kmodipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	char c;

	if (nbr >= 10)
	{
		ft_putnbr(nbr/10);
		ft_putnbr(nbr%10);
	}
	else
	{
		c = nbr + '0';
		ft_putchar(c);
	}
}

int		isprime(int nbr)
{
	int n;

	n = 2;
	while (n < nbr)
	{
		if (nbr % n == 0)
			return (0);
		n++;
	}
	return (1);
}

int	add_prime_sum(int nbr)
{
	int		num;
	int		prime;

	num = 2;
	while (num <= nbr)
	{
		if (isprime(num) == 1)
			prime = prime + num;
		num++;		
	}
	return (prime);
}

int		main(int c, char **v)
{
	if (c < 2 || atoi(v[1]) < 0)
	{
		ft_putchar('0');
	}
	else
	{
		ft_putnbr(add_prime_sum(atoi(v[1])));
	}
	ft_putchar('\n');
	return (0);
}
