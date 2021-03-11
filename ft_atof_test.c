/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:57:47 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/03/12 00:30:29 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>


size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i] )
		i++;
	return (i);
}

int atof_test(int i, char *s)
{
	int 	res;
	char	buft[2000];
	char 	libuf[2000];
	double	d;

	printf("=============%02d=============\n", i);
	if (((d = ft_atof(s)) == INFINITY))
	// if (!((d = ft_atof(s, 'd'))))
		return (puts("            \x1b[32merr\x1b[39m\n"));
	sprintf(buft, "%.1500g", d);
	sprintf(libuf, "%.1500g", atof(s));
	printf("%.1500g\n", d);
	// printf("%.1500g\n\n", atof(s));
	if ((res = ft_strcmp(libuf, buft)) < 15 && (size_t)res < ft_strlen(libuf))
		return (printf("result    : \x1b[31m[KO]\n\x1b[39mprecision : %3d\n\n", res));
	return (printf("result    : \x1b[32m[OK]\n\x1b[39mprecision : %3d\n\n", res));
}

int main()
{
	char buf[2000];
	char buf2[100];

	sprintf(buf, "%.1500f", DBL_MIN);
	atof_test(0, buf);
	sprintf(buf, "%.1500f", DBL_MIN / 1000000);
	atof_test(1, buf);
	sprintf(buf, "%.0f", DBL_MAX);
	atof_test(2, buf);
	atof_test(3, "0");
	atof_test(4, "1");
	atof_test(5, "100");
	atof_test(6, "12345");
	atof_test(7, "1.1");
	atof_test(8, "0.1");
	atof_test(9, "0.01");
	atof_test(10, "-0.01");
	atof_test(11, "-1.01");
	atof_test(12, "-100.01");
	atof_test(13, "-100");
	sprintf(buf2, "%d", INT_MAX);
	// printf("%d\n", INT_MAX);
	atof_test(14, buf2);
	sprintf(buf2, "%d", INT_MIN);
	atof_test(15, buf2);
	// printf("%d\n", INT_MIN);
	atof_test(16, "0.0");

	puts("\n\n=====================================");
	puts("===============error=================");
	puts("=====================================\n");
	atof_test(0, "01");
	atof_test(1, "001");
	atof_test(2, "1.");
	atof_test(3 ,"1..");
	atof_test(4, "0.");
	atof_test(5, "1a");
	atof_test(6, "a1");
	atof_test(7, "1.a");
	atof_test(8, "1.1a");
	atof_test(9, "1.1a1");
	atof_test(10, "1.a.1");
	atof_test(11, "1...1");
	atof_test(12, "1...1.");
	atof_test(13, ".");
	buf[0] = '9';
	atof_test(14, buf);
	atof_test(15, "+100");
	atof_test(16, "-");
	atof_test(17, "+");
	atof_test(18, "...");
	atof_test(19, "00");
	atof_test(20, "");
	atof_test(21, "-0.0");
	atof_test(22, "-0");
	atof_test(23, "-00");
	atof_test(24, "-.");
	atof_test(25, "-.1");
	atof_test(26, "-1.");
	atof_test(27, ".1");
	atof_test(28, ".1a");
	atof_test(29, ".a1");
	atof_test(30, "-a");
	atof_test(31, "+a");
	atof_test(32, "1.1.");
	atof_test(33, "1.1.1");
	atof_test(34, "1-");
	atof_test(35, "--1");
	atof_test(36, "-+1");
	atof_test(37, "+-1");
	atof_test(38, "1..1");
	atof_test(39, "--");
	atof_test(40, "++");
	atof_test(41, "\"");
	atof_test(42, "\'");
	atof_test(43, "..");
	atof_test(44, NULL);
}