#ifndef S21_MATH
#define S21_MATH

#include <limits.h>

#define S21_PI 3.14159265358979323846264338327950288
#define S21_PI_2 (S21_PI / 2.F)
#define S21_PI_34 (3.F * S21_PI / 4.F)
#define S21_PI_4 (S21_PI / 4.F)
#define S21_EXP 2.7182818284590452353602874713526624
#define S21_EPS 1e-12
#define S21_MAX_DOUBLE 1.7976931348623157e308

#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define S21_NAN 0.0 / 0.0

#define S21_check_NAN(x) (x != x)
#define S21_check_INF(x) (x == S21_INF_NEG || x == S21_INF_POS)

int s21_abs(int x);  //вычисляет абсолютное значение целого числа
long double s21_acos(double x);  //вычисляет арккосинус
long double s21_asin(double x);  //вычисляет арксинус
long double s21_atan(double x);  //вычисляет арктангенс
long double s21_ceil(double x);  //возвращает ближайшее целое число, не меньшее
                                 //заданного значения
long double s21_cos(double x);   //вычисляет косинус
long double s21_exp(
    double x);  //возвращает значение e, возведенное в заданную степень
long double s21_fabs(
    double x);  //вычисляет абсолютное значение числа с плавающей точкой
long double s21_floor(double x);  //возвращает ближайшее целое число, не
                                  //превышающее заданное значение
long double s21_fmod(double x,
                     double y);  //остаток операции деления с плавающей точкой
long double s21_log(double x);  //вычисляет натуральный логарифм
long double s21_pow(double base,
                    double exp);  //возводит число в заданную степень
long double s21_sin(double x);  //вычисляет синус
long double s21_sqrt(double x);  //вычисляет квадратный корень
long double s21_tan(double x);  //вычисляет тангенс

#endif