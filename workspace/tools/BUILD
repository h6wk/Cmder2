

filegroup (
    name = "library_headers",
    srcs = glob([
        "*.h",
    ]),
)

# This output is going to be in the bazel-* folder
genrule (
    name = "generate_plantuml",
    srcs = [
        ":library_headers"
    ],
    outs = [
        "classdiagram.puml",
    ],
    cmd = "hpp2plantuml -i \"../**/*.h\" -o $(OUTS)",
)

#genrule(
#    name = "envinfo",
#    outs = ["envinfo.txt"],
#    cmd_bash = """( env; echo "-----"; pwd; ls; echo "-----"; whoami; echo "outs = $@" ) | tee $@""",
#)


cc_library (
    name = "greet",
    srcs = ["greet.cc", "ThreadPool.cc"],
    hdrs = ["greet.h", "Logger.h", "ThreadPool.h"],
    visibility = ["//visibility:public"],
)