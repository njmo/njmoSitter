# pass variable to other makefiles ( make it vissible )
export INCLUDES = -I${PWD}/application
export SOURCE_MAIN = ${PWD}

all:
	#make	 -C ./application
	make  -C tests -f Makefile.local
clean:
	rm -rf build/bin/*
	rm -rf build/obj/*
test:
	make -C ./tests