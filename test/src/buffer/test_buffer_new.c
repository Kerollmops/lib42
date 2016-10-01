#include "header.h"

static t_buffer	*buffer;

static void	teardown(void)
{
	free(TBUFFER_GET(buffer));
	free(buffer);
}

static void	test_00_buffer_new_SizeBelowMinimum(void)
{
	buffer = buffer_new(4);

	v_assert_size_t(BUFFER_INIT_SIZE, ==, TBUFFER_MAX(buffer));

	teardown();
	VTS;
}

static void	test_01_buffer_new_SizeAboveMinimum(void)
{
	buffer = buffer_new(1111);

	v_assert_size_t(2048, ==, TBUFFER_MAX(buffer));

	teardown();
	VTS;
}

static void	test_02_buffer_new_SizePowerOf2(void)
{
	buffer = buffer_new(256);

	v_assert_size_t(512, ==, TBUFFER_MAX(buffer));

	teardown();
	VTS;
}

static void	test_03_buffer_new_SizeOfInit(void)
{
	buffer = buffer_new(BUFFER_INIT_SIZE);

	v_assert_size_t(BUFFER_INIT_SIZE * 2, ==, TBUFFER_MAX(buffer));

	teardown();
	VTS;
}

static void	test_04_buffer_new_SizePowerOf2MinsOne(void)
{
	buffer = buffer_new(255);

	v_assert_size_t(256, ==, TBUFFER_MAX(buffer));

	teardown();
	VTS;
}

void	suite_buffer_new(void)
{
	test_00_buffer_new_SizeBelowMinimum();
	test_01_buffer_new_SizeAboveMinimum();
	test_02_buffer_new_SizePowerOf2();
	test_03_buffer_new_SizeOfInit();
	test_04_buffer_new_SizePowerOf2MinsOne();

	VSS;
}
