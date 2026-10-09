CFILES = $(wildcard tests/VectorTest/*.c)
OFILES = $(CFILES:tests/VectorTest/%.c=build/tests/VectorTest/%.o)
COPTS = -I/usr/local/include

all: build/tests/VectorTest/ $(OFILES)
	@gcc -o build/tests/VectorTest/VectorTest $(OFILES) -Lbuild -lpinnacle -L/usr/local/lib/ -lallegro -lallegro_image -Wl,-rpath,/usr/local/lib,-rpath,./build

build/tests/VectorTest/%.o: tests/VectorTest/%.c
	@gcc $(COPTS) -c $< -o $@

build/tests/VectorTest/:
	@mkdir -p $@