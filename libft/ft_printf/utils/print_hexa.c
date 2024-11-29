/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hduflos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:10:58 by hduflos           #+#    #+#             */
/*   Updated: 2024/11/16 15:47:13 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	recursive_print_hexa(unsigned long n, char *base)
{
	if (n >= 16)
		recursive_print_hexa(n / 16, base);
	write(1, &base[n % 16], 1);
}

static int	count_hexa(unsigned long n)
{
	int	count;

	count = 1;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	print_hexa(int n, char c)
{
	int				count;
	unsigned long	nb;

	count = 0;
	nb = (unsigned long)n & 0xFFFFFFFF;
	count += count_hexa(nb);
	if (c == 'x')
		recursive_print_hexa(nb, "0123456789abcdef");
	else if (c == 'X')
		recursive_print_hexa(nb, "0123456789ABCDEF");
	return (count);
}

int	void_to_hexa(void *p)
{
	unsigned long	i;
	int				count;

	i = (unsigned long)p;
	if (p == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = 2 + count_hexa(i);
	recursive_print_hexa(i, "0123456789abcdef");
	return (count);
}

/*
#include <stdio.h>
#include <limits.h>

int	main()
{
	printf("Mon print :");
	print_hexa(-1, 'x');
	printf("\n");
	printf("True print:");
	printf("%x", -1);
	printf("\n");
	printf("%x", INT_MIN);
	printf("\n");
	print_hexa(INT_MIN, 'x');
	return (0);
}
*/
