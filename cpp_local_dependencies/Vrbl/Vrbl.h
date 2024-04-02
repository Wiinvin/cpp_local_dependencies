// include standard C libraries
//
#include <string.h> // string comparison stuff
#include <stdio.h>  // fprintf, etc.
#include <iostream> // not currently in use

// make sure definitions are only made once
//
#ifndef VERBOSITY_LEVEL
#define VERBOSITY_LEVEL

// Vrbl: a class that serves to encapsulate a hierarchy of verbosity levels.
// Each verbosity level corresponds to various amounts of output when running a
// program - what this actually means is up to the author of that particular
// class or utility.
//
// These verbosity levels are represented as integers. However, it is often
// useful to be able to specify them via char* (i.e. as command line
// arguments). This class serves to facilitate this.
//
// Almost all of the members of this class are static. This is because this
// class is intended to be manipulated only by the Cmdl class, at the very
// beginning of execution. After this, every other Vrbl instance will share the
// same methods and internal data as the initial Vrbl instance in Cmdl. Most
// classes and most utilities should have their own local instance.
//
// Note that classes that have a member of Vrbl type do not need to explicitly
// call the constructor for Vrbl - the compiler uses the default constructor,
// which is perfectly adequate.
// 
class Vrbl {

  //---------------------------------------------------------------------------
  //
  // public constants
  //
  //---------------------------------------------------------------------------
public:

  // define the class name
  //
  static const char* CLASS_NAME;

  // strings to use when converting string input (i.e. "BRIEF") to
  // an integer representation
  //
  static const char* VERBOSITY_LEVEL_STRINGS [];

  // enumerate the various verbosity levels that are supported
  //
  enum VERBOSITY {LEVEL_NONE = 0, LEVEL_BRIEF, LEVEL_SHORT, LEVEL_MEDIUM, 
		  LEVEL_DETAILED, LEVEL_FULL, DEF_LEVEL = LEVEL_NONE};
  static const long NUM_LEVELS;

  //---------------------------------------------------------------------------
  //
  // protected data
  //
  //---------------------------------------------------------------------------
protected:

  // the central piece of this class is an integer which holds one of the
  // values from the `VERBOSITY' enum
  //
  static long value_d;

  //---------------------------------------------------------------------------
  //
  // required public methods (vrbl_00)
  //
  //---------------------------------------------------------------------------
public:

  // method: default constructor
  //
  Vrbl();

  // method: constructor, integer as argument
  // probably should never be used (see documentation in vrbl_00.cc)
  //
  Vrbl(long level_a);
  
  // method: constructor, char* as argument
  // probably should never be used (see documentation in vrbl_00.cc)  
  //
  Vrbl(char* level_a);

  // method: name
  //
  static const char* name() {
    return CLASS_NAME;
  }

  //---------------------------------------------------------------------------
  //
  // public methods: operator overloads
  //
  //---------------------------------------------------------------------------

  // method: operator=
  //
  Vrbl& operator= (long arg) {
    value_d = (long)arg;
    return *this;
  }

  // method: operator >
  //
  bool operator> (long arg) {
    return (value_d > (long)arg);
  }
  
  // method: operator >=
  //
  bool operator>= (long arg) {
    return (value_d >= (long)arg);
  }
  
  // method: operator !=
  //
  bool operator!= (long arg) {
    return (value_d != (long)arg);
  }

  // method: operator <
  //
  bool operator< (long arg) {
    return (value_d < (long)arg);
  }
  
  // method: operator <=
  //
  bool operator<= (long arg) {
    return (value_d <= (long)arg);
  }
  
  // method: operator ==
  //
  bool operator== (long arg) {
    return (value_d == (long)arg);
  }

  //---------------------------------------------------------------------------
  //
  // public methods: set and get methods (vrbl_01)
  //
  //---------------------------------------------------------------------------

  // method: set verbosity level with integer as argument
  //
  static bool set_level(long arg);

  // method: set verbosity level with char* as argument
  //
  static bool set_level(char* arg);  

  // method: get_level
  //
  static long get_level();

  static const char* get_level_string();

  // mappings / conversions
  //
  static long map_string_to_level(char* str);
  static const char* map_level_to_string(long level);

  //---------------------------------------------------------------------------
  //
  // private methods (vrbl_02)
  //
  //---------------------------------------------------------------------------
private:

  // method: print_opions
  //
  static bool print_options();

  // method: downcase_char_array
  //
  static char* downcase_char_array(const char* array);
};
//
// end of class

// end of include file
//
#endif
