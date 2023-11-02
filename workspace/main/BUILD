
package(default_visibility = ["//visibility:public"])

cc_binary (
    name = "zmq_node",
    srcs = ["main.cc"],
    deps = [
        "//workspace/tools:tool"
        , "//workspace/common:common"
    ]
)

cc_test(
  name = "hello_test",
  size = "small",
  srcs = ["hellotest.cc"],
  deps = ["@com_google_googletest//:gtest_main"],
)