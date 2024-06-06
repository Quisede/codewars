// The cockroach is one of the fastest insects. Write a function which takes its speed in km per hour and returns it in cm per second, rounded down to the integer (= floored).

// For example:

// 1.08 --> 30
// Note! The input is a Real number (actual type is language dependent) and is >= 0. The result should be an Integer.
#include <math.h>
int cockroach_speed(double s)
{
    //сначала переведем в метры в секунду
  s = s*100000/3600;
  //округляем в меньшую сторону
  floor(s);
    return s; //Good Luck!
}
