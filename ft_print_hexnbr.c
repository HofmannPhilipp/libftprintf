/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:17:32 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/22 16:39:37 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexnbr(unsigned long n, char *hex_format)
{
	int		write_count;

	write_count = 0;
	if (n < 16)
	{
		if (ft_print_char(hex_format[n]) == -1)
			return (-1);
		return (1);
	}
	write_count += ft_print_hexnbr(n / 16, hex_format);
	if (ft_print_char(hex_format[n % 16]) == -1)
		return (-1);
	write_count++;
	return (write_count);
}
