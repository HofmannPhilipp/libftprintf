/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexnbr_uppercase.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:19:37 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/22 16:30:16 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexnbr_uppercase(unsigned long n)
{
	char 	*hex = "0123456789ABCDEF";
	int		write_count;

	write_count = 0;
	if (n < 16)
	{
		if (ft_print_char(hex[n]) == -1)
			return (-1);
		return (1);
	}
	write_count += ft_print_hexnbr_uppercase(n / 16);
	if (ft_print_char(hex[n % 16]) == -1)
		return (-1);
	write_count++;
	return (write_count);
}
