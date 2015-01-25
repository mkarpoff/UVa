GCC=g++-4.8
CFLAGS= -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
EXE=ans
SRC=./
TESTSCRIPT=tester
TESTFILE=TestFile/1

all: $(EXE)

$(EXE): $(SRC)*.C 
		$(GCC) $(CFLAGS) -o $(EXE) $(SRC)*.C

run: $(EXE)
	./$(EXE) < $(TESTFILE)

test: $(EXE)
	$(TESTSCRIPT)

fresh: clean all

clean:
		rm -f $(EXE)

