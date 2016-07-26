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
	}
	v_assert_ptr(NULL, ==, p);

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

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[1], ==, p);
	v_assert_str(str[1], p);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[2], ==, p);
	v_assert_str(str[2], p);

	p = array_iterator(NULL);
	v_assert_ptr(NULL, ==, p);

	p = array_iterator(&v);
	v_assert_ptr(NULL, !=, p);
	v_assert_ptr(str[0], ==, p);
	v_assert_str(str[0], p);

	free(v.data);
	VTS;

}

void	suite_array_iterator(void)
{
	test_00_array_iterator_ToTheEnd();
	test_01_array_iterator_Interrupted();

	VSS;
}

