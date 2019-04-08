CC=clang++
CC_FLAGS=-O3 -std=c++17 -lc++abi -Wall -Werror -pedantic \
			-fno-exceptions -fno-rtti -pthreads

BINS=bench 

all: $(BINS)

bench: bench.cpp
	$(CC) $(CC_FLAGS) -o bench bench.cpp -lbenchmark

clean:
	rm -f $(BINS)
