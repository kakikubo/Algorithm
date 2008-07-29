#include <stdio.h>
#include <string.h>

main(int argc, char *argv[])
{

  int i;

  if(argc <= 1)
    return;
  if(strcmp(argv[1], "enum") == 0)
    for(i = 0; i < argc; i++)
      printf("argv[%d] : %s\n", i, argv[i]);
  else if(strcmp(argv[1], "count") == 0)
    printf("コマンドライン引数の数: %d\n", argc - 1);

}
