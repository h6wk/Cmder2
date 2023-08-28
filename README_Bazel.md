# Bazel



* __.bazelversion__: the bazel version to use
* __WORKSPACE.bazel__: the artifacts that are added to the build process
* __BUILD.bazel__: the build targets

Get the bazel version (downloads from Google Cloud if missing):
```console
$ bazel --version
```

Build everything:
```console
$ bazel build //...
```

