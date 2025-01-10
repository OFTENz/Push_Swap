#include "push_swap.h"

static char	*ft_crtstr(char *s1, char c)
{
	char	*p;
	int		a;

	a = 0;
	while (s1[a] && s1[a] != c)
		a++;
	p = malloc(sizeof(char) * a + 1);
	a = 0;
	if (p == NULL)
		return (NULL);
	while (s1[a] && s1[a] != c)
	{
		p[a] = s1[a];
		a++;
	}
	p[a] = '\0';
	return (p);
}

static	void	ft_freeit(char **p)
{
	int	a;

	a = 0;
	while (p[a])
	{
		free(p[a]);
		a++;
	}
	free(p);
}

static char	**ft_alloc(int cnt, char *str, char c)
{
	int		a;
	int		fg;
	char	**p;
	int		e;

	a = 0;
	e = 0;
	fg = 1;
	p = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	p[cnt] = NULL;
	while (str[a])
	{
		if ((a && str[a] && str[a] != c && str[a - 1] == c)
			|| (a == 0 && str[a] != c))
		{
			p[e] = ft_crtstr(&str[a], c);
			if (!p[e++])
				ft_freeit(p);
		}
		a++;
	}
	return (p);
}

static int	ft_count_word(char *s, char c)
{
	int	i;
	int	a;
	int	k;

	i = 0 ;
	a = 0 ;
	k = 0 ;
	while (s[i])
	{
		if (s[i] == c)
			k = 1;
		if (s[i] && s[i] != c)
		{
			if (k == 1 || i == 0)
				a++;
			k = 0;
		}
		i++;
	}
	return (a);
}

char	**ft_split(char *s, char c)
{
	int		d;
	char	**p;

	if (!s)
		return (NULL);
	d = ft_count_word(s, c);
	p = ft_alloc(d, s, c);
	return (p);
}