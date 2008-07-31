#include <stdio.h>

void getYearMonth(int *, int *);
int  getMonthDays(int , int);
int  getWeekDay(int, int, int);
void PrintCalendar(int, int);

main()
{
  int year;     /* 西暦 */
  int month;    /* 月   */
  int days;     /* 月の日数 */
  int youbi;    /* 最初の日の曜日番号 */

  getYearMonth(&year, &month);
  days = getMonthDays(year, month);
  youbi = getWeekDay(year, month, 1);
  printf("西暦%d年 %d月\n", year, month);
  PrintCalendar(days, youbi);
}

void getYearMonth(int *py, int *pm)
{
  printf("カレンダーを表示します。\n");
  printf("西暦と月をスペースで区切って入力してください。\n");
  while(1){
    scanf("%d %d", py, pm);
    if(*pm >= 1 && *pm <= 12)
      break;
    printf("入力が間違っています。入力しなおして下さい。\n");
  }
  return;
}

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

void PrintCalendar(int dm, int dw)
{
  int n, d;

  printf("-----------------------------\n");
  printf(" Sun Mon Tue Wed Thu Fri Sat\n");
  printf("-----------------------------\n");

  for(n = 0; n < dw; n++)
    printf("    ");
  for(d = 1; d <= dm; d++){
    printf("  %2d", d);
    if(n % 7 == 6 && d != dm)
      printf("\n");
    n++;
  }
  printf("\n------------------------------\n");
  return;
}


