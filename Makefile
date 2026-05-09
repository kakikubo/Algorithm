CC     = cc
# -std=gnu89: K&R 風の暗黙 int を許容
# -Wno-*: 旧規格コードに由来する警告を抑止（学習履歴保全のためソースは書き換えない）
CFLAGS = -std=gnu89 -Wall \
         -Wno-implicit-int \
         -Wno-implicit-function-declaration \
         -Wno-return-mismatch \
         -Wno-int-conversion \
         -Wno-logical-op-parentheses

# calendar_lib.c は main を持たないライブラリのため、個別バイナリ化対象から除外する
LIB_SRCS = calendar_lib.c
SRCS = $(filter-out $(LIB_SRCS),$(wildcard *.c))
BINS = $(SRCS:.c=)

.PHONY: all clean test

all: $(BINS)

# calendar は calendar_lib.c の関数 (getMonthDays, getWeekDay) をリンクする
calendar: calendar.c calendar_lib.c calendar_lib.h
	$(CC) $(CFLAGS) -o $@ calendar.c calendar_lib.c

clean:
	rm -f $(BINS)

test: all
	@bash tests/run_tests.sh
