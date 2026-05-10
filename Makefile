CC     = cc
# -std=gnu89: K&R 風の暗黙 int を許容
# -Wno-*: 旧規格コードに由来する警告を抑止（学習履歴保全のためソースは書き換えない）
CFLAGS = -std=gnu89 -Wall \
         -Wno-implicit-int \
         -Wno-implicit-function-declaration \
         -Wno-return-mismatch \
         -Wno-int-conversion \
         -Wno-logical-op-parentheses

# *_lib.c は main を持たないライブラリのため、個別バイナリ化対象から除外する
LIB_SRCS = calendar_lib.c sum1ton_lib.c arraysearch_lib.c average_lib.c \
           charcat_lib.c function_lib.c graph_lib.c recursive_lib.c \
           reverse_lib.c swap_lib.c swapval_lib.c
SRCS = $(filter-out $(LIB_SRCS),$(wildcard *.c))
BINS = $(SRCS:.c=)

UNIT_TEST_BINS = tests/unit/test_calendar

.PHONY: all clean test unit-test

all: $(BINS)

# 各 .c が依存する <name>_lib.c をリンクする個別ルール
1to5: 1to5.c sum1ton_lib.c sum1ton_lib.h
	$(CC) $(CFLAGS) -o $@ 1to5.c sum1ton_lib.c
arraysearch: arraysearch.c arraysearch_lib.c arraysearch_lib.h
	$(CC) $(CFLAGS) -o $@ arraysearch.c arraysearch_lib.c
arraysearch2: arraysearch2.c arraysearch_lib.c arraysearch_lib.h
	$(CC) $(CFLAGS) -o $@ arraysearch2.c arraysearch_lib.c
arraysearch3: arraysearch3.c arraysearch_lib.c arraysearch_lib.h
	$(CC) $(CFLAGS) -o $@ arraysearch3.c arraysearch_lib.c
average: average.c average_lib.c average_lib.h
	$(CC) $(CFLAGS) -o $@ average.c average_lib.c
calendar: calendar.c calendar_lib.c calendar_lib.h
	$(CC) $(CFLAGS) -o $@ calendar.c calendar_lib.c
charcat: charcat.c charcat_lib.c charcat_lib.h
	$(CC) $(CFLAGS) -o $@ charcat.c charcat_lib.c
function: function.c function_lib.c function_lib.h
	$(CC) $(CFLAGS) -o $@ function.c function_lib.c
graph: graph.c graph_lib.c graph_lib.h
	$(CC) $(CFLAGS) -o $@ graph.c graph_lib.c
recursive: recursive.c recursive_lib.c recursive_lib.h
	$(CC) $(CFLAGS) -o $@ recursive.c recursive_lib.c
reverse: reverse.c reverse_lib.c reverse_lib.h
	$(CC) $(CFLAGS) -o $@ reverse.c reverse_lib.c
swap: swap.c swap_lib.c swap_lib.h
	$(CC) $(CFLAGS) -o $@ swap.c swap_lib.c
swapval: swapval.c swapval_lib.c swapval_lib.h
	$(CC) $(CFLAGS) -o $@ swapval.c swapval_lib.c

# MinUnit ユニットテスト (calendar_lib 用)
tests/unit/test_calendar: tests/unit/test_calendar.c calendar_lib.c calendar_lib.h tests/minunit.h
	$(CC) $(CFLAGS) -o $@ tests/unit/test_calendar.c calendar_lib.c

unit-test: $(UNIT_TEST_BINS)
	@./tests/unit/test_calendar

clean:
	rm -f $(BINS) $(UNIT_TEST_BINS)

test: all unit-test
	@bash tests/run_tests.sh
