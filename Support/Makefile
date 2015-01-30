GCC=g++-4.8
CFLAGS= -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE -g
EXE=ans
SRC=./
TESTSCRIPT=tester
TESTFILE=TestFiles/Input/01

all: $(EXE)

$(EXE): $(SRC)*.C 
		$(GCC) $(CFLAGS) -o $(EXE) $(SRC)*.C

debug:
		$(GCC) $(CFLAGS) -DDEBUG -o $(EXE) $(SRC)*.C

run: $(EXE)
	./$(EXE) < $(TESTFILE)

test: $(EXE)
	$(TESTSCRIPT)

testall: $(EXE)
	$(TESTSCRIPT) -a

fresh: clean all

clean:
		rm -f $(EXE)

