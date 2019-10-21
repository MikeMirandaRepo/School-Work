PIPE := main.c bmatch.h
SOCK := sock.c bmatch.h
EXE1 := pipe
EXE2 := sock

all: $(EXE1) $(EXE2)

$(EXE1): $(PIPE)
	gcc $(PIPE) -o $(EXE1)

$(EXE2): $(SOCK)
	gcc $(SOCK) -o $(EXE2)
