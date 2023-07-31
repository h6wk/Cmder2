
#bazel <run/build> //workspace/main:hello

package(default_visibility = ["//visibility:public"])

cc_binary (
    name = "hello",
    srcs = ["main.cc"],
    deps = [
        "//workspace/tools:greet",
    ]
)

cc_test(
  name = "hello_test",
  size = "small",
  srcs = ["hellotest.cc"],
  deps = ["@com_google_googletest//:gtest_main"],
)