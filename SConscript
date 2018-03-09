env = Environment()
deps = Glob("./deps/*")
SConscript(dirs=deps)

env.Append(CPPPATH=deps)
env.Append(LIBPATH=deps)
env.Append(LIBS=[
  "ctest"
])

if "test" in COMMAND_LINE_TARGETS:
  env.Program("test/test", ["cpath.c", "test/index.c"])
else:
  env.Library("cpath", [
      "cpath.c",
  ])
