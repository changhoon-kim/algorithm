CC		= gcc
CPPC		= g++ -std=c++11
CFLAGS		= -O2 -W -Wall
C_FILES		= $(wildcard *.c)
C_OBJECTS	= $(foreach obj, $(C_FILES:.c=.o), c_$(obj))
C_BINS		= $(foreach bin, $(C_FILES:.c=), c_$(bin))
CPP_FILES	= $(wildcard *.cpp)
CPP_OBJECTS	= $(CPP_FILES:.cpp=.o)
CPP_BINS	= $(CPP_FILES:.cpp=)


all : $(C_BINS) $(CPP_BINS)
	rm -rf $(C_OBJECTS) $(CPP_OBJECTS)

$(C_BINS) : $(C_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $@.o

$(C_OBJECTS) : $(C_FILES)
	$(CC) $(CFLAGS) -c -o $@ $(subst c_, , $*).c

$(CPP_BINS) : $(CPP_OBJECTS)
	$(CPPC) $(CFLAGS) -o $@ $@.o

$(CPP_OBJECTS) : $(CPP_FILES)
	$(CPPC) $(CFLAGS) -c -o $@ $*.cpp

clean :
	rm -rf *.o
