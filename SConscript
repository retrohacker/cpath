env = Environment()
deps = Glob("./deps/*")
SConscript(dirs=deps)

env.Append(CPPPATH=deps)
env.Append(LIBPATH=deps)

if "test" in COMMAND_LINE_TARGETS:
  env.Append(LIBS=[
    "ctest"
  ])
  env.Program("test/test", ["cpath.c", "test/index.c"])
else:
  env.Library("cpath", [
      "cpath.c",
  ])
