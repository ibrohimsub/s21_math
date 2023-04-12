#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define s21_PI 3.14159265358979324
#define s21_EPS 1e-17
#define s21_NAN 0.0 / 0.0
#define s21_INF 1.0 / 0.0
#define s21_ln10 2.30258509299404590109
#define s21_MAX_double 1.7976931348623158e308
#define ASIN_EPS 1e-161
#define COS_EPS 1e-6l

typedef struct special {
  long double m_a;
  long double pow;
  int s_n;
  int E;
} opt;

long double atan_mod(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_log(double x);
int s21_abs(int x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_pow(double b_s_e, double exp);
long double s21_sqrt(double x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double p_log(double x);
void tr_e(double x, opt *param);
long double w_sqrt(long double r, long double t, double x);
long double s21_asin_x_05(double x);

#endif  // SRC_S21_MATH_H_
