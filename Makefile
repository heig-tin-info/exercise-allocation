
CSRCS=$(wildcard *.c)
COBJS=$(patsubst %.c,%.o,$(CSRCS))
EXEC=sort

CFLAGS=-std=c99 -g -Wall -pedantic -pg
LDFLAGS=-lm -pg

all: $(EXEC)

-include $(COBJS:.o=.d)

$(EXEC): $(COBJS)
	$(CC) -o $@ $< $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^ -MMD -MF $(@:.o=.d)

clean:
	$(RM) $(EXEC) *.o a.out $(COBJS:.o=.d)

prof:
	gprof -b $(EXEC) gmon.out

.PHONY: all prof clean
