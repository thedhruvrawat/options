CC=g++
DEPS=GenericOption.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< 

GenericOption: GenericOption.o
	$(CC) -o GenericOption GenericOption.o
