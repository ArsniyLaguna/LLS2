#include <math.h>
void solveQuadratic(double a, double b, double c, double *roots,
                    int *root_count, double epsilon) {
  if (fabs(a) <= epsilon) {
    *root_count = 0;
    return;
  }

  double discriminant = b * b - 4 * a * c;

  if (sqrt(discriminant) <= epsilon) {
    discriminant = 0;
  }

  if (discriminant > epsilon) {
    double sqrt_discr = sqrt(discriminant);

    if (b >= epsilon) {
      roots[0] = (-b - sqrt_discr) / (2 * a);
      roots[1] = c / (a * roots[0]);
    } else {
      roots[1] = (-b + sqrt_discr) / (2 * a);
      roots[0] = c / (a * roots[1]);
    }

    *root_count = 2;
    if (roots[0] > roots[1]) {
      double temp = roots[0];
      roots[0] = roots[1];
      roots[1] = temp;
    }

  } else if (fabs(discriminant) <= epsilon) {
    roots[0] = -b / (2 * a);
    *root_count = 1;
  } else {
    *root_count = 0;
  }
}