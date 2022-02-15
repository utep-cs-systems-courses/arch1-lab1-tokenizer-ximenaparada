#compiler flags.
CFLAGS=-g -O3

OBJS= history.o tokenizer.o uimain.o 

all: tokenizer

# $@=target, $^=prerequisites

tokenizer: $(OBJS)
	cc -o  $@ $^ $(CFLAGS)

#deletes compilation gen files
clean:
	rm -f *.o tokenizer

run: tokenizer
	./tokenizer

$(OBJS): tokenizer.h history.h

#uimain.o: uimain.c

#tokenizer.o: tokenizer.c tokenizer.h
#history.o: history.c history.h
