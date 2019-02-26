# Purpose
This example demonstrates how to write a Python extension in Rust.

# Prerequisites
You'll need the Rust toolchain to get this up and running, as well as a Python
distribution to build against, in this case the code is written for Python 3.

To get the Rust toolchain go to https://www.rust-lang.org/install.html.

For Python head over to https://www.python.org/downloads or, if you're on Mac,
use Homebrew.

# Building
The Python script `build.py` will run the correct commands for you and create a
symlink for the binary based on the platform. For more details read on.

## Manual Building
You can build the extension using `cargo build --release` for the optimized
version, or just `cargo build` to build the debug version. Once that's done
you need to either copy the binary or make a
[symlink](https://en.wikipedia.org/wiki/Symbolic_link) to it.

The binary will be in `target/release` or `target/debug` if you used
the `--release` flag when building the extension. On Linux or Mac you
should name it `hello.so` and put it in the same directory as `main.py`.
On Windows name it `hello.pyd`.

# Notes
When you import a module (e.g. `import test`) Python will search for a
file with that name and either a `.so` or `.pyd` extension, depending
on the platform. Your library also has to have a function named
`PyInit_test` where `test` is the same name as your module. In our case
it's named `PyInit_hello` and the file is named `hello.so`.

In the Rust-Python binding library we're using here the function
name is specified in the `py_module_initializer!` macro.

