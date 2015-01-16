GCC=g++-4.8
CFLAGS= -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
EXE=
SRC=
TESTSCRIPT=

all: $(EXE)

$(EXE): $(SRC)*.C 
		$(GCC) $(CFLAGS) -o $(EXE) $(SRC)*.C

run: $(EXE)
	./$(EXE)

test: $(EXE)
	./$(TESTSCRIPT)

fresh: clean all

clean:
		rm -f $(EXE)

