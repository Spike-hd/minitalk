/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hduflos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:55:28 by hduflos           #+#    #+#             */
/*   Updated: 2024/11/16 14:45:41 by hduflos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}