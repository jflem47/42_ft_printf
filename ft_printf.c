/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:26:28 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/16 15:31:17 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	flag;

	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			flag = parse_format(str);
			print_factory(args, flag);
			str += 2;
		}
		else
		{
			ft_putchar_fd((char)*str, 1);
			str++;
		}
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("%x\n", "salut");
	printf("%%\n");
	ft_printf("%%\n");
	return (0);
}
