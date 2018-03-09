# Installation

```sh
git submodule git@github.com:retrohacker/cpath deps/cpath
```

This should automatically work with the following SConstruct setup:

```sh
env = Environment()
deps = Glob("./deps/*")
SConscript(dirs=deps)

env.Append(CPPPATH=deps)
env.Append(LIBPATH=deps)
env.Append(LIBS=[
  "cpath"
])
```

# Quick Start


```c
#include <cpath.h>

int main() {
  char ** foo = path_split("./foo/bar");
  int i = 0;
  while(foo[i] != NULL) {
    printf("%s\n", foo[i]);
    free(foo[i]);
  }
  free(foo);
  return 0;
}
```


Some more quick examples:

```c
path_split("./foo/bar/buzz/bazz.txt");
 -> [".", "foo", "bar", "buzz", "bazz.txt"]
path_split("foo/bar/buzz/bazz.txt");
 -> [".", "foo", "bar", "buzz", "bazz.txt"]
path_split("/foo/bar/buzz/bazz.txt");
 -> ["/", "foo", "bar", "buzz", "bazz.txt"]
```

# Development

```text
$ git clone --recursive git@github.com:retrohacker/cpath
$ cd cpath
$ scons test
scons: Reading SConscript files ...
scons: done reading SConscript files.
scons: Building targets ...
gcc -o test/index.o -c -Ideps/ctest test/index.c
gcc -o cpath.o -c -Ideps/ctest cpath.c
gcc -o deps/ctest/ctest.o -c deps/ctest/ctest.c
ar rc deps/ctest/libctest.a deps/ctest/ctest.o
ranlib deps/ctest/libctest.a
gcc -o test/test cpath.o test/index.o -Ldeps/ctest -lctest
scons: done building targets.
$ ./test/test
# path_split: should split path with . prefix
  [ OK ] - Expected '.' to equal '.'
  [ OK ] - Expected 'foo' to equal 'foo'
  [ OK ] - Expected 'bar' to equal 'bar'
  [ OK ] - Expected 'buzz' to equal 'buzz'
  [ OK ] - Expected 'bazz.txt' to equal 'bazz.txt'
  [ OK ] - Found 5 elements and expected 5
# path_split: should split path with no prefix
  [ OK ] - Expected '.' to equal '.'
  [ OK ] - Expected 'foo' to equal 'foo'
  [ OK ] - Expected 'bar' to equal 'bar'
  [ OK ] - Expected 'buzz' to equal 'buzz'
  [ OK ] - Expected 'bazz.txt' to equal 'bazz.txt'
  [ OK ] - Found 5 elements and expected 5
# path_split: should split path with / prefix
  [ OK ] - Expected '/' to equal '/'
  [ OK ] - Expected 'foo' to equal 'foo'
  [ OK ] - Expected 'bar' to equal 'bar'
  [ OK ] - Expected 'buzz' to equal 'buzz'
  [ OK ] - Expected 'bazz.txt' to equal 'bazz.txt'
  [ OK ] - Found 5 elements and expected 5
# path_split: should split path with escape characters
  [ OK ] - Expected '/' to equal '/'
  [ OK ] - Expected 'foo' to equal 'foo'
  [ OK ] - Expected 'bar\' to equal 'bar\'
  [ OK ] - Expected 'buzz\' to equal 'buzz\'
  [ OK ] - Expected 'bazz.txt' to equal 'bazz.txt'
  [ OK ] - Found 5 elements and expected 5
```
