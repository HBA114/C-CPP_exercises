CC=clang
CPP=clang++
CFLAGS=-g -Wall
CPPFLAGS=-g -Wall
BINS=test filetest

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

%: %.cpp
	$(CPP) $(CPPFLAGS) $^ -o $@

clean:
	$(RM) -r $(BINS) *dSYM