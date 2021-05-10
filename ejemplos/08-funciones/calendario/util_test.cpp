#include "util.hpp"
#include <gtest/gtest.h>

TEST(bisiesto_test, nobisiesto) {
  ASSERT_FALSE(calendario::es_bisiesto(2001));
}

TEST(bisiesto_test, multiplo_cuatro) {
  ASSERT_TRUE(calendario::es_bisiesto(2004));
}

TEST(bisiesto_test, multiplo_cien) {
  ASSERT_FALSE(calendario::es_bisiesto(1900));
}


TEST(bisiesto_test, multiplo_cuatrocientos) {
  ASSERT_TRUE(calendario::es_bisiesto(2000));
}
