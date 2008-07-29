#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

main()
{
  int you;
  int coin;
  char muki[][10] = {"", "表", "裏"}; // これどういう意味？FIXME

  srand(time(NULL));
  printf("表は1,裏は2,終了は他の値を入力して下さい\n");
  while(1){
    coin = rand() % 2 + 1;
    printf("コインを投げました。表？裏？");
    scanf("%d", &you);
    if(you < 1 || you > 2)
      break;
    else{
      printf("あなた:%s コイン:%s\n", muki[you] , muki[coin]);
      printf("%s\n", (you == coin) ? "あたり" : "はずれ" );
    }

    printf("\n");
  }
}
