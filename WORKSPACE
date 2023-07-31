# targets
# 
# bazel build //...
#
# bazel run //workspace/main:hello
#
# bazel build //workspace/main:hello
# bazel build //workspace/tools:greet
#
# bazel test --test_output=all //workspace/main:hello_test
#


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/5ab508a01f9eb089207ee87fd547d290da39d015.zip"],
  strip_prefix = "googletest-5ab508a01f9eb089207ee87fd547d290da39d015",
)

