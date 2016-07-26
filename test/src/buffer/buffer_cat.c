#include "header.h"

void	test_00_buffer_cat_Simple(void)
{
	t_buffer	*b;
	char		*s = "Hello World!";
	size_t		l = strlen(s);

	b = buffer_new(4);
	buffer_cat(b, s);

	v_assert_size_t(l, ==, b->len);
	v_assert_size_t(16, ==, b->sizemax);
	v_assert_str(s, b->str);

	free(b->str);
	free(b);

	VTS;
}

void	test_01_buffer_cat_NeedResize(void)
{
	t_buffer	*b;
	char		*s = "Hello World!";
	size_t		l = strlen(s);

	b = buffer_new(12);
	buffer_cat(b, s);

	v_assert_size_t(l, ==, b->len);
	v_assert_size_t(24, ==, b->sizemax);
	v_assert_str(s, b->str);

	free(b->str);
	free(b);

	VTS;
}

void	test_02_buffer_cat_BigConcatenation(void)
{
	t_buffer	*b;
	char		a[300];
	char		m[3000];
	char		am[4000];
	size_t		alen;
	size_t		mlen;

	b = buffer_new(8);

	memset(a, 'a', sizeof(a));
	a[sizeof(a) - 1] = '\0';
	alen = strlen(a);
	buffer_ncat(b, a, alen);
	v_assert_size_t(alen, ==, b->len);
	v_assert_size_t(512, ==, b->sizemax);
	v_assert_str(a, b->str);

	memset(m, 'm', sizeof(m));
	m[sizeof(m) - 1] = '\0';
	mlen = strlen(m);
	memset(am, 0, sizeof(am));
	strcat(am, a);
	strcat(am + sizeof(a) - 1, m);
	buffer_ncat(b, m, mlen);
	v_assert_size_t(alen + mlen, ==, b->len);
	v_assert_size_t(4096, ==, b->sizemax);
	v_assert_str(am, b->str);

	free(b->str);
	free(b);

	VTS;
}

void	suite_buffer_cat(void)
{
	test_00_buffer_cat_Simple();
	test_01_buffer_cat_NeedResize();
	test_02_buffer_cat_BigConcatenation();

	VSS;
}
