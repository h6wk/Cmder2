# 
# Build the whole project
#   bazel build //...
# Build a target
#   bazel build //workspace/main:hello
#
#
# Run a binary passing arguments to is (-s)
#   bazel run //workspace/main:zmq_node -- -s
#
#
# bazel test --test_output=all //workspace/main:hello_test
# bazel test --test_output=all  --test_arg=--gtest_filter=NodeTest   //workspace/tests:AllTests
#
# Execute all cc_tests
#   bazel query //... | xargs bazel test 
#

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_google_googletest",
    sha256 = "24564e3b712d3eb30ac9a85d92f7d720f60cc0173730ac166f27dda7fed76cb2",
    strip_prefix = "googletest-release-1.12.1",
    urls = ["https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip"],
)

