/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsakar <emsakar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:42:26 by emsakar           #+#    #+#             */
/*   Updated: 2023/11/19 22:42:28 by emsakar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	ft_int(int c)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (c == 0)
		return (write(1, "0", 1));
	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	if (c < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		leng++;
		c *= -1;
	}
	if (c >= 10)
	{
		tmp = ft_int(c / 10);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (write(1, &"0123456789"[c % 10], 1) == -1)
		return (-1);
	return (leng + 1);
}

int	ft_unsigned(unsigned int c)
{
	unsigned int	leng;
	int				tmp;

	leng = 0;
	if (c >= 10)
	{
		tmp = ft_unsigned(c / 10);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (write(1, &"0123456789"[c % 10], 1) == -1)
		return (-1);
	return (leng + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i] != '\0')
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_hex(unsigned int d, char b)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (d >= 16)
	{
		tmp = ft_hex(d / 16, b);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (b == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[d % 16], 1) == -1)
			return (-1);
	}
	if (b == 'x')
	{
		if (write(1, &"0123456789abcdef"[d % 16], 1) == -1)
			return (-1);
	}
	return (leng + 1);
}

int	ft_point(unsigned long b, int i)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		leng += 2;
	}
	if (b >= 16)
	{
		tmp = ft_point(b / 16, i);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (write(1, &"0123456789abcdef"[b % 16], 1) == -1)
		return (-1);
	return (leng + 1);
}
