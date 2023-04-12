#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) x = -x;
  return x;
}

long double s21_fabs(double x) { return x < 0 ? x * -1 : x; }

long double s21_exp(double x) {
  int flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  long double add_value = (long double)x, series = 1, i = 1, p = 1;
  while (s21_fabs(i / series) > 1e-100) {
    i = (i * add_value) / p;
    series += i;
    p++;
  }
  if (flag == 1) {
    if (series > s21_MAX_double) {
      series = 0;
    } else {
      series = 1. / series;
    }
  }
  if (series > s21_MAX_double) {
    return s21_INF;
  }
  return series;
}

long double s21_fmod(double x, double y) {
  return (x && y) || y != 0 ? (x / y - (int)(x / y)) * y : s21_NAN;
}

long double s21_sin(double x) {
  long double res;

  x = s21_fmod(x, 2 * s21_PI);
  while (x > s21_PI) {
    x = x - 2 * s21_PI;
  }

  res = x;
  int k = 1;
  long double temp = x;
  while (s21_fabs(temp) > s21_EPS) {
    temp = (-temp * x * x) / ((2 * k + 1) * (2 * k));
    res = res + temp;
    k++;
  }
  return res;
}

long double s21_asin_x_05(double x) {
  int i = 3;
  double num = x, div_res = 1, res = x, div = 1;
  do {
    div *= i - 1;
    num *= x * x * (i - 2);
    div_res = num / (div * i);
    res += div_res;
    i += 2;
  } while (div_res > ASIN_EPS);
  return res;
}

long double s21_asin(double x) {
  long double res = s21_NAN;
  if ((x >= -1 - ASIN_EPS) && (x <= 1 + ASIN_EPS)) {
    short sign = 1;
    if (x < 0) {
      x = -x;
      sign = -1;
    }
    if (x < 0.5)
      res = s21_asin_x_05(x);
    else
      res = s21_PI / 2 - 2 * s21_asin_x_05(s21_pow((1 - x) / 2, 0.5));
    res *= sign;
  }
  return res;
}

long double s21_cos(double x) {
  long double res;

  x = s21_fmod(x, 2 * s21_PI);
  while (x > s21_PI) {
    x = x - 2 * s21_PI;
  }
  res = 1;
  int z_flag = 0;

  int k = 1;
  long double temp = 1;
  while (s21_fabs(temp) > s21_EPS && z_flag == 0) {
    temp = (-temp * x * x) / ((2.0 * k - 1) * (2.0 * k));
    res = res + temp;
    k++;
  }
  return res;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_acos(double x) {
  return (x < -1 || x > 1)     ? s21_NAN
         : (x == -1 || x == 1) ? s21_PI * (1 - x) / 2
                               : s21_PI / 2. - s21_asin(x);
}

long double atan_mod(double x) {
  long double res = x;
  long double temp = x;
  for (int i = 1; s21_fabs(temp) > s21_EPS; i++) {
    temp = -1 * temp * x * x * (2 * i - 1) / (2 * i + 1);
    res = res + temp;
  }
  return res;
}

long double s21_atan(double x) {
  long double res = x;
  if (x < 1.0 && x > -1.0) {
    res = atan_mod(x);
  } else if (x == 1) {
    res = s21_PI / 4;
  } else if (x == -1) {
    res = -s21_PI / 4;
  } else if (x > 1) {
    res = s21_PI / 2 - atan_mod(1 / x);
  } else if (x < -1) {
    res = -s21_PI / 2 - atan_mod(1 / x);
  }
  return res;
}

void tr_e(double x, opt *param) {
  long double i = 1;
  int e = 0;
  param->s_n = x < 0 ? -1 : 1;
  x *= param->s_n;
  while (x >= 10) {
    x /= 10.;
    i *= 10;
    e++;
  }
  param->m_a = x;
  param->pow = i;
  param->E = e;
}

long double p_log(double x) {
  x--;
  long double r = x, t = x;
  long double i = 2;
  while (s21_fabs(r) > s21_EPS) {
    r *= -x * (i - 1) / i;
    i += 1;
    t += r;
  }
  return t;
}

long double e_log(double x) {
  opt param;
  tr_e(x, &param);
  x = param.m_a * param.s_n / 10;
  return p_log(x) + (param.E + 1) * s21_ln10;
}

long double s21_log(double x) {
  return (x > 0 && x < 2) ? p_log(x)
         : (x < 0)        ? s21_NAN
         : (x == 0)       ? -s21_INF
                          : e_log(x);
}

long double s21_pow(double b, double e) {
  long double num;
  if (b < 0) {
    if ((long int)e == e) {
      if (e > 0) {
        num = b;
        for (long int i = 0; i < (long int)e - 1; i++) {
          num *= b;
        }
      } else if (e == 0) {
        num = 1;
      } else {
        num = 1 / b;
        for (long int i = 0; i < (long int)e * (-1) - 1; i++) {
          num /= b;
        }
      }
    } else {
      if (e == -s21_INF || e == s21_INF) {
        if (b * (-1) < 1) {
          num = 0;
        } else if (b * (-1) == 1) {
          num = 1;
        } else {
          if (e == -s21_INF) {
            num = 0;
          } else {
            num = s21_INF;
          }
        }
      } else {
        num = -s21_NAN;
      }
    }
  } else if (b == 0) {
    num = e == 0 ? 1 : 0;
  } else if (b == 1) {
    num = 1;
  } else {
    if ((long int)e == e) {
      if (e > 0) {
        num = b;
        for (long int i = 0; i < (long int)e - 1; i++) {
          num *= b;
        }
      } else if (e == 0) {
        num = 1;
      } else {
        num = 1 / b;
        for (long int i = 0; i < (long int)e * (-1) - 1; i++) {
          num /= b;
        }
      }
    } else {
      num = s21_exp(e * (double)s21_log(b));
    }
  }
  return num;
}

long double w_sqrt(long double r, long double t, double x) {
  while (s21_fabs(r - t) > s21_EPS) {
    t = r;
    r = (t + x / t) / 2;
  }
  return r;
}

long double s21_sqrt(double x) {
  long double r = 4, t = 0;
  return (x < 0) ? -s21_NAN : w_sqrt(r, t, x);
}

long double s21_floor(double x) {
  if (x < 0) {
    x -= 0.9999999;
  }
  int answer = (int)x;
  return answer;
}

long double s21_ceil(double x) {
  long int cei = (long int)x;
  if (cei < x) {
    cei++;
  }
  return x == 0 ? 0 : cei;
}
