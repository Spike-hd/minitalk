/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hduflos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:04:00 by hduflos           #+#    #+#             */
/*   Updated: 2024/11/16 14:49:35 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

static void	ft_putunbr(unsigned int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	print_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_putnbr(n);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	print_unbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_putunbr(n);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/*
#include <stdio.h>
#include <unistd.h>
int	main()
{
	int n = -123456;
	unsigned int i = 4294967295;
	printf("\n%d", print_nbr(n));
	printf("\n");
	printf("\n%u", print_unbr(i));
}
*/
