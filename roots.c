#include <math.h>
#include <stdio.h>

void solveQuadratic(double a, double b, double c, double roots[2], int *root_count, double epsilon) {
  if (fabs(a) < epsilon) {
    *root_count = 0;
    return;
  }
  double discriminant = (b * b) - 4 * a * c;
  if (fabs(0-discriminant) < epsilon){
    discriminant = 0;
  }
  if (discriminant<-epsilon){
    *root_count = 0;
  }else if(discriminant > 0) {
    if (a == 1) {
      if (b > 0) {
        roots[0] = (-b - sqrt(discriminant)) / 2;
        roots[1] = c / roots[0];
      } else {
        roots[1] = (-b + sqrt(discriminant)) / 2;
        roots[0] = c / roots[1];
      }
    } else {
      roots[0] = (-b + sqrt(discriminant)) / (2 * a);
      roots[1] = (-b - sqrt(discriminant)) / (2 * a);
    }

    *root_count = 2;

    if (roots[0] > roots[1]) {
      double temp = roots[0];
      roots[0] = roots[1];
      roots[1] = temp;
    }
  } else if (discriminant == 0) {
    roots[0] = -b / (2 * a);
    *root_count = 1;
  }
}
