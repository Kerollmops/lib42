#include "header.h"

static void	test_00_buffer_append_Simple(void)
{
	t_buffer	*dst;
	t_buffer	*src;
	char		*s1 = "Hello";
	char		*s2 = " World!";
	char		cat[20];
	size_t		l1 = strlen(s1);
	size_t		l2 = strlen(s2);
	ssize_t		total;

	dst = buffer_ndup(s1, l1);
	src = buffer_ndup(s2, l2);
	strcpy(cat, s1);
	strcpy(cat + l1, s2);
	total = buffer_append(dst, src);

	v_assert_size_t(l2, ==, src->len);
	v_assert_str(s2, src->str);

	/* v_assert_size_t(16, ==, dst->sizemax); */
	v_assert_size_t(l1 + l2, ==, total);
	v_assert_size_t(l1 + l2, ==, dst->len);
	v_assert_str(cat, dst->str);

	free(src->str);
	free(dst->str);
	free(src);
	free(dst);

	VTS;
}

static void	test_01_buffer_append_EmptyBuffer(void)
{
	t_buffer	*dst;
	t_buffer	*src;
	char		*s1 = "Emtpy";
	char		*s2 = "";
	char		cat[20];
	size_t		l1 = strlen(s1);
	size_t		l2 = strlen(s2);
	ssize_t		total;

	dst = buffer_ndup(s1, l1);
	src = buffer_ndup(s2, l2);
	strcpy(cat, s1);
	strcpy(cat + l1, s2);
	total = buffer_append(dst, src);

	v_assert_size_t(l2, ==, src->len);
	v_assert_str(s2, src->str);

	/* v_assert_size_t(16, ==, dst->sizemax); */
	v_assert_size_t(l1 + l2, ==, total);
	v_assert_size_t(l1 + l2, ==, dst->len);
	v_assert_str(cat, dst->str);

	free(src->str);
	free(dst->str);
	free(src);
	free(dst);

	VTS;
}

void	suite_buffer_append(void)
{
	test_00_buffer_append_Simple();
	test_01_buffer_append_EmptyBuffer();

	VSS;
}
