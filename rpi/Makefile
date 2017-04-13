# pass variable to other makefiles ( make it vissible )
export INCLUDES = -I${PWD}/application
export SOURCE_MAIN = ${PWD} 

all:
	make	 -C ./application
	make -C ./tests 
clean:
	make -C ./application clean
	make -C ./tests clean
test:
	make -C ./tests