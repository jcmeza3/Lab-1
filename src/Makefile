all: tokenizer

tokenizer: uimain.o tokenizer.o history.o
    cc -o tokenizer uimain.o tokenizer.o history.o

uimain.o: uimain.c tokenizer.h history.h
    cc -c uimain.c

tokenizer.o: tokenizer.c tokenizer.h
    cc -c tokenizer.c

history.o: history.c history.h
    cc -c history.c

clean:
    rm -f *.o tokenizer
