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
