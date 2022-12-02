#include "../Resources/unity.h"
#include "../include/edit_distance.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void test_edit_distance_s1() {
  char* str1 = "casa";
  char* str2 = "cassa";
  TEST_ASSERT_EQUAL_INT(1,edit_distance(str1,str2));
}

static void test_edit_distance_s2() {
  char* str1 = "casa";
  char* str2 = "cara";
  TEST_ASSERT_EQUAL_INT(2,edit_distance(str1,str2));
}

static void test_edit_distance_s3() {
  char* str1 = "vinaio";
  char* str2 = "vino";
  TEST_ASSERT_EQUAL_INT(2,edit_distance(str1,str2));
}

static void test_edit_distance_s4() {
  char* str1 = "tassa";
  char* str2 = "passato";
  TEST_ASSERT_EQUAL_INT(4,edit_distance(str1,str2));
}

static void test_edit_distance_s5() {
  char* str1 = "pioppo";
  char* str2 = "pioppo";
  TEST_ASSERT_EQUAL_INT(0,edit_distance(str1,str2));
}

static void test_edit_distance_dyn_s1() {
  char* str1 = "casa";
  char* str2 = "cassa";
  TEST_ASSERT_EQUAL_INT(1,edit_distance_dyn(str1,str2));
}

static void test_edit_distance_dyn_s2() {
  char* str1 = "casa";
  char* str2 = "cara";
  TEST_ASSERT_EQUAL_INT(2,edit_distance_dyn(str1,str2));
}

static void test_edit_distance_dyn_s3() {
  char* str1 = "vinaio";
  char* str2 = "vino";
  TEST_ASSERT_EQUAL_INT(2,edit_distance_dyn(str1,str2));
}

static void test_edit_distance_dyn_s4() {
  char* str1 = "tassa";
  char* str2 = "passato";
  TEST_ASSERT_EQUAL_INT(4,edit_distance_dyn(str1,str2));
}

static void test_edit_distance_dyn_s5() {
  char* str1 = "pioppo";
  char* str2 = "pioppo";
  TEST_ASSERT_EQUAL_INT(0,edit_distance_dyn(str1,str2));
}

int main() {
	UNITY_BEGIN();
	
	RUN_TEST(test_edit_distance_s1);
	RUN_TEST(test_edit_distance_s2);
	RUN_TEST(test_edit_distance_s3);
	RUN_TEST(test_edit_distance_s4);
	RUN_TEST(test_edit_distance_s5);
	RUN_TEST(test_edit_distance_dyn_s1);
	RUN_TEST(test_edit_distance_dyn_s2);
	RUN_TEST(test_edit_distance_dyn_s3);
	RUN_TEST(test_edit_distance_dyn_s4);
	RUN_TEST(test_edit_distance_dyn_s5);

	UNITY_END();
	
	return 0;
}