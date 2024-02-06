#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_math.h"

#define EPS_6 1e-6

START_TEST(s21_test_abs) {
  for (int i = -1000; i <= 1000; i++) {
    ck_assert_int_eq(abs(i), s21_abs(i));
  }
}
END_TEST

START_TEST(s21_test_fabs) {
  ck_assert_double_eq_tol(fabs(15.5), s21_fabs(15.5), EPS_6);
  ck_assert_double_eq_tol(fabs(-15.3), s21_fabs(-15.3), EPS_6);
  ck_assert_double_eq_tol(fabs(0.0), s21_fabs(0.0), EPS_6);
  ck_assert_double_eq_tol(fabs(0.000004), s21_fabs(0.000004), EPS_6);
  ck_assert_double_eq_tol(fabs(-0.000004), s21_fabs(-0.000004), EPS_6);
  for (double i = -1000.0; i <= 1000.0; i += 0.01)
    ck_assert_double_eq_tol(fabs(i), s21_fabs(i), EPS_6);
}
END_TEST

START_TEST(s21_test_pow) {
  for (double i = 0; i <= 4; i += 0.5) {
    for (double j = 1; j <= 6.4; j += 0.4) {
      ck_assert_double_eq_tol(pow(i, j), s21_pow(i, j), EPS_6);
    }
  }
  ck_assert_double_eq_tol(pow(1, 1), s21_pow(1, 1), EPS_6);
  ck_assert_double_eq_tol(pow(3, 0), s21_pow(3, 0), EPS_6);
  ck_assert_double_eq_tol(pow(3, 2), s21_pow(3, 2), EPS_6);
  ck_assert_double_eq_tol(pow(3.1, 4), s21_pow(3.1, 4), EPS_6);
  ck_assert_double_eq_tol(pow(3.1, 4.2), s21_pow(3.1, 4.2), EPS_6);
  ck_assert_double_eq_tol(pow(5.1, 4.51), s21_pow(5.1, 4.51), EPS_6);
  ck_assert_double_eq_tol(pow(5.1, 1.51), s21_pow(5.1, 1.51), EPS_6);
  ck_assert_double_eq_tol(pow(5.1, 0.511), s21_pow(5.1, 0.511), EPS_6);
  ck_assert_double_eq_tol(pow(0, 0.511), s21_pow(0, 0.511), EPS_6);
  ck_assert_double_eq_tol(pow(1.5, -100), s21_pow(1.5, -100), EPS_6);
  ck_assert_double_eq_tol(pow(-1.5, 8), s21_pow(-1.5, 8), EPS_6);
  ck_assert_double_eq_tol(pow(-100.0, 2), s21_pow(-100.0, 2), EPS_6);
  ck_assert_double_eq_tol(pow(0, 0), s21_pow(0, 0), EPS_6);
  ck_assert_ldouble_infinite(s21_pow(S21_INF_POS, S21_INF_POS));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(s21_test_log) {
  for (double i = -1000.0; i < 0.0; i += 0.01) {
    ck_assert_ldouble_nan(log(i));
    ck_assert_ldouble_nan(s21_log(i));
  }

  for (double i = 0.1; i < 1000.0; i += 0.1)
    ck_assert_double_eq_tol(log(i), s21_log(i), EPS_6);

  ck_assert_double_eq_tol(log(1), s21_log(1), EPS_6);
  ck_assert_double_eq_tol(log(8), s21_log(8), EPS_6);
  ck_assert_double_eq_tol(log(0.1), s21_log(0.1), EPS_6);
  ck_assert_double_eq_tol(log(500), s21_log(500), EPS_6);
  ck_assert_double_eq_tol(log(1000000), s21_log(1000000), EPS_6);
  ck_assert_double_eq_tol(log(0.0000001), s21_log(0.0000001), EPS_6);
  ck_assert_double_eq_tol(log(1.5), s21_log(1.5), EPS_6);
  ck_assert_double_eq_tol(log(2), s21_log(2), EPS_6);
  ck_assert_ldouble_infinite(s21_log(0));
}
END_TEST

START_TEST(s21_test_exp) {
  for (double j = -20.0; j <= 80.0; j += 0.6) {
    ck_assert_double_eq_tol(exp(j), s21_exp(j), EPS_6);
  }
  ck_assert_double_eq_tol(exp(5), s21_exp(5), EPS_6);
  ck_assert_double_eq_tol(exp(19), s21_exp(19), EPS_6);
  ck_assert_double_eq_tol(exp(-5), s21_exp(-5), EPS_6);
  ck_assert_double_eq_tol(exp(-15), s21_exp(-15), EPS_6);
  ck_assert_double_eq_tol(exp(0.0000001), s21_exp(0.0000001), EPS_6);
  ck_assert_double_eq_tol(exp(0), s21_exp(0), EPS_6);
  ck_assert_double_eq_tol(exp(-20), s21_exp(-20), EPS_6);
  ck_assert_double_eq_tol(exp(50), s21_exp(50), EPS_6);
  ck_assert_double_eq_tol(exp(1), s21_exp(1), EPS_6);
  ck_assert_ldouble_infinite(s21_exp(DBL_MAX + 1));
}
END_TEST

START_TEST(s21_test_sqrt) {
  for (float j = 0.1; j <= 1200.8; j += 0.5) {
    ck_assert_double_eq_tol(sqrt(j), s21_sqrt(j), EPS_6);
  }
  ck_assert_double_eq_tol(sqrt(1), s21_sqrt(1), EPS_6);
  ck_assert_double_eq_tol(sqrt(8), s21_sqrt(8), EPS_6);
  ck_assert_double_eq_tol(sqrt(0.1), s21_sqrt(0.1), EPS_6);
  ck_assert_double_eq_tol(sqrt(500), s21_sqrt(500), EPS_6);
  ck_assert_double_eq_tol(sqrt(1000000), s21_sqrt(1000000), EPS_6);
  ck_assert_double_eq_tol(sqrt(0.0000001), s21_sqrt(0.0000001), EPS_6);
  ck_assert_double_eq_tol(sqrt(1.5), s21_sqrt(1.5), EPS_6);
  ck_assert_double_eq_tol(sqrt(2), s21_sqrt(2), EPS_6);
  ck_assert_ldouble_nan(s21_sqrt(-2));
}
END_TEST

START_TEST(s21_test_ceil) {
  ck_assert_double_eq(ceil(1.000001), s21_ceil(1.000001));
  ck_assert_double_eq(ceil(8.44), s21_ceil(8.44));
  ck_assert_double_eq(ceil(0.1), s21_ceil(0.1));
  ck_assert_double_eq(ceil(500.55), s21_ceil(500.55));
  ck_assert_double_eq(ceil(1000000.0), s21_ceil(1000000.0));
  ck_assert_double_eq(ceil(0.0000001), s21_ceil(0.0000001));

  ck_assert_double_eq(ceil(1.5), s21_ceil(1.5));
  ck_assert_double_eq(ceil(0.0), s21_ceil(0.0));
  ck_assert_ldouble_infinite(s21_ceil(S21_INF_POS));
  ck_assert_ldouble_infinite(s21_ceil(S21_INF_NEG));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
}
END_TEST

START_TEST(s21_test_floor) {
  ck_assert_double_eq(floor(1.000001), s21_floor(1.000001));
  ck_assert_double_eq(floor(8.44), s21_floor(8.44));
  ck_assert_double_eq(floor(0.1), s21_floor(0.1));
  ck_assert_double_eq(floor(500.55), s21_floor(500.55));
  ck_assert_double_eq(floor(1000000.0), s21_floor(1000000.0));
  ck_assert_double_eq(floor(0.0000001), s21_floor(0.0000001));
  ck_assert_double_eq(floor(1.5), s21_floor(1.5));
  ck_assert_double_eq(floor(0.0), s21_floor(0.0));
  ck_assert_double_eq(floor(-1.000001), s21_floor(-1.000001));
  ck_assert_double_eq(floor(-8.44), s21_floor(-8.44));
  ck_assert_double_eq(floor(-0.1), s21_floor(-0.1));
  ck_assert_double_eq(floor(-500.55), s21_floor(-500.55));
  ck_assert_double_eq(floor(-1000000.0), s21_floor(-1000000.0));
  ck_assert_double_eq(floor(-0.0000001), s21_floor(-0.0000001));
  ck_assert_double_eq(floor(-1.5), s21_floor(-1.5));
  ck_assert_double_eq(floor(-0.0), s21_floor(-0.0));
}
END_TEST

START_TEST(s21_test_fmod) {
  ck_assert_double_eq_tol(fmod(10.5, -3.0), s21_fmod(10.5, -3.0), EPS_6);
  ck_assert_double_eq_tol(fmod(-8.1, 4.0), s21_fmod(-8.1, 4.0), EPS_6);
  ck_assert_double_eq_tol(fmod(-0.0, 4.4), s21_fmod(-0.0, 4.4), EPS_6);
  ck_assert_double_eq_tol(fmod(0.0, 1.4), s21_fmod(0.0, 1.4), EPS_6);
  ck_assert_double_eq_tol(fmod(10.1, 0.051), s21_fmod(10.1, 0.051), EPS_6);
  ck_assert_double_eq_tol(fmod(100000.1, -0.1), s21_fmod(100000.1, -0.1),
                          EPS_6);
  ck_assert_double_eq_tol(fmod(100.1, 0.1), s21_fmod(100.1, 0.1), EPS_6);
  ck_assert_double_eq_tol(fmod(0.00005001, 0.0000001),
                          s21_fmod(0.00005001, 0.0000001), EPS_6);
  ck_assert_double_eq_tol(fmod(1.5, 100.0), s21_fmod(1.5, 100.0), EPS_6);
  ck_assert_double_eq_tol(fmod(0.0, 1.0), s21_fmod(0.0, 1.0), EPS_6);
  ck_assert_ldouble_nan(s21_fmod(2, 0));
}
END_TEST

START_TEST(s21_test_asin) {
  for (float j = -0.99; j <= 0.99; j += 0.02) {
    ck_assert_double_eq_tol(asin(j), s21_asin(j), EPS_6);
  }
  ck_assert_double_eq_tol(asin(S21_PI / 4), s21_asin(S21_PI / 4), EPS_6);
  ck_assert_double_eq_tol(asin(S21_PI / 4), s21_asin(S21_PI / 4), EPS_6);
  ck_assert_double_eq_tol(asin(-0.99), s21_asin(-0.99), EPS_6);
  ck_assert_double_eq_tol(asin(0.3), s21_asin(0.3), EPS_6);
  ck_assert_double_eq_tol(asin(0.45), s21_asin(0.45), EPS_6);
  ck_assert_double_eq_tol(asin(0.0), s21_asin(0.0), EPS_6);
  ck_assert_double_eq_tol(asin(-0.18), s21_asin(-0.18), EPS_6);
  ck_assert_double_eq_tol(asin(0.360), s21_asin(0.360), EPS_6);
  ck_assert_double_eq_tol(asin(0.255), s21_asin(0.255), EPS_6);
  ck_assert_double_eq_tol(asin(-0.50), s21_asin(-0.50), EPS_6);
  ck_assert_double_eq_tol(asin(0.000001), s21_asin(0.000001), EPS_6);
  ck_assert_double_eq_tol(asin(1.0), s21_asin(1.0), EPS_6);
  ck_assert_double_eq_tol(asin(-1.0), s21_asin(-1.0), EPS_6);
  ck_assert_ldouble_nan(s21_asin(1.5));
  ck_assert_ldouble_nan(s21_asin(5));
}
END_TEST

START_TEST(s21_test_cos) {
  for (float j = -721; j < 721; j += 0.2) {
    ck_assert_double_eq_tol(cos(j), s21_cos(j), EPS_6);
  }
  ck_assert_double_eq_tol(cos(30.0), s21_cos(30.0), EPS_6);
  ck_assert_double_eq_tol(cos(45.0), s21_cos(45.0), EPS_6);
  ck_assert_double_eq_tol(cos(0.0), s21_cos(0.0), EPS_6);
  ck_assert_double_eq_tol(cos(180.0), s21_cos(180.0), EPS_6);
  ck_assert_double_eq_tol(cos(360.0), s21_cos(360.0), EPS_6);
  ck_assert_double_eq_tol(cos(25.5), s21_cos(25.5), EPS_6);
  ck_assert_double_eq_tol(cos(-5.0), s21_cos(-5.0), EPS_6);
  ck_assert_double_eq_tol(cos(500.21), s21_cos(500.21), EPS_6);
  ck_assert_double_eq_tol(cos(0.000001), s21_cos(0.000001), EPS_6);
  ck_assert_double_eq_tol(cos(0.0001), s21_cos(0.0001), EPS_6);
  ck_assert_double_eq_tol(cos(2.0 * S21_PI), s21_cos(2.0 * S21_PI), EPS_6);
  ck_assert_double_eq_tol(cos((-1) * S21_PI_2), s21_cos((-1) * S21_PI_2),
                          EPS_6);
  ck_assert_double_eq_tol(cos(S21_PI), s21_cos(S21_PI), EPS_6);
  ck_assert_double_nan(s21_cos(S21_INF_POS));
  ck_assert_double_nan(s21_cos(S21_NAN));
}
END_TEST

START_TEST(s21_test_acos) {
  for (float j = -0.99; j <= 0.99; j += 0.02) {
    ck_assert_double_eq_tol(acos(j), s21_acos(j), EPS_6);
  }
  ck_assert_double_eq_tol(acos(S21_PI / 4), s21_acos(S21_PI / 4), EPS_6);
  ck_assert_double_eq_tol(acos(S21_PI / 4), s21_acos(S21_PI / 4), EPS_6);
  ck_assert_double_eq_tol(acos(-0.99), s21_acos(-0.99), EPS_6);
  ck_assert_double_eq_tol(acos(0.3), s21_acos(0.3), EPS_6);
  ck_assert_double_eq_tol(acos(0.45), s21_acos(0.45), EPS_6);
  ck_assert_double_eq_tol(acos(0.0), s21_acos(0.0), EPS_6);
  ck_assert_double_eq_tol(acos(-0.18), s21_acos(-0.18), EPS_6);
  ck_assert_double_eq_tol(acos(0.360), s21_acos(0.360), EPS_6);
  ck_assert_double_eq_tol(acos(0.255), s21_acos(0.255), EPS_6);
  ck_assert_double_eq_tol(acos(-0.50), s21_acos(-0.50), EPS_6);
  ck_assert_double_eq_tol(acos(0.000001), s21_acos(0.000001), EPS_6);
  ck_assert_double_eq_tol(acos(-1), s21_acos(-1), EPS_6);
  ck_assert_double_eq_tol(acos(1), s21_acos(1), EPS_6);
  ck_assert_ldouble_infinite(s21_acos(S21_INF_POS));
  ck_assert_ldouble_infinite(s21_acos(S21_INF_NEG));
  ck_assert_ldouble_nan(s21_acos(1.5));
}
END_TEST

START_TEST(s21_test_atan) {
  for (double j = 0; j < 0.1; j += 0.1) {
    ck_assert_double_eq_tol(atan(j), s21_atan(j), EPS_6);
  }

  ck_assert_double_eq_tol(atan(S21_PI / 4), s21_atan(S21_PI / 4), EPS_6);
  ck_assert_double_eq_tol(atan(-S21_PI / 4), s21_atan(-S21_PI / 4), EPS_6);
  ck_assert_double_eq_tol(atan(-0.99), s21_atan(-0.99), EPS_6);
  ck_assert_double_eq_tol(atan(0.3), s21_atan(0.3), EPS_6);
  ck_assert_double_eq_tol(atan(0.45), s21_atan(0.45), EPS_6);
  ck_assert_double_eq_tol(atan(0.0), s21_atan(0.0), EPS_6);
  ck_assert_double_eq_tol(atan(-0.18), s21_atan(-0.18), EPS_6);
  ck_assert_double_eq_tol(atan(0.360), s21_atan(0.360), EPS_6);
  ck_assert_double_eq_tol(atan(0.255), s21_atan(0.255), EPS_6);
  ck_assert_double_eq_tol(atan(-0.50), s21_atan(-0.50), EPS_6);
  ck_assert_double_eq_tol(atan(0.000001), s21_atan(0.000001), EPS_6);
  ck_assert_double_eq_tol(atan(2.1), s21_atan(2.1), EPS_6);
  ck_assert_double_eq_tol(atan(1), s21_atan(1), EPS_6);
  ck_assert_double_eq_tol(atan(-1), s21_atan(-1), EPS_6);
  ck_assert_double_eq_tol(atan(-50), s21_atan(-50), EPS_6);
  ck_assert_double_eq_tol(atan(0), s21_atan(0), EPS_6);
  ck_assert_double_eq_tol(atan(S21_PI / 2), s21_atan(S21_PI / 2), EPS_6);
  ck_assert_double_eq_tol(atan(-S21_PI / 2), s21_atan(-S21_PI / 2), EPS_6);
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_double_eq_tol(atan(S21_INF_POS), s21_atan(S21_INF_POS), EPS_6);
  ck_assert_double_eq_tol(atan(S21_INF_NEG), s21_atan(S21_INF_NEG), EPS_6);
}
END_TEST

START_TEST(s21_test_sin) {
  for (double j = -10.0; j <= 10.0; j += 0.01) {
    ck_assert_double_eq_tol(sin(j), s21_sin(j), EPS_6);
  }
  ck_assert_double_eq_tol(sin(0), s21_sin(0), EPS_6);
  ck_assert_double_eq_tol(sin(S21_PI / 6), s21_sin(S21_PI / 6), EPS_6);
  ck_assert_double_eq_tol(sin(S21_PI / 4), s21_sin(S21_PI / 4), EPS_6);
  ck_assert_double_eq_tol(sin(S21_PI / 3), s21_sin(S21_PI / 3), EPS_6);
  ck_assert_double_eq_tol(sin(S21_PI / 2), s21_sin(S21_PI / 2), EPS_6);
  ck_assert_double_eq_tol(sin(S21_PI), s21_sin(S21_PI), EPS_6);
  ck_assert_double_eq_tol(sin(3.0 * S21_PI / 2.0), s21_sin(3.0 * S21_PI / 2.0),
                          EPS_6);
  ck_assert_double_eq_tol(sin(2.0 * S21_PI), s21_sin(2.0 * S21_PI), EPS_6);
  ck_assert_double_eq_tol(sin((-1) * S21_PI_2), s21_sin((-1) * S21_PI_2),
                          EPS_6);
  ck_assert_double_nan(s21_sin(S21_INF_POS));
  ck_assert_double_nan(s21_sin(S21_NAN));
}
END_TEST

START_TEST(s21_test_tan) {
  for (double j = -10.0; j <= 10.0; j += 0.1) {
    ck_assert_double_eq_tol(tan(j), s21_tan(j), EPS_6);
  }
  ck_assert_double_eq_tol(tan(360.0), s21_tan(360.0), EPS_6);
  ck_assert_double_eq_tol(tan(0.000001), s21_tan(0.000001), EPS_6);
  ck_assert_double_eq_tol(tan(30.0), s21_tan(30.0), EPS_6);
  ck_assert_double_eq_tol(tan(45.0), s21_tan(45.0), EPS_6);
  ck_assert_double_eq_tol(tan(0.0), s21_tan(0.0), EPS_6);
  ck_assert_double_eq_tol(tan(180.0), s21_tan(180.0), EPS_6);
  ck_assert_double_eq_tol(tan(25.5), s21_tan(25.5), EPS_6);
  ck_assert_double_eq_tol(tan(-5.0), s21_tan(-5.0), EPS_6);
  ck_assert_double_eq_tol(tan(500.21), s21_tan(500.21), EPS_6);
  ck_assert_double_eq_tol(tan(0.0001), s21_tan(0.0001), EPS_6);
  ck_assert_double_eq_tol(tan(S21_PI / 6), s21_tan(S21_PI / 6), EPS_6);
  ck_assert_double_eq_tol(tan(S21_PI / 4), s21_tan(S21_PI / 4), EPS_6);
  ck_assert_double_eq_tol(tan(S21_PI / 3), s21_tan(S21_PI / 3), EPS_6);
  ck_assert_double_eq_tol(tan(S21_PI), s21_tan(S21_PI), EPS_6);
  ck_assert_double_eq_tol(tan(S21_PI_34), s21_tan(S21_PI_34), EPS_6);
  ck_assert_double_eq_tol(tan(S21_PI_2), s21_tan(S21_PI_2), EPS_6);
  ck_assert_double_eq_tol(tan((-1) * S21_PI_2), s21_tan((-1) * S21_PI_2),
                          EPS_6);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("S21_MATH");
  TCase *tc1_1 = tcase_create("TEST");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, s21_test_abs);
  tcase_add_test(tc1_1, s21_test_fabs);
  tcase_add_test(tc1_1, s21_test_pow);
  tcase_add_test(tc1_1, s21_test_log);
  tcase_add_test(tc1_1, s21_test_exp);
  tcase_add_test(tc1_1, s21_test_sqrt);
  tcase_add_test(tc1_1, s21_test_ceil);
  tcase_add_test(tc1_1, s21_test_floor);
  tcase_add_test(tc1_1, s21_test_fmod);
  tcase_add_test(tc1_1, s21_test_asin);
  tcase_add_test(tc1_1, s21_test_cos);
  tcase_add_test(tc1_1, s21_test_acos);
  tcase_add_test(tc1_1, s21_test_atan);
  tcase_add_test(tc1_1, s21_test_sin);
  tcase_add_test(tc1_1, s21_test_tan);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}