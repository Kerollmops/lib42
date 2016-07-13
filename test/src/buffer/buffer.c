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

void	test_06_buffer_insert_AddStringMiddle(void)
{
	t_buffer b;
	char	*s = "docfolamour";
	char	*good = "docteur folamour";
	size_t	len_good = strlen(good);

	ft_buffer_init(&b, 32);
	ft_buffer_add(&b, s, strlen(s));
	ft_buffer_insert(&b, 3, "teur ", 5);
	v_assert_str(good, b.str);
	v_assert_size_t(len_good, ==, b.len);

	FT_BUFFER_FREE(&b);
	VTS;
}

void	test_07_buffer_insert_AddStringHead(void)
{
	t_buffer b;
	char	*s = "folamour";
	char	*good = "docteur folamour";
	size_t	len_good = strlen(good);

	ft_buffer_init(&b, 32);
	ft_buffer_add(&b, s, strlen(s));
	ft_buffer_insert(&b, 0, "docteur ", 8);
	v_assert_str(good, b.str);
	v_assert_size_t(len_good, ==, b.len);

	FT_BUFFER_FREE(&b);
	VTS;
}

void	test_08_buffer_insert_AddStringTail(void)
{
	t_buffer b;
	char	*s = "docteur";
	char	*good = "docteur folamour";
	size_t	len_good = strlen(good);

	ft_buffer_init(&b, 32);
	ft_buffer_add(&b, s, strlen(s));
	ft_buffer_insert(&b, b.len, " folamour", 9);

	v_assert_str(good, b.str);
	v_assert_size_t(len_good, ==, b.len);

	FT_BUFFER_FREE(&b);
	VTS;
}

void	test_09_buffer_remove_Middle(void)
{
	t_buffer b;
	char	*s = "hello world";
	size_t	len = strlen(s);
	size_t	ret;

	ft_buffer_init(&b, 32);
	ft_buffer_add(&b, s, len);
	ret = ft_buffer_remove(&b, 5, 5);

	v_assert_size_t(5, ==, ret);
	v_assert_size_t(6, ==, b.len);
	v_assert_str("hellod", b.str);

	FT_BUFFER_FREE(&b);
	VTS;
}

void	test_10_buffer_remove_OutOfRange(void)
{
	t_buffer b;
	char	*s = "hello world";
	size_t	len = strlen(s);
	size_t	ret;

	ft_buffer_init(&b, 32);
	ft_buffer_add(&b, s, len);
	ret = ft_buffer_remove(&b, 11, 1);

	v_assert_size_t(0, ==, ret);
	v_assert_size_t(len, ==, b.len);
	v_assert_str(s, b.str);

	FT_BUFFER_FREE(&b);
	VTS;
}

void	test_11_buffer_remove_MiddleLongRange(void)
{
	t_buffer b;
	char	*s = "hello world";
	size_t	len = strlen(s);
	size_t	ret;

	ft_buffer_init(&b, 32);
	ft_buffer_add(&b, s, len);
	ret = ft_buffer_remove(&b, 5, 20);

	v_assert_size_t(6, ==, ret);
	v_assert_size_t(5, ==, b.len);
	v_assert_str("hello", b.str);

	FT_BUFFER_FREE(&b);
	VTS;
}

void	test_12_buffer_remove_Head(void)
{
	t_buffer b;
	char	*s = "hello world";
	size_t	len = strlen(s);
	size_t	ret;

	ft_buffer_init(&b, 32);
	ft_buffer_add(&b, s, len);
	ret = ft_buffer_remove(&b, 0, 6);

	v_assert_size_t(6, ==, ret);
	v_assert_size_t(5, ==, b.len);
	v_assert_str("world", b.str);

	FT_BUFFER_FREE(&b);
	VTS;
}

void	test_13_buffer_remove_HeadLongRange(void)
{
	t_buffer b;
	char	*s = "hello world";
	size_t	len = strlen(s);
	size_t	ret;

	ft_buffer_init(&b, 32);
	ft_buffer_add(&b, s, len);
	ret = ft_buffer_remove(&b, 0, 20);

	v_assert_size_t(11, ==, ret);
	v_assert_size_t(0, ==, b.len);
	v_assert_str("", b.str);

	FT_BUFFER_FREE(&b);
	VTS;
}

void	test_14_buffer_remove_Tail(void)
{
	t_buffer b;
	char	*s = "hello world";
	size_t	len = strlen(s);
	size_t	ret;

	ft_buffer_init(&b, 32);
	ft_buffer_add(&b, s, len);
	ret = ft_buffer_remove(&b, 10, 1);

	v_assert_size_t(1, ==, ret);
	v_assert_size_t(10, ==, b.len);
	v_assert_str("hello worl", b.str);

	FT_BUFFER_FREE(&b);
	VTS;
}

void	test_15_buffer_remove_TailLongRange(void)
{
	t_buffer b;
	char	*s = "hello world";
	size_t	len = strlen(s);
	size_t	ret;

	ft_buffer_init(&b, 32);
	ft_buffer_add(&b, s, len);
	ret = ft_buffer_remove(&b, 10, 20);

	v_assert_size_t(1, ==, ret);
	v_assert_size_t(10, ==, b.len);
	v_assert_str("hello worl", b.str);

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
	test_06_buffer_insert_AddStringMiddle();
	test_07_buffer_insert_AddStringHead();
	test_08_buffer_insert_AddStringTail();
	test_09_buffer_remove_Middle();
	test_10_buffer_remove_OutOfRange();
	test_11_buffer_remove_MiddleLongRange();
	test_12_buffer_remove_Head();
	test_13_buffer_remove_HeadLongRange();
	test_14_buffer_remove_Tail();
	test_15_buffer_remove_TailLongRange();

	VSS;
}
