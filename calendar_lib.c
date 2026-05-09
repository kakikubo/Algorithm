#include "calendar_lib.h"

int getMonthDays(int y, int m)
{
  int dm;

  switch(m){
  case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    dm = 31;
    break;
  case 4: case 6: case 9: case 11:
    dm = 30;
    break;
  case 2:
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
      dm = 29;
    else
      dm = 28;
    break;
  default:
    dm = 0;
  }
  return dm;
}

int getWeekDay(int y, int m, int d)
{
  int w;
  if(m == 1 || m == 2){
    y--;
    m += 12;
  }
  w = (y + y/4 - y/100 + y/400 + (13*m + 8)/5 + d) % 7;

  return w;
}
