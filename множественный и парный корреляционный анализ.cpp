#include <conio.h>
#include <stdio.h>
#include <math.h>
#define n 10

int main( )
{
   float x[n] = {99, 57, 76, 90, 45, 39, 68, 88, 85, 71};
   float y[n] = {3, 1.1, 2.9, 3, 0.8, 1.5, 2.1, 3.2, 1.2, 0.3};
   float z[n] = {37.6, 18.5, 29.1, 38.5, 18.8, 20.6, 29.6, 36.8, 15.8, 34.8};

   float x_av, y_av, z_av, x2_av, y2_av, z2_av, xy_av, xz_av, yz_av;
   float sx, sy, sz, rxy, rxz, ryz, detR;
   int i;

   printf("x\ty\tz\n");

   x_av = y_av = z_av = x2_av = y2_av = z2_av = xy_av = xz_av = yz_av = 0.0;
   for(i = 0; i < 10; i++)
   {
	   x_av += x[i];
	   y_av += y[i];
	   z_av += z[i];

	   x2_av += x[i]*x[i];
	   y2_av += y[i]*y[i];
	   z2_av += z[i]*z[i];

	   xy_av += x[i]*y[i];
	   xz_av += x[i]*z[i];
	   yz_av += y[i]*z[i];

	   printf("%.3f\t%.3f\t%.3f\n", x[i], y[i], z[i]);
   }

   printf("%.3f\t%.3f\t%.3f\n", x_av, y_av, z_av);

   x_av /= n;
   y_av /= n;
   z_av /= n;

   x2_av /= n;
   y2_av /= n;
   z2_av /= n;

   xy_av /= n;
   xz_av /= n;
   yz_av /= n;


   sx = sqrt(x2_av - x_av*x_av);
   sy = sqrt(y2_av - y_av*y_av);
   sz = sqrt(z2_av - z_av*z_av);

   rxy = (xy_av - x_av*y_av)/(sx*sy);
   rxz = (xz_av - x_av*z_av)/(sx*sz);
   ryz = (yz_av - y_av*z_av)/(sy*sz);

   detR = 1 - rxy*rxy;

   printf(" rxy = %.3f\n", rxy);
   printf(" rxz = %.3f\n", rxz);
   printf(" ryz = %.3f\n", ryz);
   printf("detR = %.3f\n", detR);
   
   getch();
   return 0;
}