env = Environment()
deps = Glob("./deps/*")
SConscript(dirs=deps)

env.Append(CPPPATH=deps)
env.Append(LIBPATH=deps)

env.Library("cpath", [
    "cpath.c",
])

if "test" in COMMAND_LINE_TARGETS:
  env.Append(LIBS=[
    "ctest"
  ])
  env.Append(CCFLAGS=['-g'])
  env.Program("test/test", ["cpath.c", "test/index.c"])
