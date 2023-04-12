#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

Suite *lib_suite(void);

int main(void) {
  Suite *s;
  SRunner *sr;

  s = lib_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  srunner_free(sr);
  return 0;
}

START_TEST(s21_ceil_f) {
  ck_assert_ldouble_eq_tol(s21_ceil(0), ceill(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_ceil(-0), ceill(-0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_ceil(0.000001), ceill(0.000001), 1e-7);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.000001), ceill(-0.000001), 1e-7);
  ck_assert_ldouble_eq_tol(s21_ceil(0.999999), ceill(0.999999), 1e-7);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.999999), ceill(-0.999999), 1e-7);
  ck_assert_ldouble_eq_tol(s21_ceil(12.123456), ceill(12.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_ceil(-31.654321), ceill(-31.654321), 1e-7);
}
END_TEST

START_TEST(s21_floor_f) {
  ck_assert_ldouble_eq_tol(s21_floor(0), floorl(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_floor(-0), floorl(-0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_floor(0.000001), floorl(0.000001), 1e-7);
  ck_assert_ldouble_eq_tol(s21_floor(-0.000001), floorl(-0.000001), 1e-7);
  ck_assert_ldouble_eq_tol(s21_floor(0.999999), floorl(0.999999), 1e-7);
  ck_assert_ldouble_eq_tol(s21_floor(-0.999999), floorl(-0.999999), 1e-7);
  ck_assert_ldouble_eq_tol(s21_floor(12.123456), floorl(12.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_floor(-31.654321), floorl(-31.654321), 1e-7);
}
END_TEST

START_TEST(s21_tan_f) {
  ck_assert_ldouble_eq_tol(s21_tan(0), tanl(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_tan(1), tanl(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_tan(0.123456), tanl(0.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_tan(123456), tanl(123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_tan(-654321), tanl(-654321), 1e-7);
  for (double i = -s21_PI; i < s21_PI; i += 0.001) {
    ck_assert_ldouble_eq_tol(s21_tan(i), tanl(i), 1e-7);
  }
}
END_TEST

START_TEST(s21_cos_f) {
  ck_assert_ldouble_eq_tol(s21_cos(0), cosl(0), 1e76);
  ck_assert_ldouble_eq_tol(s21_cos(1), cosl(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_cos(0.123456), cosl(0.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_cos(123456), cosl(123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_cos(-654321), cosl(-654321), 1e-7);
  for (double i = -s21_PI; i < s21_PI; i += 0.001) {
    ck_assert_ldouble_eq_tol(s21_cos(i), cosl(i), 1e-7);
  }
}
END_TEST

START_TEST(s21_sin_f) {
  ck_assert_ldouble_eq_tol(s21_sin(0), sinl(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sin(1), sinl(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sin(0.123456), sinl(0.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sin(123456), sinl(123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sin(-654321), sinl(-654321), 1e-7);
  for (double i = -s21_PI; i < s21_PI; i += 0.001) {
    ck_assert_ldouble_eq_tol(s21_sin(i), sinl(i), 1e-7);
  }
}
END_TEST

START_TEST(s21_abs_f) {
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(1), abs(1));
  ck_assert_int_eq(s21_abs(123456), abs(123456));
  ck_assert_int_eq(s21_abs(-654321), abs(-654321));
  ck_assert_int_eq(s21_abs(234567), abs(234567));
  ck_assert_int_eq(s21_abs(-234567), abs(-234567));
  for (int i = -100; i < 100; i++) ck_assert_int_eq(s21_abs(i), abs(i));
}
END_TEST

START_TEST(s21_atan_f) {
  ck_assert_ldouble_eq_tol(s21_atan(0), atanl(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_atan(1), atanl(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atanl(-1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_atan(-0.654321), atanl(-0.654321), 1e-7);
  ck_assert_ldouble_eq_tol(s21_atan(0.999999), atanl(0.999999), 1e-7);
  ck_assert_ldouble_eq_tol(s21_atan(123456), atanl(123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_atan(-654321), atanl(-654321), 1e-7);
  for (double i = -1; i <= 1; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_atan(i), atanl(i), 1e-7);
  }
}
END_TEST

START_TEST(s21_acos_f) {
  ck_assert_ldouble_eq_tol(s21_acos(0), acosl(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_acos(1), acosl(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acosl(-1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_acos(0.123456), acosl(0.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_acos(0.999999), acosl(0.999999), 1e-7);
  ck_assert_int_eq(s21_acos(-1.0) == NAN, acosl(-1.0) == NAN);
  ck_assert_int_eq(s21_acos(1.0) == NAN, acosl(1.0) == NAN);
}
END_TEST

START_TEST(s21_asin_f) {
  ck_assert_ldouble_eq_tol(s21_asin(0), asinl(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_asin(1), asinl(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_asin(-1), asinl(-1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_asin(0.123456), asinl(0.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_asin(0.999999), asinl(0.999999), 1e-7);
  ck_assert_int_eq(s21_asin(-1.0) == NAN, asinl(-1.0) == NAN);
}
END_TEST

START_TEST(s21_fmod_f) {
  ck_assert_ldouble_eq_tol(s21_fmod(456.87678, 3.7), fmod(456.87678, 3.7),
                           1e-7);
  ck_assert_ldouble_eq_tol(s21_fmod(36677.546546, 4.1), fmod(36677.546546, 4.1),
                           1e-7);
  ck_assert_ldouble_eq_tol(s21_fmod(23.456, -4.355), fmod(23.456, -4.355),
                           1e-7);
}
END_TEST

START_TEST(s21_exp_f) {
  ck_assert_ldouble_eq_tol(s21_exp(0), expl(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_exp(1), expl(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_exp(-0.654321), expl(-0.654321), 1e-7);
  ck_assert_ldouble_eq_tol(s21_exp(0.999999), expl(0.999999), 1e-7);
  ck_assert_ldouble_eq(s21_exp(123456), expl(123456));
  ck_assert_ldouble_eq_tol(s21_exp(-654321), expl(-654321), 1e-7);
  for (double i = -10; i < 10; i++)
    ck_assert_ldouble_eq_tol(s21_exp(i), expl(i), 1e-7);
}
END_TEST

START_TEST(s21_log_f) {
  ck_assert_ldouble_eq_tol(s21_log(0.16), logl(0.16), 1e-7);
  ck_assert_ldouble_eq_tol(s21_log(1), logl(1), 1e-7);
  ck_assert_ldouble_eq_tol(s21_log(1.999999), logl(1.999999), 1e-7);
  ck_assert_ldouble_eq_tol(s21_log(2), logl(2), 1e-7);
  ck_assert_ldouble_eq_tol(s21_log(123456), logl(123456), 1e-7);
}
END_TEST

START_TEST(s21_sqrt_f) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrtl(0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sqrt(1.6), sqrtl(1.6), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sqrt(123456), sqrtl(123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_sqrt(0.999999), sqrtl(0.999999), 1e-7);
  ck_assert_int_eq(s21_sqrt(0) == NAN, sqrtl(0) == NAN);
  for (double i = 0; i <= 1000; i++)
    ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrtl(i), 1e-7);
}
END_TEST

START_TEST(s21_pow_f) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 0.), pow(0, 0.), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(2.6, 0.), pow(2.6, 0.), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(1, 2.6), pow(1, 2.6), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(0., 2.6), pow(0., 2.6), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(2.6, 3.45), pow(2.6, 3.45), 1e-7);
  ck_assert_ldouble_eq(s21_pow(-2.6, -INFINITY), pow(-2.6, -INFINITY));
  ck_assert_ldouble_eq(s21_pow(-2.6, INFINITY), pow(-2.6, INFINITY));
  ck_assert_ldouble_eq(s21_pow(-1, INFINITY), pow(-1, INFINITY));
  ck_assert_ldouble_eq(s21_pow(-0.123456, INFINITY), pow(-0.123456, INFINITY));
  ck_assert_int_eq(s21_pow(-2.6, 3.45) == NAN, pow(-2.6, 3.45) == NAN);
  ck_assert_ldouble_eq_tol(s21_pow(2, 3), pow(2, 3), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 3), pow(-2, 3), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(-2, -3), pow(-2, -3), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(-2, 0), pow(-2, 0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(3.0, -14.0), pow(3.0, -14.0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(31.456, 4.3), pow(31.456, 4.3), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(31.456, 0.3), pow(31.456, 0.3), 1e-7);
  ck_assert_ldouble_eq_tol(s21_pow(4.3, 4.3), pow(4.3, 4.3), 1e-7);
  ck_assert_ldouble_eq(s21_pow(123456, -654321), pow(123456, -654321));
}
END_TEST

START_TEST(s21_fabs_f) {
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-7);
  ck_assert_ldouble_eq_tol(s21_fabs(1.21), fabs(1.21), 1e-7);
  ck_assert_ldouble_eq_tol(s21_fabs(12.3456), fabs(12.3456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_fabs(-6.54321), fabs(-6.54321), 1e-7);
  ck_assert_ldouble_eq_tol(s21_fabs(0.123456), fabs(0.123456), 1e-7);
  ck_assert_ldouble_eq_tol(s21_fabs(-0.654321), fabs(-0.654321), 1e-7);
  for (double i = -100; i < 100; i += 0.1)
    ck_assert_ldouble_eq_tol(s21_fabs(i), fabs(i), 1e-7);
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Func Check");

  TCase *tc_ceil;
  TCase *tc_floor;
  TCase *tc_tan;
  TCase *tc_cos;
  TCase *tc_sin;
  TCase *tc_abs;
  TCase *tc_atan;
  TCase *tc_acos;
  TCase *tc_asin;
  TCase *tc_fmod;
  TCase *tc_exp;
  TCase *tc_log;
  TCase *tc_sqrt;
  TCase *tc_pow;
  TCase *tc_fabs;

  tc_fabs = tcase_create("Fabs");
  suite_add_tcase(s, tc_fabs);
  tcase_add_test(tc_fabs, s21_fabs_f);

  tc_pow = tcase_create("Pow");
  suite_add_tcase(s, tc_pow);
  tcase_add_test(tc_pow, s21_pow_f);

  tc_sqrt = tcase_create("Sqrt");
  suite_add_tcase(s, tc_sqrt);
  tcase_add_test(tc_sqrt, s21_sqrt_f);

  tc_log = tcase_create("Log");
  suite_add_tcase(s, tc_log);
  tcase_add_test(tc_log, s21_log_f);

  tc_exp = tcase_create("Exp");
  suite_add_tcase(s, tc_exp);
  tcase_add_test(tc_exp, s21_exp_f);

  tc_fmod = tcase_create("Fmod");
  suite_add_tcase(s, tc_fmod);
  tcase_add_test(tc_fmod, s21_fmod_f);

  tc_asin = tcase_create("Asin");
  suite_add_tcase(s, tc_asin);
  tcase_add_test(tc_asin, s21_asin_f);

  tc_acos = tcase_create("Acos");
  suite_add_tcase(s, tc_acos);
  tcase_add_test(tc_acos, s21_acos_f);

  tc_atan = tcase_create("Atan");
  suite_add_tcase(s, tc_atan);
  tcase_add_test(tc_atan, s21_atan_f);

  tc_abs = tcase_create("Abs");
  suite_add_tcase(s, tc_abs);
  tcase_add_test(tc_abs, s21_abs_f);

  tc_sin = tcase_create("Sin");
  suite_add_tcase(s, tc_sin);
  tcase_add_test(tc_sin, s21_sin_f);

  tc_cos = tcase_create("Cos");
  suite_add_tcase(s, tc_cos);
  tcase_add_test(tc_cos, s21_cos_f);

  tc_tan = tcase_create("Tan");
  suite_add_tcase(s, tc_tan);
  tcase_add_test(tc_tan, s21_tan_f);

  tc_floor = tcase_create("Floor");
  suite_add_tcase(s, tc_floor);
  tcase_add_test(tc_floor, s21_floor_f);

  tc_ceil = tcase_create("Ceil");
  suite_add_tcase(s, tc_ceil);
  tcase_add_test(tc_ceil, s21_ceil_f);

  return s;
}
