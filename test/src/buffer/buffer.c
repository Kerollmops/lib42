#include "header.h"

void	test_00_buffer_init_zero(void)
{
	size_t size = 0;
	t_buffer b;
	ft_buffer_init(&b, size);
	v_assert_size_t(BUFFER_INIT_SIZE, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(0UL, ==, FT_BUFFER_LEN(&b));
	v_assert(b.str != NULL);

	FT_BUFFER_FREE(&b);

	VTS;
}

void	test_01_buffer_init_size(void)
{
	size_t size = 12;
	t_buffer b;
	ft_buffer_init(&b, size);
	v_assert_size_t(size, ==, FT_BUFFER_MAX(&b));
	v_assert_size_t(0UL, ==, FT_BUFFER_LEN(&b));
	v_assert(b.str != NULL);

	FT_BUFFER_FREE(&b);

	VTS;
}

void	test_02_buffer_add_simple(void)
{
	char	*s = "Hello World!";
	size_t	l = strlen(s);
	t_buffer b;

	ft_buffer_init(&b, 0);
	ft_buffer_add(&b, s, l);
	v_assert_size_t(l, ==, FT_BUFFER_LEN(&b));
	v_assert_size_t(BUFFER_INIT_SIZE, ==, FT_BUFFER_MAX(&b));
	v_assert_str(s, b.str);

	FT_BUFFER_FREE(&b);

	VTS;
}

void	test_03_buffer_add_limit(void)
{
	char	*s = "Hello World!";
	size_t	l = strlen(s);
	t_buffer b;

	ft_buffer_init(&b, 12);
	ft_buffer_add(&b, s, l);
	v_assert_size_t(l, ==, FT_BUFFER_LEN(&b));
	v_assert_size_t(12 * BUFFER_GROWTH_FACTOR, ==, FT_BUFFER_MAX(&b));
	v_assert_str(s, b.str);

	FT_BUFFER_FREE(&b);

	VTS;
}

void	test_04_buffer_add_resize(void)
{
	t_buffer	b;
	size_t		initsize;
	/* char		*oldstr; */
	char		a[300];
	size_t		alen;
	char		m[3000];
	size_t		mlen;
	char		z[4000];
	/* size_t		zlen; */

	memset(a, 'a', sizeof(a));
	memset(m, 'm', sizeof(m));
	memset(z, 0, sizeof(z));
	a[299] = 0;
	m[2999] = 0;
	strcat(z, a);
	strcat(z, m);
	alen = strlen(a);
	mlen = strlen(m);
	/* zlen = strlen(z); */

	ft_buffer_init(&b, 0);

	/* oldstr = b.str; */
	initsize = FT_BUFFER_MAX(&b);
	ft_buffer_add(&b, a, alen);
	v_assert_size_t(alen, ==, FT_BUFFER_LEN(&b));
	v_assert_size_t(initsize * BUFFER_GROWTH_FACTOR, ==, FT_BUFFER_MAX(&b));
	v_assert_str(a, b.str);

	/* oldstr = b.str; */
	initsize = 4096UL;
	ft_buffer_add(&b, m, mlen);
	v_assert_size_t(mlen + alen, ==, FT_BUFFER_LEN(&b));
	v_assert_size_t(initsize, ==, FT_BUFFER_MAX(&b));
	v_assert_str(z, b.str);

	FT_BUFFER_FREE(&b);

	VTS;
}

void	test_05_buffer_set_simple(void)
{
	t_buffer b;
	char	*s = "**********";
	size_t len = strlen(s);

	ft_buffer_init(&b, 0);
	ft_buffer_set(&b, '*', 10);
	ft_buffer_set(&b, '\0', 1);
	v_assert_str(s, b.str);
	v_assert_size_t(len + 1, ==, FT_BUFFER_LEN(&b));

	ft_buffer_set(&b, '#', 1);
	v_assert_str(s, b.str);
	v_assert_size_t(len + 2, ==, FT_BUFFER_LEN(&b));

	FT_BUFFER_FREE(&b);
	VTS;
}

void	suite_buffer(void)
{
	test_00_buffer_init_zero();
	test_01_buffer_init_size();
	test_02_buffer_add_simple();
	test_03_buffer_add_limit();
	test_04_buffer_add_resize();
	test_05_buffer_set_simple();

	VSS;
}
