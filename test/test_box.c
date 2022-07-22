#include "test_box.h"

size_t ARRAY_SIZE = 5;
box_t *box_ptr = NULL;

box_t box1 = {1, 10, 10, 22, 23, RED};
box_t box2 = {2, .color = GREEN};
box_t box3 = {3, .color = BLUE};
box_t box4 = {4, .height = 10};
box_t box5 = {5, .length = 12};
box_t box6 = {6};

/* Required by the unity test framework */
void setUp()
{
  box_ptr = create_array_of_box(ARRAY_SIZE);
}
/* Required by the unity test framework */
void tearDown()
{
  free(box_ptr);
  box_ptr = NULL;
}

void test_box_creation(void)
{
  TEST_ASSERT_NOT_NULL(box_ptr);
}

void test_add_box_at_end(void)
{
  TEST_ASSERT_NOT_NULL(box_ptr);

  /* Adding new box before array creation */
  TEST_ASSERT_EQUAL(NULL_PTR, add_box_at_end(NULL, ARRAY_SIZE, &box1));

  /* Add New box to the end and Check if it is successful */
  TEST_ASSERT_EQUAL(SUCCESS, add_box_at_end(box_ptr, ARRAY_SIZE, &box1));
  TEST_ASSERT_EQUAL(RED, box_ptr->color);

  TEST_ASSERT_EQUAL(SUCCESS, add_box_at_end(box_ptr, ARRAY_SIZE, &box2));
  TEST_ASSERT_EQUAL(SUCCESS, add_box_at_end(box_ptr, ARRAY_SIZE, &box3));
  TEST_ASSERT_EQUAL(SUCCESS, add_box_at_end(box_ptr, ARRAY_SIZE, &box4));
  TEST_ASSERT_EQUAL(SUCCESS, add_box_at_end(box_ptr, ARRAY_SIZE, &box5));

  /* Check Overflow of Array */
  TEST_ASSERT_EQUAL(ARRAY_FULL, add_box_at_end(box_ptr, ARRAY_SIZE, &box6));
}
void test_display_all(void)
{
  TEST_ASSERT_NOT_NULL(box_ptr);

  /* Display before array creation */
  TEST_ASSERT_EQUAL(NULL_PTR, display_all(NULL, ARRAY_SIZE));

  TEST_ASSERT_EQUAL(SUCCESS, add_box_at_end(box_ptr, ARRAY_SIZE, &box1));
  TEST_ASSERT_EQUAL(SUCCESS, add_box_at_end(box_ptr, ARRAY_SIZE, &box2));
  TEST_ASSERT_EQUAL(SUCCESS, add_box_at_end(box_ptr, ARRAY_SIZE, &box3));
  TEST_ASSERT_EQUAL(SUCCESS, add_box_at_end(box_ptr, ARRAY_SIZE, &box4));
  TEST_ASSERT_EQUAL(SUCCESS, add_box_at_end(box_ptr, ARRAY_SIZE, &box6));

  TEST_ASSERT_EQUAL(SUCCESS, display_all(box_ptr, ARRAY_SIZE));

}

int test_main(void)
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */
  RUN_TEST(test_box_creation);
  RUN_TEST(test_add_box_at_end);
  RUN_TEST(test_display_all);
  /* Close the Unity Test Framework */
  return UNITY_END();
}
