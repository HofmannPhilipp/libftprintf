/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsignednbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:24:57 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/22 14:41:31 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static size_t	get_digit_count(int n)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

static void	convert_number_to_string(char *str, int n, size_t i)
{
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i --;
	}
}

int	ft_print_unsignednbr(unsigned int n)
{
	char	*result_str;
	size_t	len;
	int		write_count;

	write_count = 0;
	len = get_digit_count(n);
	result_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!result_str)
		return (-1);
	result_str[len] = '\0';
	convert_number_to_string(result_str, n, len - 1);
	write_count += ft_print_str(result_str);
	free(result_str);
	return (write_count);
}
int main(void)
{
	void *ptr;
	ptr = malloc(10);
	printf("%d\n",ft_printf("%u\n", 0));
	printf("%d\n",printf("%u\n",0));
	return 0;
}