buildc:
	cmake -G "Unix Makefiles" -B ./build -S .

runc:
	cd ./build && make && ./main

reset:
	rm --recursive ./build && mkdir build

clean:
	cd ./build && make clean

all: buildc runc