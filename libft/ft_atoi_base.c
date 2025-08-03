#include "libft.h"

static int	strlenspc(const char *str)
{
	int	len;

	len = 0;
	while (str[len] == ' ' || (str[len] >= 9 && str[len] <= 13))
		len++;
	return (len);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int			result;
	int			i;
	signed char	a;
	int			digit;

	result = 0;
	i = 0 + strlenspc(str);
	a = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			a = -1;
		i++;
	}
	while (ft_strchr(base, str[i]) != NULL)
    {
        digit = ft_strchr(base, str[i]) - base;
        if (digit < 0 || digit >= (int)ft_strlen(base))
            return (0); // Invalid character for the base
		result = result * ft_strlen(base) + digit;
		i++;
	}
	return (result * a);
}
