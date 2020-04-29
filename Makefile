.PHONY: all
all: format build

.PHONY: format
format:
	clang-format src/*.cc include/*.hh -i

.PHONY: build
build:
	mkdir -p build
	cd build && \
	conan install .. --build missing && \
	cmake .. && \
	make

.PHONY: cpuperformance
cpuperformance:
	sudo cpupower frequency-set -g performance

.PHONY: cpupowersave
cpupowersave:
	sudo cpupower frequency-set -g powersave

.PHONY: debug
debug:
	mkdir -p build
	cd build && \
	conan install .. --build missing && \
	cmake -DCMAKE_BUILD_TYPE=debug .. && \
	make

.PHONY: clean
clean:
	rm -rf build
