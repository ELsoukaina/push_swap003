#include "push_swap.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dst && !size)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	if (size < i)
		i = size;
	j = 0;
	while ((int)(j) < (int)(size - i - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dst[i + j] = 0;
	return (i + ft_strlen((char *)src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (lensrc);
	while (size - 1 > i && lensrc > 0)
	{
		dst[i] = src[i];
		i++;
		lensrc--;
	}
	dst[i] = '\0';
	return (lensrc + i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isdigit(int d)
{
	if (d >= 48 && d <= 57)
		return (1);
	return (0);
}

void	minmax(long int res, int sign)
{
	res = sign * res;
	if (res > 2147483647 || res < -2147483648)
		parsingErr();
}

int	ft_atoi(const char *str)
{
	long int	i[3];

	i[0] = 0;
	i[1] = 1;//res
	i[2] = 0;//sign
	while (str[i[0]] == ' ' || str[i[0]] == '\f' || str[i[0]] == '\t'
		|| str[i[0]] == '\v' || str[i[0]] == '\n' || str[i[0]] == '\r')
		i[0]++;
	if (str[i[0]] == '-')
		i[1] = -1;
	if((str[i[0]] == '+' || str[i[0]] == '-') && str[i[0]+1] == '\0')
		parsingErr();
	else if (str[i[0]] == '+' || str[i[0]] == '-')
		i[0]++;
	while (str[i[0]] != '\0')
	{
		if (ft_isdigit(str[i[0]]) == 0)
			parsingErr();
		i[2] = i[2] * 10 + str[i[0]] - '0';
		i[0]++;
	}
	minmax(i[2], i[1]);
	return (i[2]*i[1]);
}