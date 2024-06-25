all: tokenizer

tokenizer: main.o tokenizer.o history.o
    cc -o tokenizer main.o tokenizer.o history.o

main.o: main.c tokenizer.h history.h
    cc -c main.c

tokenizer.o: tokenizer.c tokenizer.h
    cc -c tokenizer.c

history.o: history.c history.h
    cc -c history.c

clean:
    rm -f *.o tokenizer
