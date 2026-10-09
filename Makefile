all: build/libpinnacle.so tests

CFILES = $(wildcard src/*.c)
OFILES = $(CFILES:src/%.c=build/engine/%.o)
COPTS = -Iinclude -fPIC

targets:
	@echo "targets:"
	@echo "  build:"
	@echo "    NewtonEngine 	 - Build the engine"
	@echo "    all 	 			 - Build the engine and test programs"
	@echo "    tests 			 - Build the test programs"
	@echo "    install           - Builds and installs Pinnacle"
	@echo "  clean:"
	@echo "    clean             - Cleans the build directory"
	@echo "  misc:"
	@echo "    targets           - Displays this message"

deps:
	@echo "Dependencies: libc, liballegro(For some tests)"

build/engine/%.o: src/%.c include/%.h
	@gcc $(COPTS) -c $< -o $@

build/tests/VectorTest: tests/VectorTest
	@make -f $</Makefile

build/engine:
	@mkdir -p "build/engine"

build/tests:
	@mkdir -p "build/tests"

build/libpinnacle.so: build/engine $(OFILES)
	@gcc -shared -o build/libpinnacle.so $(OFILES)

tests: build/tests build/tests/VectorTest

clean:
	@rm -rf build

install: