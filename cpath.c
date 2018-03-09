#include "cpath.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <stdio.h>

char** path_split(char* path) {
  size_t len = strlen(path);
  // Count the slashes, a path can't contain more components than the number of
  // slashes + 3 ( NULL, missing prefix, plus one for split)
  int i;
  int slashes = 3;
  for(i = 0; i < len; i++) {
    if(path[i] == '/') {
      slashes += 1; // For every slash, increment the counter
    }
  }
  // Allocate an array to hold the maximum possible number of path components,
  // and fill the array with NULL
  char** result = malloc(slashes * sizeof(char*));
  for(i = 0; i < slashes; i++) {
    result[i] = NULL;
  }

  // Fill the array with path components
  i = 0;
  char* cpy = strdup(path);
  int b = 0;
  do {
    char* basec = strdup(cpy);
    char* dirc = strdup(cpy);
    char* base = basename(basec);
    char* dir = dirname(dirc);
    result[i] = strdup(base);
    free(cpy);
    cpy = strdup(dir);
    // If we have run out of components, stop parsing
    if(strcmp(dir, ".") == 0 || strcmp(dir, "/") == 0) {
      b = 1;
      i++;
      result[i] = strdup(dir);
    }
    free(basec);
    free(dirc);
    i++;
  } while(i < slashes - 1 && b == 0);
  free(cpy);
  // Reverse components so they are in the correct order
  int j = i - 1;
  for(i = 0; i < j/2; i++) {
    char* temp = result[i];
    result[i] = result[j-i];
    result[j-i] = temp;
  }
  for(i = j + 1; i < slashes; i++) {
    result[i] = NULL;
  }
  return result;
}
