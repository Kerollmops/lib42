#include "stdlib_42.h"

char	*ft_utoa_base_r(char *buf, unsigned long long int n, int base)
{
	char	*charset;
	size_t	i;

	if (base < 0 || base > 16)
		return (NULL);
	charset = "0123456789abcdef";
	i = 0;
	if (n == 0)
		buf[i++] = '0';
	while (n != 0)
	{
		buf[i++] = charset[n % base];
		n /= base;
	}
	buf[i] = '\0';
	return (ft_strrev(buf));
}

char	*ft_utoa_base(unsigned long long int n, int base)
{
	char	*s;

	if (base < 0 || base > 16)
		return (NULL);
	if ((s = ft_memalloc(66)) == NULL)
		return (NULL);
	return (ft_utoa_base_r(s, n, base));
}

char	*ft_stoa_base_r(char *buf, long long int n, int base)
{
	char	*charset;
	size_t	i;
	int		neg;

	if (base < 0 || base > 16)
		return (NULL);
	charset = "0123456789abcdef";
	i = 0;
	neg = (n < 0);
	if (n == 0)
		buf[i++] = '0';
	while (n != 0)
	{
		buf[i++] = charset[FT_ABS(n % base)];
		n /= base;
	}
	buf[i] = (neg) ? '-' : '\0';
	return (ft_strrev(buf));
}

char	*ft_stoa_base(long long int n, int base)
{
	char	*s;

	if (base < 0 || base > 16)
		return (NULL);
	if ((s = ft_memalloc(67)) == NULL)
		return (NULL);
	return (ft_stoa_base_r(s, n, base));
}
