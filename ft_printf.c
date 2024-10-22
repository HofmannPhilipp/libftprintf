/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 19:13:27 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/22 15:10:49 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format_specifier(char c, va_list ap)
{
	int	write_count;
	int	temp;

	write_count = 0;
	if (c == 'd' || c == 'i')
	{
		temp = ft_print_nbr(va_arg(ap, int));
		if (temp == -1)
			return (-1);
		write_count +=temp;
	}
	if (c == 's')
	{
		temp = ft_print_str(va_arg(ap, char*));
		if (temp == -1)
			return (-1);
		write_count +=temp;
	}
	if (c == 'c')
	{
		if (ft_print_char(va_arg(ap, int)) == -1)
			return (-1);
		write_count++;
	}
	if (c == '%')
	{
		if (ft_print_char('%') == -1)
			return (-1);
		write_count++;
	}
	if (c == 'x')
	{
		temp = ft_print_hexnbr(va_arg(ap, unsigned int), 0);
		if (temp == -1)
			return (-1);
		write_count += temp;
	}
	if (c == 'X')
	{
		temp = ft_print_hexnbr(va_arg(ap, unsigned int), 1);
		if (temp == -1)
			return (-1);
		write_count += temp;
	}
	if (c == 'p')
	{
		if(ft_print_str("0x") == -1)
			return (-1);
		write_count += 2;
		temp = ft_print_hexnbr(va_arg(ap, unsigned long),0);
		if (temp == -1)
			return (-1);
		write_count += temp;
	}
	if (c == 'u')
	{
		temp = ft_print_unsignednbr(va_arg(ap, unsigned int));
		if (temp == -1)
			return (-1);
		write_count += temp;
	}
	return (write_count);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	ap;
	int	i;
	int	count;

	va_start(ap, format_str);

	i = 0;
	count = 0;
	while (format_str[i])
	{
		if (format_str[i] != '%')
		{
			if (ft_print_char(format_str[i]) == -1)
				return (-1);
			count++;
		}
		if (format_str[i] == '%' && format_str[i + 1] != '\0')
		{
			i ++;
			count += print_format_specifier(format_str[i], ap);
		}
		i ++;
	}
	va_end(ap);

	return (count);
}

// int main(void)
// {
// 	void *ptr;
// 	ptr = malloc(10);
// 	printf("%d\n",ft_printf("\n"));
// 	printf("%d\n",printf("%s\n", 0));
// }
