#include "header.h"

void	test_00_buffer_insert_AddStringMiddle(void)
{
	t_buffer b;
	char	*s = "docfolamour";
	char	*good = "docteur folamour";
	size_t	len_good = strlen(good);

	buffer_init(&b, 32);
	buffer_ncat(&b, s, strlen(s));
	buffer_insert(&b, 3, "teur ", 5);
	v_assert_str(good, b.str);
	v_assert_size_t(len_good, ==, b.len);

	TBUFFER_FREE(&b);
	VTS;
}

void	test_01_buffer_insert_AddStringHead(void)
{
	t_buffer b;
	char	*s = "folamour";
	char	*good = "docteur folamour";
	size_t	len_good = strlen(good);

	buffer_init(&b, 32);
	buffer_ncat(&b, s, strlen(s));
	buffer_insert(&b, 0, "docteur ", 8);
	v_assert_str(good, b.str);
	v_assert_size_t(len_good, ==, b.len);

	TBUFFER_FREE(&b);
	VTS;
}

void	test_02_buffer_insert_AddStringTail(void)
{
	t_buffer b;
	char	*s = "docteur";
	char	*good = "docteur folamour";
	size_t	len_good = strlen(good);

	buffer_init(&b, 32);
	buffer_ncat(&b, s, strlen(s));
	buffer_insert(&b, b.len, " folamour", 9);

	v_assert_str(good, b.str);
	v_assert_size_t(len_good, ==, b.len);

	TBUFFER_FREE(&b);
	VTS;
}

void	suite_buffer_insert(void)
{
	test_00_buffer_insert_AddStringMiddle();
	test_01_buffer_insert_AddStringHead();
	test_02_buffer_insert_AddStringTail();

	VSS;
}
