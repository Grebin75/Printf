/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:39:42 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/12 18:24:47 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	checker(char s, va_list *arg, unsigned int flag)
{
	void	*p;

	if (s == 'c')
		return (shandler(va_arg(*arg, int), NULL, 1));
	if (s == 's')
		return (shandler(0, va_arg(*arg, char *), 0));
	if (s == 'p')
	{
		p = va_arg(*arg, void *);
		if (!p)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + putn((unsigned long)p, 16, HEXLOW));
	}
	if (s == 'd' || s == 'i')
		return (ihandler(va_arg(*arg, int), flag));
	if (s == 'u')
		return (putn(va_arg(*arg, unsigned), 10, "0123456789"));
	if (s == '%')
		return (write(1, "%", 1));
	return (checkerpt2(s, &*arg, flag));
}

int	checkerpt2(char s, va_list *arg, unsigned int flag)
{
	unsigned x;

	x = va_arg(*arg, unsigned);
	if (s == 'x') 
	{
		if (flag & FLAGPREFIX && x != 0)
			return(write(1, "0x", 2) + putn(x, 16, HEXLOW));
		return (putn(x, 16, HEXLOW));
	}
	if (s == 'X')
	{
		if (flag & FLAGPREFIX && x != 0)
			return(write(1, "0X", 2) + putn(x, 16, HEXUP));
		return (putn(x, 16, HEXUP));
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list			arg;
	int				counter;
	unsigned int	flag;

	flag = 0;
	counter = 0;
	va_start (arg, s);
	while (s && *s)
	{
		if (*s == '%')
		{
			while(*(s + 1) == '+' || *(s + 1) == ' ' || *(s + 1) == '#')
				flag = flagshandler(++s, flag);
			counter += checker(*++s, &arg, flag);
		}
		else
			counter += write(1, s, 1);
		s++;
	}
	va_end(arg);
	return (counter);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("Valor: %#X\n", 10);
}