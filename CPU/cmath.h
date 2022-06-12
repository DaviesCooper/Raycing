#ifndef CMATH_H
#define CMATH_H

#include <cstdint>

double fisqrt(double n) {
   double y = n;
   double x2 = y * 0.5;
   std::int64_t i = *(std::int64_t *) &y;
   // The magic number here changes because we're using double
   // precision instead of float precision
   // https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf
   i = 0x5fe6eb50c7b537a9 - ( i >> 1 );
   y = * ( double * ) &i;
   y = y * ( 1.5 - ( x2 * y * y ) );
   return y;
}

#endif