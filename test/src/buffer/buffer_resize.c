#include "header.h"

static t_buffer	*buffer;

static void	teardown(void)
{
	free(TBUFFER_GET(buffer));
	free(buffer);
}

static void	test_00_buffer_resize_ExpandNotMuch(void)
{
	buffer = buffer_new(4);
	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(buffer));

	buffer = buffer_resize(buffer, 7);
	v_assert_size_t(BUFFER_INIT_SIZE * 2, ==, TBUFFER_MAX(buffer));

	teardown();
	VTS;
}

static void	test_01_buffer_resize_ExpandMoreThan2(void)
{
	buffer = buffer_new(1111);
	v_assert_size_t(2048, ==, TBUFFER_MAX(buffer));

	buffer = buffer_resize(buffer, 5555);
	v_assert_size_t(8192, ==, TBUFFER_MAX(buffer));

	teardown();
	VTS;
}

static void	test_02_buffer_resize_ExpandPowerOf2(void)
{
	buffer = buffer_new(256);
	v_assert_size_t(256, ==, TBUFFER_MAX(buffer));

	buffer = buffer_resize(buffer, 256);
	v_assert_size_t(512, ==, TBUFFER_MAX(buffer));

	teardown();
	VTS;
}

void	suite_buffer_resize(void)
{
	test_00_buffer_resize_ExpandNotMuch();
	test_01_buffer_resize_ExpandMoreThan2();
	test_02_buffer_resize_ExpandPowerOf2();

	VSS;
}
