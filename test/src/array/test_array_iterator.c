#include "header.h"

static t_array	v;
static char		*str[] = {
	"hello",
	"world",
	"and",
	"good",
	"morning",
};

static void setup(void)
{
	array_init(&v, 8);
	array_add(&v, str[0]);
	array_add(&v, str[1]);
	array_add(&v, str[2]);
	array_add(&v, str[3]);
	array_add(&v, str[4]);
}

static void	teardown(void)
{
	free(v.data);
	memset(&v, 0, sizeof(t_array));
}

void	test_00_array_iterator_ToTheEnd(void)
{
	void *p;

	setup();

	for (size_t i = 0; (p = array_iterator(&v)) != NULL; ++i)
	{
		v_assert_ptr(NULL, !=, p);
		v_assert_ptr(str[i], ==, p);
		v_assert_str(str[i], p);
		v_assert_size_t(i + 1, ==, v.iterator);
	}
	v_assert_ptr(NULL, ==, p);
	v_assert_size_t(0, ==, v.iterator);

	free(v.data);
	VTS;
}

void	test_01_array_iterator_Interrupted(void)
{
	void *p;

	setup();

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[0], ==, p);
	v_assert_str(str[0], p);
	v_assert_size_t(1, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[1], ==, p);
	v_assert_str(str[1], p);
	v_assert_size_t(2, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[2], ==, p);
	v_assert_str(str[2], p);
	v_assert_size_t(3, ==, v.iterator);

	TARRAY_RESET_ITER(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[2], ==, p);
	v_assert_size_t(0, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[0], ==, p);
	v_assert_str(str[0], p);
	v_assert_size_t(1, ==, v.iterator);

	free(v.data);
	VTS;

}

void	test_02_array_iterator_RemoveElementBefore(void)
{
	void *p;

	setup();

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[0], ==, p);
	v_assert_str(str[0], p);
	v_assert_size_t(1, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[1], ==, p);
	v_assert_str(str[1], p);
	v_assert_size_t(2, ==, v.iterator);

	array_remove(&v, 0);
	v_assert_size_t(1, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[2], ==, p);
	v_assert_str(str[2], p);
	v_assert_size_t(2, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[3], ==, p);
	v_assert_str(str[3], p);
	v_assert_size_t(3, ==, v.iterator);

	free(v.data);
	VTS;

}

void	test_03_array_iterator_RemoveElementAfter(void)
{
	void *p;

	setup();

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[0], ==, p);
	v_assert_str(str[0], p);
	v_assert_size_t(1, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[1], ==, p);
	v_assert_str(str[1], p);
	v_assert_size_t(2, ==, v.iterator);

	array_remove(&v, 4);
	v_assert_size_t(2, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[2], ==, p);
	v_assert_str(str[2], p);
	v_assert_size_t(3, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[3], ==, p);
	v_assert_str(str[3], p);
	v_assert_size_t(4, ==, v.iterator);

	free(v.data);
	VTS;

}

void	test_04_array_iterator_RemoveElementOnIt(void)
{
	void *p;

	setup();

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[0], ==, p);
	v_assert_str(str[0], p);
	v_assert_size_t(1, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[1], ==, p);
	v_assert_str(str[1], p);
	v_assert_size_t(2, ==, v.iterator);

	array_remove(&v, 2);
	v_assert_size_t(2, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[3], ==, p);
	v_assert_str(str[3], p);
	v_assert_size_t(3, ==, v.iterator);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[4], ==, p);
	v_assert_str(str[4], p);
	v_assert_size_t(4, ==, v.iterator);

	free(v.data);
	VTS;

}

void	suite_array_iterator(void)
{
	test_00_array_iterator_ToTheEnd();
	test_01_array_iterator_Interrupted();
	test_02_array_iterator_RemoveElementBefore();
	test_03_array_iterator_RemoveElementAfter();
	test_04_array_iterator_RemoveElementOnIt();

	VSS;
}
