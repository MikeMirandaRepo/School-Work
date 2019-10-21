NIO := proj3.cpp hfunc.h
MMAPIO := proj3mmap.cpp hfunc.h
EXE1 := normalIO
EXE2 := mmapIO

all: $(EXE1) $(EXE2)

$(EXE1): $(NIO)
	g++ $(NIO) -o $(EXE1)
$(EXE2): $(MMAPIO)
	g++ $(MMAPIO) -o $(EXE2)
