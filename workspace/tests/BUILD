
cc_test(
    name = "AllTests",
    srcs = glob([
        "**/*.cc", "**/*.h"
    ]),
    deps = [
        "//workspace/common:common"
        , "//workspace/tools:tool"
        , "//workspace/agent:agent"
        , "//workspace/server:server"
        , "//workspace/com:com"
        , "@com_google_googletest//:gtest_main"
    ],
)
