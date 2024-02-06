#include "s21_math.h"

int s21_abs(int x) { return (x > 0) ? x : -x; }

long double s21_fabs(double x) {
  if (x < 0) x = -x;
  return (long double)x;
}

long double s21_ceil(double x) {
  long double res = 0;
  if (S21_check_NAN(x) || S21_check_INF(x))
    res = x;
  else {
    int whole = (int)x;
    if (x > 0 && (x - whole)) whole += 1;
    res = whole;
    if (res == 0 && x < 0) res = -res;
  }
  return res;
}

long double s21_floor(double x) {
  int whole = (int)x;
  if (S21_check_NAN(x) || S21_check_INF(x))
    whole = x;
  else if (x < 0 && (x - whole))
    whole -= 1;
  return (long double)whole;
}

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (y == 0 || S21_check_INF(x) ||
      (S21_check_INF(x) && S21_check_INF(y) && x != y))
    res = S21_NAN;
  else if (S21_check_INF(y))
    res = (long double)x;
  else {
    long long int mod = 0;
    mod = x / y;
    res = (long double)x - mod * (long double)y;
  }
  return res;
}

long double s21_log(double x) {  //итерационный метод Галея
  long double res = 0;
  if (S21_check_INF(x))
    res = x;
  else if (x == 0)
    res = S21_INF_NEG;
  else if (x < 0)
    res = S21_NAN;
  else {
    int ex_pow = 0;
    for (; x >= S21_EXP; ex_pow++) x /= S21_EXP;
    for (int i = 0; i < 100; ++i) {
      res = res + 2 * (x - s21_exp(res)) / (x + s21_exp(res));
    }
    res += ex_pow;
  }
  return res;
}

long double s21_pow(double base, double exp) {  // res=e^(exp*ln(base))
  long double res = 0;
  int sign = 0;
  if (!exp)
    res = 1;
  else if (base == S21_INF_NEG && exp == S21_INF_NEG)
    res = 0;
  else if (base == S21_INF_NEG && exp == S21_INF_POS)
    res = S21_INF_POS;
  else if (base < 0 && exp != (long long int)exp)
    res = S21_NAN;
  else {
    if (base < 0) {  // если x отриц.
      sign = -1;
    } else {
      sign = 1;
    }
    res = s21_exp(exp * s21_log(base * sign));
    if (s21_fmod(exp, 2)) res *= sign;
  }
  return res;
}

long double s21_exp(double x) {
  long double res = 1;
  long double temp = 1;
  long double count = 1;
  int sign = 0;
  if (x < 0) {
    x *= -1;
    sign = 1;
  }
  while (s21_fabs(temp) > S21_EPS) {
    temp *= x / count;
    ++count;
    res += temp;
    if (res > S21_MAX_DOUBLE) {  // если x-> +inf
      res = S21_INF_POS;
      break;
    }
  }
  if (sign == 1) {
    if (res > S21_MAX_DOUBLE) {  // если x = -inf
      res = 0;
    } else
      res = 1. / res;  // если x отриц.
  }
  return res;
}

long double s21_cos(double x) {
  x = s21_fmod(x, 2 * S21_PI);
  long double res = 1;
  long double result = 1;
  if (x == 0) {
    result = 1;
  } else if (x == S21_PI) {
    result = -1;
  } else if (S21_check_INF(x) || S21_check_NAN(x)) {
    result = S21_NAN;
  } else if (x == S21_PI_2 || x == (-1) * S21_PI_2) {
    result = 0;
  } else {
    for (int i = 1; i < 1000; i++) {
      res *= -1 * x * x / ((2 * i - 1) * (2 * i));
      result += res;
    }
  }

  return result;
}

long double s21_sin(double x) {
  x = s21_fmod(x, 2 * S21_PI);
  long double result = x, res = x;
  if (x == 0 || x == S21_PI) {
    result = 0;
  } else if (x == S21_PI_2) {
    result = 1;
  } else if (x == (-1) * S21_PI_2) {
    result = -1;
  } else if (S21_check_INF(x) || S21_check_NAN(x)) {
    result = S21_NAN;
  } else {
    for (int i = 1; i < 1000; i++) {
      res = -1 * res * x * x / (2 * i * (2 * i + 1));
      result += res;
    }
  }
  return result;
}

long double s21_tan(double x) {
  long double result;
  if (x == 0 || x == S21_PI) {
    result = 0;
  } else if (x == S21_PI_4) {
    result = 1;
  } else if (x == S21_PI_34) {
    result = -1;
  } else if (x == S21_PI_2) {
    result = 16331239353195370.0;
  } else if (x == (-1) * S21_PI_2) {
    result = -16331239353195370.0;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}

long double s21_atan(double x) {
  long double result = 0;
  if (x == 1)
    result = S21_PI_4;
  else if (x == -1)
    result = S21_PI_4 * (-1);
  else if (x == 0)
    result = 0;
  else if (x == S21_INF_POS)
    result = S21_PI_2;
  else if (x == S21_INF_NEG)
    result = (-1) * S21_PI_2;
  else if (x == S21_PI_2)
    result = 1.003884821853887214L;
  else if (x == -S21_PI_2)
    result = -1.003884821853887214L;
  else if (x != x)
    result = S21_NAN;
  else if (-1. < x && x < 1.) {
    for (int i = 0; i < 1000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
    }
  } else {
    for (int i = 0; i < 1000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
    }
    result = S21_PI * s21_sqrt(x * x) / (2 * x) - result;
  }
  return result;
}

long double s21_asin(double x) {
  long double result = 0;
  if (x == 1) {
    result = S21_PI_2;
  } else if (x == -1) {
    result = S21_PI_2 * (-1);
  } else if (x < -1 || x > 1) {
    result = S21_NAN;
  } else if (x == 0) {
    result = 0;
  } else {
    result = s21_atan(x / (s21_sqrt(1 - x * x)));
  }
  return result;
}

long double s21_acos(double x) {
  long double result = 0;
  if (x == 0) {
    result = S21_PI_2;
  } else if (x == -1) {
    result = S21_PI;
  } else if (x == S21_INF_POS) {
    result = S21_INF_POS;
  } else if (x == S21_INF_NEG) {
    result = S21_INF_NEG;
  } else if (x < -1 || x > 1 || S21_check_NAN(x)) {
    result = S21_NAN;
  } else if (x == 1) {
    result = 0;
  } else {
    if (x > 0 && x) {
      result = s21_atan((s21_sqrt(1 - x * x)) / x);
    } else if (x < 0) {
      result = S21_PI + s21_atan((s21_sqrt(1 - x * x)) / x);
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = 0;
  result = s21_pow(x, 0.5);
  if (x < 0) {
    result = S21_NAN;
  }
  return result;
}