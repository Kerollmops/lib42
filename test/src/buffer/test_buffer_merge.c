#include "header.h"

static void	test_00_buffer_merge_NoRealloc(void)
{
	t_buffer	*b1;
	t_buffer	*b2;
	t_buffer	*merge;
	char		*s1 = "Hello World!";
	char		*s2 = "Good Morning";
	char		s[100];
	size_t		l1 = strlen(s1);
	size_t		l2 = strlen(s2);

	s[0] = '\0';
	strcat(s, s1);
	strcat(s, s2);
	b1 = buffer_dup(s1);
	b2 = buffer_dup(s2);
	merge = buffer_merge(b1, b2);

	v_assert_str(s1, TBUFFER_GET(b1));
	v_assert_str(s2, TBUFFER_GET(b2));
	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(merge));
	v_assert_size_t(l1 + l2, ==, TBUFFER_LEN(merge));
	v_assert_str(s, TBUFFER_GET(merge));

	free(TBUFFER_GET(b1));
	free(TBUFFER_GET(b2));
	free(TBUFFER_GET(merge));
	free(b1);
	free(b2);
	free(merge);
	VTS;
}

static void	test_01_buffer_merge_Realloc(void)
{
	t_buffer	*b1;
	t_buffer	*b2;
	t_buffer	*merge;
	char		s1[100];
	char		s2[100];

	// setup
	memset(s1, '\0', 100);
	memset(s1, '*', BUFFER_INIT_SIZE + 10);
	memset(s2, '\0', 100);
	memset(s2, '#', 6);
	b1 = buffer_dup(s1);
	b2 = buffer_dup(s2);
	strcat(s1, s2);
	merge = buffer_merge(b1, b2);

	// test
	v_assert_size_t(BUFFER_INIT_SIZE * BUFFER_GROWTH_FACTOR, ==, TBUFFER_MAX(b1));
	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(b2));
	v_assert_size_t(BUFFER_INIT_SIZE * BUFFER_GROWTH_FACTOR, ==, TBUFFER_MAX(merge));
	v_assert_size_t(80, ==, TBUFFER_LEN(merge));
	v_assert_str(s1, TBUFFER_GET(merge));

	// teardown
	free(TBUFFER_GET(b1));
	free(TBUFFER_GET(b2));
	free(TBUFFER_GET(merge));
	free(b1);
	free(b2);
	free(merge);
	VTS;
}

void	suite_buffer_merge(void)
{
	test_00_buffer_merge_NoRealloc();
	test_01_buffer_merge_Realloc();

	VSS;
}
