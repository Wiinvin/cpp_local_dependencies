
# define the object files
#
OBJ = dbgl_00.o dbgl_01.o dbgl_02.o
mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))


# define compilation, linking and archiving flags
#
#CFLAGS += -c -O2 -Wall
CFLAGS += -g
AR = gcc-ar rvs

# define dependencies
#
DEPS = Dbgl.h ./Makefile

# define include files
#
INCLUDES=-Iprojects/data/ml_learn/exp/exp_0002/feat_pipeline/mplpc/include/ -I

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
	cp Dbgl.h //
	$(AR) ../lib/libdsp.a $(OBJ)

# define a special target to clean the directory
#
clean:
	rm -f $(OBJ)

#
# end of file
