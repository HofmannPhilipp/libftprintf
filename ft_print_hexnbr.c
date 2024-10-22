/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:17:32 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/22 14:29:57 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexnbr(unsigned long n, int is_uppercase)
{
	char *hex_low = "0123456789abcdef";
	char *hex_up = "0123456789ABCDEF";
	int	write_count;

	write_count = 0;
	if (n < 16)
	{
		if (is_uppercase)
		{
			if (ft_print_char(hex_up[n]) == -1)
				return (-1);
		}
		else
		{
			if(ft_print_char(hex_low[n]) == -1)
				return (-1);
		}
		write_count++;
		return (write_count);
	}
	write_count += ft_print_hexnbr(n / 16, is_uppercase);
	if (is_uppercase)
	{
		if (ft_print_char(hex_up[n % 16]) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_char(hex_low[n % 16]) == -1)
			return (-1);
	}
	write_count++;
	return (write_count);
}
