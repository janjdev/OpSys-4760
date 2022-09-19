PROJ1	= proj1
PROJ1_OBJ = proj1.o
OUTPUT	= $(PROJ1)

.SUFFIXES: .c .o

all: $(OUTPUT)

$(PROJ1): $(PROJ1_OBJ)
	gcc -ggdb -g -o $@ $(PROJ1_OBJ)

.c.o:
	gcc -ggdb -g -c $<

.PHONY: clean
clean:
	/bin/rm -f $(OUTPUT) *.o