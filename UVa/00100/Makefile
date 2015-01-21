GCC=g++-4.8
CFLAGS= -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
EXE=ans
SRC=./soln
TESTSCRIPT=tester.sh

all: $(EXE)

$(EXE): $(SRC)*.C 
		$(GCC) $(CFLAGS) -o $(EXE) $(SRC)*.C

clang:
		clang $(CFLAGS) -o $(EXE) $(SRC)*.C
run: $(EXE)
	./$(EXE) < TestFiles/input04

test: $(EXE)
	./$(TESTSCRIPT)

fresh: clean all

clean:
		rm -f $(EXE)

