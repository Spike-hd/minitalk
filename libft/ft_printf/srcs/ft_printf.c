/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hduflos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 08:54:07 by hduflos           #+#    #+#             */
/*   Updated: 2024/11/16 14:31:31 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	format_specifier(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (void_to_hexa(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (print_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (print_unbr(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (print_hexa(va_arg(args, int), c));
	else if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			count += format_specifier(str[i + 1], args);
			i += 2;
		}
		else
		{
			write(1, &str[i], 1);
			count++;
			i++;
		}
	}
	va_end (args);
	return (count);
}
