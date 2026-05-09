CC     = cc
# -std=gnu89: K&R 風の暗黙 int を許容
# -Wno-error=*: 旧規格コードの新しいエラー昇格を警告に戻す
CFLAGS = -std=gnu89 -Wall \
         -Wno-error=implicit-int \
         -Wno-error=implicit-function-declaration \
         -Wno-error=return-mismatch \
         -Wno-error=int-conversion

SRCS = $(wildcard *.c)
BINS = $(SRCS:.c=)

.PHONY: all clean

all: $(BINS)

clean:
	rm -f $(BINS)
