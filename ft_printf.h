/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:31:17 by phhofman          #+#    #+#             */
/*   Updated: 2024/10/22 16:32:04 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>


int	ft_print_unsignednbr(unsigned int n);
int	ft_print_str(char *s);
int	ft_print_nbr(int n);
int	ft_print_char(char c);
int	ft_printf(const char *fromat_str, ...);
int	ft_print_hexnbr(unsigned long n);
int	ft_print_hexnbr_uppercase(unsigned long n);

#endif
