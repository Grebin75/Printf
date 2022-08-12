/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:25:53 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/12 18:08:04 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define HEXUP			"0123456789ABCDEF"
# define HEXLOW			"0123456789abcdef"

# define FLAGSIG		0b1
# define FLAGSPACE		0b10
# define FLAG0			0b100
# define FLAGPREFIX		0b1000
# define FLAGLEFT		0b10000
# define PRECISION		

unsigned int	flagshandler(const char *s, unsigned int flag);
int	checkerpt2(char s, va_list *arg, unsigned int flag);
int	putn(unsigned long n, unsigned long base, char *s);
int	ihandler(long n, unsigned int flag);
int	shandler(char c, char *s, char ischar);
int	checker(char s, va_list *arg, unsigned int flag);
int	ft_printf(const char *s, ...);

#endif