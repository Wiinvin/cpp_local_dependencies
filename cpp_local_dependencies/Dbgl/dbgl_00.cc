#include "Dbgl.h"

//-----------------------------------------------------------------------------
//
// basic required methods
//
//-----------------------------------------------------------------------------

// method: default constructor
//
// arguments: none
//
// This method implements the default constructor for the Dbgl class. It
// doesn't do anything - we want to be able to instantiate the class from
// anywhere without affecting its the static ("global") state (read `value_d')
//
Dbgl::Dbgl() {
  if (value_d >= LEVEL_BRIEF) {
    fprintf(stdout, "%s: initializing a Dbgl object\n", __PRETTY_FUNCTION__);
  }
}

// method: constructor, integer as argument
//
// arguments:
//  long level_a: integer form of debug level (i.e. Dbgl::FULL)
//
// Probably should never be used.
//  The Cmdl class should just use the default (empty) constructor and then
//   `set_level' after parsing the command line arguments.
//  All other classes should probably just get their debug levels by using the
//   default constructor so that the `value_d' set by the command line shows up
//   there due to all of the members of the Dbgl class being static
//  Included here for the sake of completeness.
//
Dbgl::Dbgl(long level_a) {
  value_d = level_a;
}

// method: constructor, char* as argument
//
// arguments:
//  char* level_a: char* form of debug level (i.e. "FULL" or "full")
//
// Probably should never be used.
//  The Cmdl class should just use the default (empty) constructor and then
//   `set_level' after parsing the command line arguments.
//  All other classes should probably just get their debug levels by using the
//   default constructor so that the `value_d' set by the command line shows up
//   there due to all of the members of the Dbgl class being static
//  Included here for the sake of completeness.
//
Dbgl::Dbgl(char* level_a) {

  // if we are passed an empty char array, simply set the default level.
  //
  if (level_a[0] == '\0') {
    set_level(DEF_LEVEL);
  }

  // otherwise (non-empty char array), use the set method for char
  // arrays, which handles the char array to long conversion
  //
  else {
    set_level(level_a);
  }
}

//-----------------------------------------------------------------------------
//
// we define non-integral constants in the default constructor
//
//-----------------------------------------------------------------------------

const char* Dbgl::DEBUG_LEVEL_STRINGS[] = {"NONE", "BRIEF", "SHORT",
					   "MEDIUM", "DETAILED", "FULL"};
const long Dbgl::NUM_LEVELS = 6;

const char* Dbgl::CLASS_NAME = "Dbgl";

long Dbgl::value_d = Dbgl::LEVEL_NONE;
