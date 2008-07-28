#include <stdio.h>

main()
{
  FILE *fp;
  char s[256];
  int i = 1;

  fp = fopen("abc.txt","r");
  if(fp == NULL)
    return;

  while(feof(fp) == 0){
    fgets(s, 255, fp);
    printf("%04d:%s", i, s);
    i++;
  }

  fclose(fp);
}

/*
どうしても上記プログラムの結果は最後の行が2度カウントされてしまいます。
だから結果は以下の通りとなります。

/Users/kakikubo/Hack/Algorithm $ ./simple-cat
0001:abcdefg
0002:hijklmn
0003:opqrstu
0004:vwxyz
0005:vwxyz

解決法は今のところ分かっていません。こりゃ本当にCを勉強しないといかんですな。

 */
