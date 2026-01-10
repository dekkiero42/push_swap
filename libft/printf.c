/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiletsk <dbiletsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:20:04 by marvin            #+#    #+#             */
/*   Updated: 2025/11/16 13:41:36 by dbiletsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_int(int n)
{
	char	*temp;
	int		len;

	temp = ft_itoa(n);
	len = ft_strlen(temp);
	write(1, temp, len);
	return (free(temp), len);
}

static int	print_hex(unsigned long long n, int b)
{
	char	*base;
	char	hex[17];
	int		i;

	if (n == 0)
		return (print_string("0"));
	if (b)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 15;
	ft_memset(hex, 0, sizeof(hex));
	while (n > 0)
	{
		hex[i--] = base[n % 16];
		n /= 16;
	}
	return (print_string(&hex[++i]));
}

static int	print_pointer(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		return (print_string("(nil)"));
	len = write(1, "0x", 2);
	len += print_hex(ptr, 0);
	return (len);
}

static int	handle_placeholder(va_list *arg, char format)
{
	if (format == 'c')
		return (print_char(va_arg(*arg, unsigned int)));
	else if (format == 's')
		return (print_string(va_arg(*arg, char *)));
	else if (format == 'd' || format == 'i')
		return (print_int(va_arg(*arg, int)));
	else if (format == 'u')
		return (print_uint(va_arg(*arg, unsigned int)));
	else if (format == 'x')
		return (print_hex(va_arg(*arg, unsigned int), 0));
	else if (format == 'X')
		return (print_hex(va_arg(*arg, unsigned int), 1));
	else if (format == 'p')
		return (print_pointer(va_arg(*arg, unsigned long long)));
	else
		return (write(1, "%", 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;

	if (!s || s[0] == '\0')
		return (0);
	va_start(args, s);
	len = 0;
	while (*s)
	{
		if (*s == '%' && are_in("cspdiuxX%",*(s + 1)))
		{
			len += handle_placeholder(&args, *(++s));
			s++;
			continue ;
		}
		len += write(1, s++, 1);
	}
	return (len);
}
