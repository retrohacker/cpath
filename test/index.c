#include <ctest.h>
#include <stddef.h>
#include <stdlib.h>
#include "../cpath.h"

int test1() {
  test* t = new_test("path_split: should split path");
  char** actual = path_split("./foo/bar/buzz/bazz.txt");
  char* expected[6] = {".", "foo", "bar", "buzz", "bazz.txt", NULL};
  int i;
  for(i = 0; i < 6; i++) {
    if(expected[i] == NULL || actual[i] == NULL) {
      while(actual[i] != NULL && i < 10) {
        i += 1;
      }
      equal(t, "%d", "Found %d elements and expected %d", i, 5);
      break;
    }
    equal(t, "%s", "Expected '%s' to equal '%s'", actual[i], expected[i]);
    free(actual[i]);
  }
  return done(t);
}

int test2() {
  test* t = new_test("path_split: should split path");
  char** actual = path_split("foo/bar/buzz/bazz.txt");
  char* expected[6] = {".", "foo", "bar", "buzz", "bazz.txt", NULL};
  int i;
  for(i = 0; ; i++) {
    if(expected[i] == NULL || actual[i] == NULL) {
      while(actual[i] != NULL && i < 10) {
        printf("%s\n", actual[i]);
        i += 1;
      }
      equal(t, "%d", "Found %d elements and expected %d", i, 5);
      break;
    }
    equal(t, "%s", "Expected '%s' to equal '%s'", actual[i], expected[i]);
    free(actual[i]);
  }
  free(actual);
  return done(t);
}

int test3() {
  test* t = new_test("path_split: should split path");
  char** actual = path_split("/foo/bar/buzz/bazz.txt");
  char* expected[6] = {"/", "foo", "bar", "buzz", "bazz.txt", NULL};
  int i;
  for(i = 0; ; i++) {
    if(expected[i] == NULL || actual[i] == NULL) {
      while(actual[i] != NULL && i < 10) {
        printf("%s\n", actual[i]);
        i += 1;
      }
      equal(t, "%d", "Found %d elements and expected %d", i, 5);
      break;
    }
    equal(t, "%s", "Expected '%s' to equal '%s'", actual[i], expected[i]);
    free(actual[i]);
  }
  free(actual);
  return done(t);
}

int test4() {
  test* t = new_test("path_split: should split path");
  char** actual = path_split("/foo\/bar\\/buzz\\\/bazz.txt");
  char* expected[6] = {"/", "foo", "bar\\", "buzz\\", "bazz.txt", NULL};
  int i;
  for(i = 0; ; i++) {
    if(expected[i] == NULL || actual[i] == NULL) {
      while(actual[i] != NULL && i < 10) {
        printf("%s\n", actual[i]);
        i += 1;
      }
      equal(t, "%d", "Found %d elements and expected %d", i, 5);
      break;
    }
    equal(t, "%s", "Expected '%s' to equal '%s'", actual[i], expected[i]);
    free(actual[i]);
  }
  free(actual);
  return done(t);
}

int main() {
  return test1() | test2() | test3() | test4();
}