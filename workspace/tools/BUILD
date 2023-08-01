

filegroup (
    name = "library_headers",
    srcs = glob([
        "*.h",
    ]),
)

genrule (
    name = "generate_plantuml",
    srcs = [
        ":library_headers"
    ],
    outs = [
        "out.puml",
    ],
    cmd = "hpp2plantuml -i \"../**/*.h\" -o $(OUTS)",
)


cc_library (
    name = "greet",
    srcs = ["greet.cc", "ThreadPool.cc"],
    hdrs = ["greet.h", "Logger.h", "ThreadPool.h"],
    visibility = ["//visibility:public"],
)