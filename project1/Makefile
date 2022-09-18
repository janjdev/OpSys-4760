PROJ1	= proj1
PROJ1_OBJ = proj1.o
OUTPUT	= $(PROJ1)

.SUFFIXES: .cpp .o

all: $(OUTPUT)

$(PROJ1): $(PROJ1_OBJ)
	g++ -Wall -g -o $@ $(PROJ1_OBJ)

.cpp.o:
	g++ -Wall -g -c $<

.PHONY: clean
clean:
	/bin/rm -f $(OUTPUT) *.o