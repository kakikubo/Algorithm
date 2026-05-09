#include <stdio.h>
#include "calendar_lib.h"

void getYearMonth(int *, int *);
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


