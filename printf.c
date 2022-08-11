/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:39:42 by hcoutinh          #+#    #+#             */
/*   Updated: 2022/08/11 17:35:54 by hcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int putn(unsigned long n, unsigned long base, char *s, int counter)
{
    if (n > (base - 1))
        counter += putn((n / base), base, s, 0);
    write(1, &s[(n % base)], 1);
    return (++counter);
}

int ihandler(long n)
{
    int counter;
    int sig;

    counter = 0;
    sig = ((n > 0) - (n < 0));
    if (n < 0)
        counter += write(1, "-", 1);
    return (counter + putn(n * sig, 10, "0123456789", 0));
}

int shandler(char c, char *s, char ischar)
{
    int len;

    if (ischar)
        return (write(1, &c, 1));
    if (!s)
        return (write(1, "(null)", 6));
    len = -1;
    while (s[++len])
        ;
    return (write(1, s, len));
}

int checker (char s, va_list *arg)
{
    void    *p;

    if (s == 'c')
        return (shandler(va_arg(*arg, int), NULL, 1));
    if (s == 's')
        return (shandler(0, va_arg(*arg, char *), 0));
    if (s == 'p')
    {
        p = va_arg(*arg, void *);
        if (!p)
            return (write(1, "(nil)", 5));
        return (write(1, "0x", 2) + putn((unsigned long)p, 16, "0123456789abcdef", 0));
    }
    if (s == 'd' || s == 'i')
        return (ihandler(va_arg(*arg, int)));
    if (s == 'u')
        return (putn(va_arg(*arg, unsigned), 10, "0123456789", 0));
    if (s == 'x')
        return(putn(va_arg(*arg, unsigned), 16, "0123456789abcdef", 0));
    if (s == 'X')
        return (putn(va_arg(*arg, unsigned), 16, "0123456789ABCDEF", 0));
    if (s == '%')
        return (write(1, "%", 1));
    return (0);
}

int ft_printf(const char *s, ...)
{
    va_list arg;
    int     counter;

    counter = 0;
    va_start(arg, s);
    while(s && *s)
    {
        if(*s == '%')
            counter += checker(*++s, &arg);
        else
            counter += write(1, s, 1);
        s++;
    }
    va_end(arg);
    return (counter);
}
