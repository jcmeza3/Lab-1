# Define the compiler
CC = cc

# Define flags
CFLAGS = -Wall -g

# Define the target executable
TARGET = tokenizer

# Define object files
OBJS = uimain.o tokenizer.o history.o

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile uimain.c
uimain.o: uimain.c tokenizer.h history.h
	$(CC) $(CFLAGS) -c uimain.c

# Compile tokenizer.c
tokenizer.o: tokenizer.c tokenizer.h
	$(CC) $(CFLAGS) -c tokenizer.c

# Compile history.c
history.o: history.c history.h
	$(CC) $(CFLAGS) -c history.c

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
