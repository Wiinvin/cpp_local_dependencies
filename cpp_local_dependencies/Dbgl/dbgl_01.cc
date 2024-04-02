#include "Dbgl.h"

// method: set_level
//
// arguments:
//  long level_a: an integer representing the value to set
//
// return:
//  bool indicative of success
//
// This method sets the debug level
//
bool Dbgl::set_level(long level_a) {
  value_d = level_a;
  return true;
}

// method: set_level
//
// arguments:
//  char* level_a: an string representing the debug level
//
// return:
//  bool indicative of success
//
// This method sets the debug level
//
bool Dbgl::set_level(char* level_a) {

  // if we are passed an empty char array, simply set the default level.
  // also indicate that this occured in stdout. Probably should never happen.
  //
  if (level_a[0] == '\0') {
    set_level(DEF_LEVEL);
    fprintf(stdout, "**> Dbgl::set_level(char*) passed an empty char array\n");
  }

  // otherwise (non-empty char array), get the level integer
  // associated with that debug string
  //
  long level = map_string_to_level(level_a);

  // if `level_a' is not in DEBUG_LEVEL_STRINGS, this will be caught here
  //
  if (level == -1) {
    fprintf(stdout,
	    "**> Dbgl::set_level(char*), unable to parse \'%s\'\n",
	    level_a);
    print_options();
    return false;
  }

  // if everything has gone correctly, set the level and return
  //
  value_d = level;
  return true;
}

// method: get_level
//
// arguments:
//  none
//
// returns:
//  long level: the value of the debug level
//
// This method returns the debug level
//
long Dbgl::get_level() {
  return value_d;
}

// method: get_level_string
//
// arguments:
//  none
//
// returns:
//  long level: the value of the debug level
//
// This method returns the debug level
//
const char* Dbgl::get_level_string() {
  return map_level_to_string(value_d);
}

// method: map_level_to_string
//
// arguments:
//  long level_a: level to map to string
//
// returns:
//  char*: a string corresponding to the current debug level
//
// This method returns the debug level as a char*
//
const char* Dbgl::map_level_to_string(long level_a) {
  return DEBUG_LEVEL_STRINGS[level_a];
}
  
// method: map_string_to_level
//
// arguments:
//  char* array_a: an array of chars representing a debug level (i.e. "full")
//
// return:
//  long: the level associated with the string argument
//
// This method downcases all members of a char array to ease
// comparison in `map_string_to_level'
//
long Dbgl::map_string_to_level(char* array_a) {
  bool match;
  long level;
  char* downcased_level_string;
  char* downcased_str_a = downcase_char_array(array_a);

  // loop over all DEBUG_LEVEL_STRINGS
  //
  for (level = 0; level < NUM_LEVELS; level++) {

    // downcase the corresponging level string
    //
    downcased_level_string = downcase_char_array(Dbgl::DEBUG_LEVEL_STRINGS[level]);

    // do the comparsion
    //
    match = !strcmp(downcased_level_string, downcased_str_a);

    // if we have found a match, return the index of the match
    //
    if (match) {
      return level;
    }
  }

  // if no match has been found, signal an error
  //
  return -1;
}
