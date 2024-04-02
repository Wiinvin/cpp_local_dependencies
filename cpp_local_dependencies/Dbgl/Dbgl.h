// Revision History:
//
// Courtesy of NEDC group from Temple University.
// Using this for educational purposes only
//

#include <string.h> // string comparison stuff
#include <stdio.h>  // fprintf, etc.
#include <iostream> // not currently in use

// make sure definitions are only made once
//
#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL

// Dbgl: a class that serves to encapsulate a hierarchy of debugging levels.
// Each debug level corresponds to various amounts of debugging output when
// running a program - what this actually means is up to the author of that
// particular class or utility.
//
// These debug levels are represented as integers. However, it is often useful
// to be able to specify them via char* (i.e. as command line arguments). This
// class serves to facilitate this.
//
// Almost all of the members of this class are static. This is because this
// class is intended to be manipulated only by the Cmdl class, at the very
// beginning of execution. After this, every other Dbgl instance will share the
// same methods and internal data as the initial Dbgl instance in Cmdl. Each
// class should have its own instance, and most, if not all, utilities should
// have a local instance - and all should act exactly the same.
//
// Note that if some function alters its local instance of Dbgl, all other Dbgl
// instances in the program will reflect this alteration.
//
// Note that classes that have a member of Dbgl type (all cpp classes in $NFC
// should) do not need to explicitly call the constructor for Dbgl - the
// compiler uses the default constructor, which is perfectly adequate.
//
class Dbgl {

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
  static const char* DEBUG_LEVEL_STRINGS [];

  // enumerate the various debug levels that are supported
  //
  enum DEBUG {LEVEL_NONE = 0, LEVEL_BRIEF, LEVEL_SHORT, LEVEL_MEDIUM, 
	      LEVEL_DETAILED, LEVEL_FULL, DEF_LEVEL = LEVEL_NONE};
  static const long NUM_LEVELS;

  //---------------------------------------------------------------------------
  //
  // protected data
  //
  //---------------------------------------------------------------------------
protected:

  // the central piece of this class is an integer which holds one of the
  // values from the `DEBUG' enum
  //
  static long value_d;

  //---------------------------------------------------------------------------
  //
  // required public methods (dbgl_00)
  //
  //---------------------------------------------------------------------------
public:

  // method: default constructor
  //
  Dbgl();

  // method: constructor, integer as argument
  // probably should never be used (see documentation in dbgl_00.cc)
  //
  Dbgl(long level_a);
  
  // method: constructor, char* as argument
  // probably should never be used (see documentation in dbgl_00.cc)  
  //
  Dbgl(char* level_a);

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
  Dbgl& operator= (long arg) {
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
  // public methods: set and get methods (dbgl_01)
  //
  //---------------------------------------------------------------------------

  // method: set debug level with integer as argument
  //
  static bool set_level(long arg);

  // method: set debug level with char* as argument
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
  // private methods (dbgl_02)
  //
  //---------------------------------------------------------------------------
private:

  // method: print_options
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
