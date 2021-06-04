#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float wallis_pi(int n)
{ float pi=1.0;
 for (int i=1;i<=n;i++)
 {
   pi*=(float)((4.0*i*i)/((4.0*i*i)-1.0));
   }
 return 2.0*pi;
}

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

