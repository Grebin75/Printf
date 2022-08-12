/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:53:40 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/12 18:19:24 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	putn(unsigned long n, unsigned long base, char *s)
{
	int counter;
	
	counter = 0;
	if (n > (base - 1))
		counter += putn((n / base), base, s);
	write(1, &s[(n % base)], 1);
	return (counter + 1);
}

int	ihandler(long n, unsigned int flag)
{
	int	counter;
	int	sig;

	counter = 0;
	if (flag & FLAGSIG)
		counter += write(1, "+", 1);
	if (flag & FLAGSPACE)
		counter += write(1, " ", 1);
	sig = ((n > 0) - (n < 0));
	if (n < 0)
		counter += write(1, "-", 1);
	return (counter + putn(n * sig, 10, "0123456789"));
}

int	shandler(char c, char *s, char ischar)
{
	int	len;

	if (ischar)
		return (write(1, &c, 1));
	if (!s)
		return (write(1, "(null)", 6));
	len = -1;
	while (s[++len])
		;
	return (write(1, s, len));
}

unsigned int	flagshandler(const char *s, unsigned int flag)
{
	if (*s == '+' && (*(s + 1) == 'd' || *(s + 1) == 'i'))
	{
		if (flag & FLAGSPACE)
			flag = flag & !FLAGSPACE;
		flag = flag | FLAGSIG;
	}
	else if (*s == ' ' && (*(s + 1) == 'd' || *(s + 1) == 'i'))
	{
		if (flag & FLAGSIG)
			return (flag);
		else
			flag = flag | FLAGSPACE;
	}
	else if (*s == '#' && (*(s + 1) == 'X' || *(s + 1) == 'x'))
		flag = flag | FLAGPREFIX;
	return (flag);
}