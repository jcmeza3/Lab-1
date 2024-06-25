# Compiler
CC = cc
# Compiler flags
CFLAGS = -Wall -g
# Executable name
TARGET = tokenizer
# Object files
OBJS = uimain.o tokenizer.o history.o

# Default target
all: $(TARGET)

# Linking object files to create executable
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

# Clean target
clean:
	rm -f $(OBJS) $(TARGET)
