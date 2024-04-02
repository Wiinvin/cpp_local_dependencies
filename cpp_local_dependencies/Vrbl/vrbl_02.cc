#include "Vrbl.h"

// method: downcase_char_array
//
// arguments:
//  char* array_a: an array of chars to downcase
//
// return:
//  char*: an array of chars whose members have all been downcased
//
// This method downcases all members of a char array to ease comparison in
// `map_string_to_enum'
//
char* Vrbl::downcase_char_array(const char* array_a) {

  // get the number of characters in array and allocate char array for output
  //
  long len = strlen(array_a);
  char* lower_case_array = new char[len];

  // downcase, character by character
  //
  for (long i = 0; i < len; i++) {
    lower_case_array[i] = tolower(array_a[i]);
  }

  // null-terminate and return
  //
  lower_case_array[len] = '\0';
  return lower_case_array;
}

// method: print_options
//
// arguments: none
//
// returns: none
//
// print out all available levels to stdout
//
bool Vrbl::print_options() {
  fprintf(stdout, " (case insensitive) debug options: ");
  for (int i = 0; i < NUM_LEVELS; i++) {
    fprintf(stdout, "%s", VERBOSITY_LEVEL_STRINGS[i]);
    if (i < NUM_LEVELS - 1)
      fprintf(stdout, ", ");
  }
  fprintf(stdout, "\n");
  return true;  
}
