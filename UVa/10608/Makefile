GCC=g++-4.8
CFLAGS= -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE -g 
EXE=ans
SRC=./
TESTSCRIPT=./tester.sh

all: $(EXE)

$(EXE): $(SRC)*.C 
		$(GCC) $(CFLAGS) -o $(EXE) $(SRC)*.C

clang:
		clang $(CFLAGS) -o $(EXE) $(SRC)*.C

run: $(EXE)
	./$(EXE) < test_files/input01

test: $(EXE)
	./$(TESTSCRIPT)

fresh: clean all

clean:
		rm -f $(EXE)

