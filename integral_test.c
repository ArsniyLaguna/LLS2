#include "integral.h"
#include <assert.h>

double function(double x) { return sin(x); }
void integral_test_1() {
  double a = 0;    // нижний предел Интеграла
  double b = 10;   // верхний предел интеграла
  int n = 10000; // количество разбиений на отрезке

  double result = integral_trapez(a, b, n, function);
  double expect = 1.8390715;
  assert(fabs(result - expect) <= 1e-6);
}

void integral_test_2() {
  double a = 2;
  double b = 10;
  int n = 300000;
  
  double result = integral_trapez(a, b, n, function);
  double expect = 0.42292469;
  assert(fabs(result - expect) <= 1e-6);
}

void integral_test_3() {
  double a = 1;
  double b = 20;
  int n = 100000;
  
  double result = integral_trapez(a, b, n, function);
  double expect = 0.13222024;
  assert(fabs(result - expect) <= 1e-6);
}

int main() {
  integral_test_1();
  integral_test_2();
  integral_test_3();
  return 0;
}
