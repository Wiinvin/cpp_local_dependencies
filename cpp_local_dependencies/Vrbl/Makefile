# define the object files
#
OBJ = vrbl_00.o vrbl_01.o vrbl_02.o

# define compilation, linking and archiving flags
#
#CFLAGS += -O2 -c -Wall
CFLAGS += -g -c

AR = gcc-ar rvs

# define dependencies
#
DEPS = Vrbl.h ./Makefile

# define include files
#
INCLUDES=-I -I

# define a dummy target
#
all: $(OBJ)

# define a target to make sure all source files are compiled
#
%.o: %.cc $(DEPS)
	g++ $(CFLAGS) $(INCLUDES) -o $@ $< 

# define a special target to install the code
#
install:
	cp Vrbl.h ../include/
	$(AR) ../lib/libdsp.a $(OBJ)

# define a special target to clean the directory
#
clean:
	rm -f $(OBJ)
#
# end of file
